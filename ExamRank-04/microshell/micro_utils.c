/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 04:44:33 by orekabe           #+#    #+#             */
/*   Updated: 2022/11/06 04:44:34 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void    ft_putstr(char  *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void    err_fatal(void)
{
    ft_putstr("error: fatal\n");
    exit(1);
}