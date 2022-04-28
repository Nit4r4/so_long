/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:03:37 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/27 17:19:18 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Gere les erreurs et exit le game
*/
void    critical_errors(char *str)
{
    // ft_printf(ERROR);
    ft_printf("%s %s", ERROR, str);
    exit(EXIT_FAILURE);
}

/*
* Verifier qu'il y ait le bon nombre d'argment, ni plus, ni moins
*/
void    check_args(int argc)
{
    if (argc != 2)
        critical_errors(ERR_ARG);
}

void    check_tiles(t_game *game)
{   
    //(void)*game;
   // critical_errors(ERR_GRD);
    // int i;

    // i = 0;
    // while (i < game->map.map2d)
    {
            printf("Coins : %d\n", game->tiles.item);
            printf("Wall : %d\n", game->tiles.wall);
            printf("Player : %d\n", game->tiles.player);
            printf("Ground : %d\n", game->tiles.ground);
            printf("End : %d\n", game->tiles.end);
        if (game->tiles.item <= 0)
            critical_errors(ERR_ITEM);
        else if (game->tiles.player < 1)
            critical_errors(ERR_PLY);
        else if (game->tiles.player > 1)
            critical_errors(ERR_PLYS);
        else if (game->tiles.ground <= 0)
            critical_errors(ERR_GRD);
        else if (game->tiles.end <= 0)
            critical_errors(ERR_END);
    }
}

/*
* Verfifier que ma map ait des murs
*/
void    check_walls(t_game *game, int x, int y)
{
    if (game->map.map2d[y][x] != '1')
        critical_errors(ERR_WALL);
}
          
// void    check_walls(t_game *game)
// {
//     //int w_count;
//     int i;
//     i = 0;
//     printf("le nombre de wall trouve : %d\n", i);
//     if (game->map.map2d[i] != game->tiles.wall)
//         critical_errors(ERR_WALL);
//     // w_count = (game->map.height - 1) + (game->map.map2d -1) * 2;
//     // if (!w_count)
//     i = 0;
//     if (game->map.map2d[0][i++] == '1')
//     {
//         i++;
//     }
//     critical_errors(ERR_WALL);
//     i = 0;
//     if (game->map.map2d[i++][0] == '1')
//     {
//         i++;
//     }
//     critical_errors(ERR_WALL);
//     printf("le nombre de wall trouve APRES : %d\n", i);
// }

// void    check_walls(t_game *game)
// {
//     int i;
//     int w_count;
//     int result;
    
//     i = 0;
//     while (i < game->map.height)
//         {
//             printf("Line : %s\n", game->map.map2d[i]);
//             i++;        
//         }
//     i = -1;
//     result = 0;
//     w_count = ((game->map.width - 1 + game->map.height - 1) * 2);
//     if (!game->tiles.wall)
//         critical_errors(ERR_WALL);
//     while (game->map.map2d[0][++i] == '1')
//         result++;
//     printf("result_1 : %d\n", result);
//     i = -1;
//     while (game->map.map2d[game->map.height - 1][++i] == '1')
//         result++;
//     printf("result_2 : %d\n", result);
//     i = -1;
//     while (game->map.map2d[++i][0] == '1' && i < game->map.height - 1)
//         result++;
//     printf("result_3 : %d\n", result);  
//     i = -1;
//     while (game->map.map2d[++i][game->map.width - 2] == '1' && i < game->map.height - 1)
//         result++;
//     printf("result_4 : %d\n", result);  
//     printf("Compare result : %d\n", result);
//     printf("Compare w_count (ok) : %d\n", w_count);
//     if (w_count != result)
//         critical_errors(ERR_WALL);
// }