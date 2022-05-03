/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:35 by vferraro          #+#    #+#             */
/*   Updated: 2022/05/03 18:01:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * verifier que mon fichier a lire est un .ber et rien d'autre 
 */
void checkname(char *str)
{
	char	*ext;
	int		len;

	len = ft_strlen(str);
	if (!str)
		return ;
	ext = ft_strnstr(str, ".ber", len);
	if (ext && ft_strlen(ext) == 4)
	{
		return ;
	}
	critical_errors(ERR_FILE);
}

/*
* Verifier que les lignes sont completes
* Calculer la longeur des ligneset enlever les retour a la ligne
*/
void    linescheck(int fd, t_game *game)
{
	char    *gnl;
	char    *dobby;
	
	dobby = get_next_line(fd);
	gnl = ft_strtrim(dobby, "\n");
	free(dobby);
	game->map.lines = ft_strdup("");
	game->map.width = 0;
	game->map.height = 0;
	while (gnl != NULL) 
	{
		if (game->map.width != (int)ft_strlen(gnl) && game->map.width)
			critical_errors(ERR_LINES);
		dobby = game->map.lines;
		game->map.lines = ft_strjoin(game->map.lines, gnl);
		free(dobby);
		game->map.width = (int)ft_strlen(gnl);
		dobby = get_next_line(fd);
		free(gnl);
		gnl = ft_strtrim(dobby, "\n");
		free(dobby);
		game->map.height++;
	}      
}

/* 
* Fonction pour transformer les lignes en tableau 
* char table[x][y] --> tableau de char de x lignes et y colonnes 
*/
void    str_to_board(t_game *game)
{
	int x;
	int y;
	int i;
	char **board;

	i = 0;
	board = malloc(game->map.height * sizeof(char *));
	if (!board)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		board[y] = ft_calloc((game->map.width) + 1, sizeof(char));
		if (!board[y])
			return ;
		while (x < game->map.width)
		{
			board[y][x] = game->map.lines[i];
			x++;
			i++;
		}
		y++;
	}
	game->map.map2d = board;
}

void    check_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	init_tiles(game);
	while (y != game->map.height)
	{
		x = 0;
		while (x != game->map.width)
		{
			count_tiles(game, game->map.map2d[y][x]);
			check_walls(game, x, y);
			x++;
		}
		y++;
	}
}