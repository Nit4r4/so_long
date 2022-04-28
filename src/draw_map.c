/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:45:42 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/28 13:27:34 by vferraro         ###   ########.fr       */
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
/*
* dessine map
*/
void      define_map(t_game *game, int x, int y)
{
     draw_ground(game, x, y);
     if (game->map.map2d[y][x] == '1')
          draw_wall(game, x, y);
     else if (game->map.map2d[y][x] == 'P')
     {
          draw_player(game, x, y);
          game->fox.x_fox = x;
          game->fox.y_fox = y;
     }
     else if (game->map.map2d[y][x] == 'C')
          draw_item(game, x, y);
     else if (game->map.map2d[y][x] == 'E')
          draw_end(game, x, y);
}

// avec les counter
// void      define_map(t_game *game, int x, int y)
// {
//      draw_ground(game, x, y);
//      if (game->map.map2d[y][x] == '1')
//           {
//                draw_wall(game, x, y);
//                game->tiles->wall++;
//           }
//      else if (game->map.map2d[y][x] == 'P')
//           {
//                draw_player(game, x, y);
//                game->tiles->player++;
//           }
//      else if (game->map.map2d[y][x] == 'C')
//           {
//                draw_item(game, x, y);
//                game->tiles->item++;
//           }
//      else if (game->map.map2d[y][x] == 'E')
//           {
//                draw_end(game, x, y);
//                game->tiles->end++;
//           }
// }


void      draw_map(t_game *game)
{
    int x;
    int y;
    y = 0;
  //  int i = 0;
     //ft_printf("map2d\n");
    while (y < game->map.height)
    {
          x = 0;
          while (x < game->map.width)
          {
               ft_printf("%c", game->map.map2d[y][x]);
               define_map(game, x, y);
               x++;
          }
          ft_printf("\n");
          y++;
    }
   // printf("lines2\n%c\n", game->map.lines[21]); //pourquoi 21 
}