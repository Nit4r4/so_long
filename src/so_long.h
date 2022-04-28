/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:57:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/28 17:51:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <stdarg.h>
#include <stdbool.h>

# define IMG_G "./img_xpm/vide_HERBE_32x32.xpm"
# define IMG_W "./img_xpm/mur_arbre_32x32C2.xpm"
# define IMG_P "./img_xpm/fox.xpm"
# define IMG_I "./img_xpm/item_32x32_smallApple.xpm"
# define IMG_E "./img_xpm/end32x32_flip.xpm"

# define IMG_X 32
# define IMG_Y 32

# define ESC 53
# define RED_CROSS 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ARROW_L 123
# define ARROW_R 124
# define ARROW_DW 125
# define ARROW_UP 126

# define ERROR "Il semblerait qu'il y ait un problème :"
# define ERR_LINES "Le rectangle n'est pas un rectangle !\n"
# define ERR_ARG "Vérifies que tu aies le bon nombre d'arguments\n"
# define ERR_FILE "Oups, il y a un soucis avec ton fichier\n"
//# define ERR_MAP "La carte n'est apparemment pas au bon format\n" 
# define ERR_ITEM "Je ne suis pas matérialiste, mais si il n'y a rien à récupérer je reste dans mon terrier\n" 
# define ERR_PLY "Être ou ne pas être... telle est la question ici, il te faut un perso pour jouer, tu ne crois pas ?\n"
# define ERR_PLYS "Il y a beaucoup trop de monde ici...\n"
# define ERR_GRD "Tu sais voler ? Moi non plus, ajoute un sol !\n" 
# define ERR_WALL "On a besoin de limite et de cadre dans la vie pour pouvoir progresser en toute sécurité...\n" 
# define ERR_END "On ne peut pas ne pas sortir tu comprends ?\n" 
# define ERR_M "Problème de...de...comment on dit déjà ? DE MÉMOIRE !\n" 
# define ERR_ERR "Une inception d'erreur... mais est-on dans la vraie vie ? Sors ta toupie et fais un test de réalité... non je déconne, corrige ta faute et recommence !\n" 

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

typedef struct s_tiles
{
    int item;
    int player;
    int wall;
    int ground;
    int end;
}   t_tiles;

typedef struct s_player
{
    void **fox;
    int x_fox;
    int y_fox;
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
    int     moves;
    t_map   map;
    t_img   ground;
    t_img   wall;
    t_img   player;
    t_img   item;
    t_img   end;
    t_tiles tiles;
    t_img   *img;
    t_player    fox;
}   t_game;

void     checkname(char *str);
// char	**map_height(t_game *game, int fd);
void    linescheck(int fd, t_game *game);
void    str_to_board(t_game *game); //probleme ici
void    draw_tile(t_game *game);
void    define_map(t_game *game, int x, int y); // probleme ici
void    draw_map(t_game *game);
void    draw_ground(t_game *game, int x, int y);
void    draw_wall(t_game *game, int x, int y);
void    draw_player(t_game *game, int x, int y);
void    draw_item(t_game *game, int x, int y);
void    draw_end(t_game *game, int x, int y);
void    critical_errors(char *str);
void    check_args(int argc);
//void    check_tiles(t_game *game, int x, int y);
void    check_tiles(t_game *game);
//void    check_walls(t_game *game);
void    check_walls(t_game *game, int i, int j);
void    check_map(t_game *game);
void    init_tiles(t_game *game);
void    count_tiles(t_game *game, char c);
void    init_memory(t_game *game);
void    count_item(t_game *game, int x, int y);

/* utils */
char *ft_strstr(const char *str, const char *word);

/* moves */
//int     bouge_ton_bool(t_game *game);
int     bouge_ton_bool();
int     in_key_s_hook(t_game *game);
int     keep_in_touch(int o_key, t_game *game);
int     wall_king_dead(int o_key, t_game *game);
int     deprived_of_exit(t_game *game, int x, int y);
int     this_is_the_end(int o_key, t_game *game);

#endif