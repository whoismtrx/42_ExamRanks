/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:45 by orekabe           #+#    #+#             */
/*   Updated: 2023/10/29 20:57:46 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char*   ARG = "Wrong number of arguments\n";
char*   FATAL = "Fatal error\n";
char    ANONCMENT[200000], MSG[200000], BUFF[200000];
int     sockfd, nclifd, nfds, id, ids[1024], ret;
struct  sockaddr_in servaddr, cli;
fd_set  fds, rfds;
socklen_t clilen;

void    err(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}

void    announcement(char *str, int cli)
{
    for(int fd = 0; fd < nfds; fd++)
        if (fd != cli && FD_ISSET(fd, &fds))
            send(fd, str, strlen(str), 0);
}

void    join_client(int fd)
{
    nfds = (fd >= nfds) ? fd+1 : nfds;
    ids[fd] = id++;
    bzero(ANONCMENT, sizeof(ANONCMENT));
    sprintf(ANONCMENT, "server: client %d just arrived\n", ids[fd]);
    announcement(ANONCMENT, fd);
    FD_SET(fd, &fds);
}

void    left_client(int fd)
{
    FD_CLR(fd, &fds);
    bzero(ANONCMENT, sizeof(ANONCMENT));
    sprintf(ANONCMENT, "server: client %d just left\n", ids[fd]);
    announcement(ANONCMENT, fd);
    close(fd);
}

void    share_msg(int fd)
{
    bzero(ANONCMENT, sizeof(ANONCMENT));
    bzero(BUFF, sizeof(BUFF));
    for(int i=0, j=0; MSG[i]; i++, j++)
    {
        BUFF[j] = MSG[i];
        if (MSG[i] == '\n')
        {
            sprintf(ANONCMENT, "client %d: %s", ids[fd], BUFF);
            announcement(ANONCMENT, fd);
            j = -1;
            bzero(ANONCMENT, sizeof(ANONCMENT));
            bzero(BUFF, sizeof(BUFF));
        }
    }
    bzero(MSG, sizeof(MSG));
}

void    mini_serv()
{  
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    nfds = sockfd+1;
    while(1)
    {
        rfds = fds;
        if (select(nfds, &rfds, NULL, NULL, NULL) == -1)
            err(FATAL);
        for(int fd = 0; fd < nfds; fd++)
        {
            if (!FD_ISSET(fd, &rfds))
                continue;
            if (fd == sockfd)
            {
                clilen = sizeof(cli);
                nclifd = accept(sockfd, (struct sockaddr *)&cli, &clilen);
                if (nclifd > 0)
                {
                    join_client(nclifd);
                    break;
                }
            }
            else
            {
                if (recv(fd, MSG, 199999, 0) <= 0)
                {
                    left_client(fd);
                    break;
                }
                else
                    share_msg(fd);
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        err(ARG);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        err(FATAL);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        err(FATAL);
    if (listen(sockfd, 10) == -1)
        err(FATAL);
    mini_serv();
}