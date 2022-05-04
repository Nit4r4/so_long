/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:02:58 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/04 17:16:14 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* close the window */
int	bouge_ton_bool(void)
{
	exit(0);
}

/* key hook marks orders */
int	in_key_s_hook(t_game *game)
{
	mlx_hook(game->window, 17, 0L << 0, bouge_ton_bool, game);
	mlx_hook(game->window, 2, 1L << 0, keep_in_touch, game);
	return (0);
}

/* define press keys action */
int	check_left_move(int o_key, t_game *game)
{
	if (!wall_king_dead(o_key, game))
	{
		draw_ground(game, game->fox.x_fox, game->fox.y_fox);
		if (o_key == KEY_A || o_key == ARROW_L)
			move_left_fox(game);
		return (1);
	}
	return (0);
}

int	keep_in_touch(int o_key, t_game *game)
{
	if (check_left_move(o_key, game) == 1)
	{
		if (o_key == ESC)
			bouge_ton_bool();
		if (o_key == KEY_A || o_key == ARROW_L)
			return (0);
		else if (o_key == KEY_W || o_key == ARROW_UP)
			game->fox.y_fox -= 1;
		else if (o_key == KEY_S || o_key == ARROW_DW)
			game->fox.y_fox += 1;
		else if (o_key == KEY_D || o_key == ARROW_R)
			game->fox.x_fox += 1;
		else if (o_key != KEY_A || o_key != KEY_S \
				|| o_key != KEY_W || o_key != KEY_D)
		{
			ft_printf(ERR_KEY);
			return (0);
		}
		draw_player(game, game->fox.x_fox, game->fox.y_fox);
		print_steps(game);
	}
	return (0);
}

void	print_steps(t_game *game)
{
	count_item(game, game->fox.x_fox, game->fox.y_fox);
	game->steps++;
	ft_printf("%d pas\n", game->steps);
}
