/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:03:37 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 17:56:35 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Gere les erreurs et exit le game
*/
void    critical_errors(char *str)
{
	ft_printf("%s%s", ERROR, str);
	exit(EXIT_FAILURE);
}

/*
* Verifier qu'il y ait le bon nombre d'argment, ni plus, ni moins
*/
void    check_args(int argc)
{
	if (argc != 2)
		critical_errors(ERR_ARG);
}

/* 
* Gestion des erreurs
*/
void    check_tiles(t_game *game)
{   
	if (game->tiles.item <= 0)
		critical_errors(ERR_ITEM);
	else if (game->tiles.player < 1)
		critical_errors(ERR_PLY);
	else if (game->tiles.player > 1)
		critical_errors(ERR_PLYS);
	else if (game->tiles.ground <= 0)
		critical_errors(ERR_GRD);
	else if (game->tiles.end <= 0)
		critical_errors(ERR_END);
}

/*
* Verfifier que ma map ait des murs
*/
void    check_walls(t_game *game, int x, int y)
{
	if (game->map.map2d[0][x] != '1'|| game->map.map2d[game->map.height - 1][x] != '1')
		critical_errors(ERR_WALL);
	if (game->map.map2d[y][0] != '1'|| game->map.map2d[y][game->map.width - 1] != '1')
		critical_errors(ERR_WALL);
}