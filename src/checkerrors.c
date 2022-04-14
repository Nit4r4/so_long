/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:35:18 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/07 14:19:13 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    linescheck(int fd, int comp1, int comp2)
    {
        char *gnl;
        int i;
        int line;

        gnl = get_next_line(fd);
        i = 0;
        while (i < EOF) 
        {
        comp1 = ft_strlen(gnl);
        comp2 = ft_strlen(gnl);
        if (comp1 != comp2)
            {
                printf("Erreur, le rectangle n'est pas un rectangle !");
                exit(EXIT_FAILURE);
            }
        else 
            line++;
        }        
    }