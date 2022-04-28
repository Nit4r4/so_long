/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:02:58 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/28 14:28:19 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* close the window */
int     bouge_ton_bool()
{
    //if (game)
        exit(0);
}
/* key hook marks orders */
int     in_key_s_hook(t_game *game)
{
    mlx_hook(game->window, 17, 0L << 0, bouge_ton_bool, game);
    mlx_hook(game->window, 2, 1L << 0, keep_in_touch, game);
    return (0);
}
/* define press keys action */
int     keep_in_touch(int o_key, t_game *game)
{
    draw_ground(game, game->fox.x_fox, game->fox.y_fox);
    if (o_key == ESC)
        bouge_ton_bool();
    else if (o_key == KEY_W || o_key == ARROW_UP)
        game->fox.y_fox -= 1;
    else if (o_key == KEY_S || o_key == ARROW_DW)
        game->fox.y_fox += 1;
    else if (o_key == KEY_A || o_key == ARROW_L)
        game->fox.x_fox -= 1;
    else if (o_key == KEY_D || o_key == ARROW_R)
        game->fox.x_fox += 1;
   draw_player(game, game->fox.x_fox, game->fox.y_fox);
    return (0);
}