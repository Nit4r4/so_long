/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:49:08 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 18:16:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tiles(t_game *game)
{
	game->tiles.wall = 0;
	game->tiles.item = 0;
	game->tiles.player = 0;
	game->tiles.ground = 0;
	game->tiles.end = 0;
	game->steps = 0;
}

void	count_tiles(t_game *game, char c)
{
	if (c == '1')
	{
		game->tiles.wall++;
	}
	if (c == 'C')
		game->tiles.item++;
	if (c == 'P')
		game->tiles.player++;
	if (c == '0')
		game->tiles.ground++;
	if (c == 'E')
		game->tiles.end++;
}
