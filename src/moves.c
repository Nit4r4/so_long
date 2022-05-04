/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:28:34 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/04 13:51:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* decompte le nombre d'item sur la map
*/
void	count_item(t_game *game, int x, int y)
{
	if (game->map.map2d[y][x] == 'C')
	{
		game->tiles.item--;
		game->map.map2d[y][x] = '0';
	}
	if (game->map.map2d[y][x] == 'E')
		exit(0);
}

/*
* deplacement du perso en fonction des touches
*/
int	this_is_the_end(int o_key, t_game *game)
{
	if (o_key == KEY_W || o_key == ARROW_UP)
	{
		if (game->map.map2d[game->fox.y_fox - 1][game->fox.x_fox]
		== 'E' && game->tiles.item <= 0)
			return (1);
	}
	else if (o_key == KEY_S || o_key == ARROW_DW)
	{
		if (game->map.map2d[game->fox.y_fox + 1][game->fox.x_fox]
		== 'E' && game->tiles.item <= 0)
			return (1);
	}
	else if (o_key == KEY_A || o_key == ARROW_L)
	{
		if (game->map.map2d[game->fox.y_fox][game->fox.x_fox - 1]
		== 'E' && game->tiles.item <= 0)
			return (1);
	}
	else if (o_key == KEY_D || o_key == ARROW_R)
	{
		if (game->map.map2d[game->fox.y_fox][game->fox.x_fox + 1]
		== 'E' && game->tiles.item <= 0)
			return (1);
	}
	return (0);
}

/*
* fonctions pour ne pas passer/manger les murs
*/
int	deprived_of_exit(t_game *game, int x, int y)
{
	if (game->map.map2d[x][y] == '1')
		return (1);
	if (game->map.map2d[x][y] == 'E' && game->tiles.item > 0)
		return (1);
	return (0);
}

int	wall_king_dead(int o_key, t_game *game)
{
	if (o_key == KEY_W || o_key == ARROW_UP)
	{
		if (deprived_of_exit(game, game->fox.y_fox - 1, game->fox.x_fox))
			return (1);
	}
	else if (o_key == KEY_S || o_key == ARROW_DW)
	{
		if (deprived_of_exit(game, game->fox.y_fox + 1, game->fox.x_fox))
			return (1);
	}
	else if (o_key == KEY_A || o_key == ARROW_L)
	{
		if (deprived_of_exit(game, game->fox.y_fox, game->fox.x_fox - 1))
			return (1);
	}
	else if (o_key == KEY_D || o_key == ARROW_R)
	{
		if (deprived_of_exit(game, game->fox.y_fox, game->fox.x_fox + 1))
			return (1);
	}
	return (0);
}
