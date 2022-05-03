/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:31:10 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 18:12:27 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game.mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	linescheck(fd, &game);
	close(fd);
	check_args(argc);
	checkname(argv[1]);
	str_to_board(&game);
	check_map(&game);
	check_tiles(&game);
	game.window = mlx_new_window(game.mlx, game.map.width * IMG_X, \
		game.map.height * IMG_Y, "so_long");
	draw_tile(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx, in_key_s_hook, &game);
	mlx_loop(game.mlx);
}
