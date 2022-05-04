/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fox_to_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:40:21 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/04 15:41:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_playerleft(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, \
		game->playerleft.img, x * IMG_X, y * IMG_Y);
}

void	move_left_fox(t_game *game)
{
	game->fox.x_fox -= 1;
	draw_playerleft(game, game->fox.x_fox, game->fox.y_fox);
	print_steps(game);
}
