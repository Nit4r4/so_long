/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:57:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/19 18:04:03 by vferraro         ###   ########.fr       */
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
# define IMG_E "./img_xpm/item_32x32_smallApple.xpm"

# define IMG_X 32
# define IMG_Y 32


typedef struct s_map
{
    char    *lines;
    char    **map2d;
    int     x;
    int     y;
    int     width;
    int     height;
}   t_map;

typedef struct s_img
{
    void    *img;
    int     height;
    int     width;
}   t_img;

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
    void    *mlx;
    void    *window;
    t_map   map;
    t_img   ground;
    t_img   wall;
    t_img   player;
    t_img   item;
    t_img   end;
}   t_game;

void    draw_tile(t_game *game);
void    define_map(t_game *game, int x, int y);
void    draw_map(t_game *game);
void    draw_ground(t_game *game, int x, int y);
void    draw_wall(t_game *game, int x, int y);
void    draw_player(t_game *game, int x, int y);
void    draw_item(t_game *game, int x, int y);
void    draw_end(t_game *game, int x, int y);


#endif