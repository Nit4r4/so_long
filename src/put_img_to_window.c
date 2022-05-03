/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:40:47 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 17:57:14 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->ground.img, x * IMG_X, y * IMG_Y);
}

void    draw_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->wall.img, x * IMG_X, y * IMG_Y);
}

void    draw_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player.img, x * IMG_X, y * IMG_Y);
}

void    draw_item(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->item.img, x * IMG_X, y * IMG_Y);
}

void    draw_end(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->end.img, x * IMG_X, y * IMG_Y);
}