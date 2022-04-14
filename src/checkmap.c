/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:35 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/14 13:31:28 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * verifier que mon fichier a lire est un .ber et rien d'autre 
 */
int checkname(char *str)
{
    char *ext;

    if (!str)
        return (0);
    ext = strstr(str, ".ber");
    if (ext && strlen(ext) == 4)
    {
        return (1);
    }
    return (0);

    