/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:48:34 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/01 16:55:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    readmap(int fd)
{
    
}