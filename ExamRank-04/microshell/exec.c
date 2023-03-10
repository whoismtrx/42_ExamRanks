/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 04:44:37 by orekabe           #+#    #+#             */
/*   Updated: 2023/01/09 23:29:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void    cd(tree *node)
{
    if (!node->args[1] || node->args[2])
        ft_putstr("error: cd: bad arguments\n");
    else
    {
        if (chdir(node->args[1]) == -1)
        {
            ft_putstr("error: cd: cannot change directory to ");
            ft_putstr(node->args[1]);
            ft_putstr("\n");
        }
    }
    return ;
}

void    exec_cmd(tree *node)
{
    int pid;
    pid = fork();
    if (pid == -1)
        err_fatal();
    if (pid == 0)
    {
        if (execve(node->args[0], node->args, g_env) == -1)
        {
            ft_putstr("error: cannot execute ");
            ft_putstr(node->args[0]);
            ft_putstr("\n");
            exit(1);
        }
    }
    else
        waitpid(-1, 0, 0);
    return ;
}

void    pipee(tree *node)
{
    int fds[2];
    int pid;
    int d;
    int c;

    if (pipe(fds) == -1)
        err_fatal();
    pid = fork();
    if (pid == -1)
        err_fatal();
    if (pid == 0)
    {
        d = dup2(fds[1], 1);
        if (d == -1)
            err_fatal();
        c = close(fds[1]);
        if (c == -1)
            err_fatal();
        c = close(fds[0]);
        if (c == -1)
            err_fatal();
        exec_tree(node->left);
        exit(0);
    }
    pid = fork();
    if (pid == -1)
        err_fatal();
    if (pid == 0)
    {
        d = dup2(fds[0], 0);
        if (d == -1)
            err_fatal();
        c = close(fds[0]);
        if (c == -1)
            err_fatal();
        c = close(fds[1]);
        if (c == -1)
            err_fatal();
        exec_tree(node->right);
        exit(0);
    }
    c = close(fds[0]);
    if (c == -1)
        err_fatal();
    c = close(fds[1]);
    if (c == -1)
        err_fatal();
    waitpid(-1, 0, 0);
    waitpid(-1, 0, 0);
    return ;
}

void    exec_tree(tree *root)
{
    if (root)
    {
        if (root->token == 1)
        {
            exec_tree(root->left);
            exec_tree(root->right);
        }
        else if (root->token == 2)
            pipee(root);
        else if (root->token == 3 && !strcmp(root->args[0], "cd"))
            cd(root);
        else if (root->token == 3)
            exec_cmd(root);
    }
    return ;
}