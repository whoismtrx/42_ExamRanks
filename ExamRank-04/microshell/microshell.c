/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 04:44:29 by orekabe           #+#    #+#             */
/*   Updated: 2022/11/06 04:44:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int main(int argc, char **argv, char **env)
{
    tree *root = NULL;
    g_env = env;
    if (argc > 1)
    {
        root = parse_tree(argv, 1);
        exec_tree(root);
    }
    exit(0);
}
