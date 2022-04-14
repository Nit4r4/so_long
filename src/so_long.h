/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:57:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/14 16:03:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>

# define IMG_G "./img_xpm/vide_HERBE_32x32.xpm"
# define IMG_W "./img_xpm/mur_arbre_32x32C2.xpm"
# define IMG_P "./img_xpm/fox.xpm"
# define IMG_I "./img_xpm/item_32x32_smallApple.xpm"

typedef struct s_map
{
    char    *lines;
    char    **map2d;
    int     x;
    int     y;
    int     width;
    int     height;
}   t_map;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_item
{
    char    *tree;
    int     width;
    int     height;
}   t_item;

typedef struct s_start
{
    int     player;
    int     item;
    int     end;
}   t_start;

typedef struct s_end
{
    int x;
    int y;
}   t_end;

typedef struct s_game
{
    t_map   map;
}   t_game;




#endif