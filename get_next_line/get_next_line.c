/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:25:42 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/18 03:25:43 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (fd < 0)
		return (NULL);
	char *ret = malloc(99999);
	if(!ret)
		return (NULL);
	int r, rd = 0;
	r = read(fd, ret + rd, 1);
	rd += r;
	while (r != 0 && ret[rd - 1] != '\n')
	{
		r = read(fd, ret + rd, 1);
		rd += r;
		if (r == -1)
		{
			free(ret);
			return NULL;
		}
	}
	ret[rd] = '\0';
	if (!ret || !*ret)
	{
		free(ret);
		return NULL;
	}
	return (ret);
}
