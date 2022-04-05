/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:57:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/05 15:57:17 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

// # include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>

// verifier si j ai besoin d incerer la libft ou gnl suivant la maniere dont je range mes fichiers dans mes dossiers

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

char	*get_next_line(int fd);

#endif