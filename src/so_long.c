/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:50 by vferraro          #+#    #+#             */
/*   Updated: 2022/03/01 14:13:54 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

typedef struct  s_data 
{
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr+ (y * data->line_lenght + x * (data->bits_per_pixel/ 8));
    *(unsigned int*)dst= color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    //void    *img;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 400, 400, "N1t4r4");
    img.img = mlx_new_image(mlx, 400, 400);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
    my_mlx_pixel_put(&img, 200, 200, 0x0000FF00);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}