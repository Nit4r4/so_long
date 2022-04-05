/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:48:34 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/05 16:12:36 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkname(char *str)
{
    char *ext;

    if (!str)
        return (0);
    ext = strstr(str, ".ber");
    if (ext && strlen(ext) == 4)
    {
        return (1);
    }
    return (0);
}

// void    readfile(char **tab);
// {
//     int fd;
//     int x;
//     int y;
//     char test;
//     char *retur;
//     int longueur;

//     longueur = 0;
//     fd = open(file, O_RDONLY);
//     if (!fd)
//         return (-1);
//     while (test != '\n')
//     {
//         test = read (de 1);
//         longueur++;
//     }

//     salut\n

//     tab[0] = ft_strlen(gnl(fd, 0, tab))

// }









// void    readtab(int x, int y, char **tab)
// {
//     int     fd;
//     int     i;
//     char    *file;

//     i = 0;
//     fd = open(file, O_RDONLY);
//     if (!fd)
//         return (-1);
    
// }

// }
// void    readmap(int fd)
// {
//     char    c;
//     int     i;

//     if (!fd)
//         return (-1);
//     i = 0;
//     while (1)
//     {
//         if (c == '1')
//             print(wall);
//         i++;
//         else if (c == '0')
//             print(ground);
//         i++;
//         else if (c == 'C')
//             print(item);
//         i++;
//         else if (c == 'E')
//             print(end);
//         i++;
//         else if (c == 'P')
//             print(player);
//         i++;
//     }
// }