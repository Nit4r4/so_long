/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:35 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/27 17:21:10 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * verifier que mon fichier a lire est un .ber et rien d'autre 
 */
void checkname(char *str)
{
    char *ext;

    if (!str)
        return ;
    ext = ft_strstr(str, ".ber");
    if (ext && ft_strlen(ext) == 4)
    {
        return ;
    }
    critical_errors(ERR_FILE);
}

void    check_map(t_game *game)
{
    int i;
    int j;

    j = 0;
    init_tiles(game);
    //printf("Map W : %c\n", game->map.map2d[0][0]);
    //printf("%d\n", j)
    while (j < game->map.height)
    {
        i = 0;
        //while (game->map.map2d[j][i] != '\0')
        while (i < game->map.width)
        {   //printf("avant : %d\n %d\n", i, j);
            count_tiles(game, game->map.map2d[j][i]);
           //check_walls(game);
           //check_walls(game, game->map.x, game->map.y);
            i++;
        }
        j++;
        //printf("apres : %d\n %d\n", i, j);

    }
}