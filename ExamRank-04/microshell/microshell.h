/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 04:44:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/11/06 04:44:25 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **g_env;

typedef struct s_tree
{
    int     token;
    char    **args;
    struct  s_tree *left;
    struct  s_tree *right;
}               tree;

void    ft_putstr(char *str);
void    err_fatal(void);

tree    *tree_new(char *arg);
tree    *parse_tree(char **argv, int i);
tree    *parse_pipe(char **argv, int i);
tree    *parse_cmd(char **argv, int i);

void    exec_tree(tree *root);
void    pipee(tree *node);
void    cd(tree *node);
void    exec_cmd(tree *node);

#endif