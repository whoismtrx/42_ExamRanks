/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 04:44:41 by orekabe           #+#    #+#             */
/*   Updated: 2022/11/06 04:44:42 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

tree    *tree_new(char *arg)
{
    tree    *new;
    new = (tree *)malloc(sizeof(tree));
    if (!new)
        err_fatal();
    if (!strcmp(arg, ";"))
        new->token = 1;
    else if (!strcmp(arg, "|"))
        new->token = 2;
    else
        new->token = 3;
    new->args = NULL;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

tree    *parse_cmd(char **argv, int i)
{
    tree    *node = tree_new(argv[i]);
    int     j = i;
    while (argv[j] && strcmp(argv[j], ";") && strcmp(argv[j], "|"))
        j++;
    node->args = (char **)malloc(sizeof(char *) * (j - i + 1));
    if (!node->args)
        err_fatal();
    j = 0;
    while (argv[i + j] && strcmp(argv[i + j], ";") && strcmp(argv[i + j], "|"))
    {
        node->args[j] = argv[i + j];
        j++;
    }
    node->args[j] = NULL;
    return (node);
}

tree    *parse_pipe(char **argv, int i)
{
    tree    *node = NULL;
    int     j = i;
    while (argv[i] && strcmp(argv[i], ";"))
    {
        if (!strcmp(argv[i], "|"))
        {
            node = tree_new(argv[i]);
            node->left = parse_cmd(argv, j);
            node->right = parse_pipe(argv, i + 1);
            return (node);
        }
        i++;
    }
    node = parse_cmd(argv, j);
    return (node);
}

tree    *parse_tree(char **argv, int i)
{
    tree    *root = NULL;
    int     j = i;
    while (argv[i])
    {
        if (!strcmp(argv[i], ";"))
        {
            root = tree_new(argv[i]);
            root->left = parse_pipe(argv, j);
            root->right = parse_tree(argv, i + 1);
            return (root);
        }
        i++;
    }
    root = parse_pipe(argv, j);
    return (root);
}