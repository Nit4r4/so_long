/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:45:42 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/19 18:10:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_tile(t_game *game)
{
     game->ground.img = mlx_xpm_file_to_image (game->mlx, IMG_G, 
                         &game->ground.width, &game->ground.height);
     game->wall.img = mlx_xpm_file_to_image (game->mlx, IMG_W, 
                         &game->wall.width, &game->wall.height);
     game->player.img = mlx_xpm_file_to_image (game->mlx, IMG_P, 
                         &game->player.width, &game->player.height);
     game->item.img = mlx_xpm_file_to_image (game->mlx, IMG_I, 
                         &game->item.width, &game->item.height);
     game->end.img = mlx_xpm_file_to_image (game->mlx, IMG_E, 
                         &game->end.width, &game->end.height);
}

void      define_map(t_game *game, int x, int y)
{
     if (game->map.map2d[x][y] == '1')
          draw_wall(game, x, y);
     if (game->map.map2d[x][y] == '0')
          draw_ground(game, x, y);
     if (game->map.map2d[x][y] == 'P')
          draw_player(game, x, y);
     if (game->map.map2d[x][y] == 'C')
          draw_item(game, x, y);
     if (game->map.map2d[x][y] == 'E')
          draw_end(game, x, y);
}

void      draw_map(t_game *game)
{
    int x;
    int y;
    y = 0;
    int i = 0;
    printf("map\n");
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            printf("%c", game->map.lines[i++]);
            x++;
        }
        printf("\n");
        y++;
    }
    printf("lines2\n%c\n", game->map.lines[21]);
}