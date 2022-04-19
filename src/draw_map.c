/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:45:42 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/19 16:17:41 by vferraro         ###   ########.fr       */
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

void      draw_map(t_game *game, int x, int y)
{
     
}