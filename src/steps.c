/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:35:28 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 11:36:02 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     one_step_two_steps(int o_key, t_game *game)
{
    if (keep_in_touch(o_key, &game) == 1)
        game->steps++;
        {
            if (game->tiles.wall)
            return (0);
        }
}

void    count_steps(t_game *game)
{
    while (game->steps)
    {
        game->steps++;
        if (game->tiles == '1')
            game->steps;
        if (game-> == '1')
            game->steps;
    }
    game->steps++;
}