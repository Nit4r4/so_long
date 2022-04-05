/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:50 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/01 14:39:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdio.h>

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
    char    *filename;
    int     width;
    int     height;
    //void    *img;
    t_data  img;

    filename = "img_xpm/vide_HERBE_32x32.xpm";

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 512, 256, "Fox Trot");
    img.img = mlx_new_image(mlx, 512, 256);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
   // my_mlx_pixel_put(&img, 200, 200, 0x0000FF00);
    img.img = mlx_xpm_file_to_image (mlx, filename, &width, &height);
    int x = 0;
    //  while (x * 32 < 900)
        // mlx_put_image_to_window(mlx, mlx_win, img.img, x++ * 32, 0);
    int y = 0;
    // while (y * 32 <= 720)
        mlx_put_image_to_window(mlx, mlx_win, img.img, y++ * 32, 64);
    while(y <= 256)
    {
        while(x <= 512)
        {
            mlx_put_image_to_window(mlx, mlx_win, img.img, x, y); // remplir ligne
            x += 32;
            // mlx_put_image_to_window(mlx, mlx_win, img.img, y++ * 32, 0);
        }
        // mlx_put_image_to_window(mlx, mlx_win, img.img, x, y); // ligne suivante
        y += 32;
        x = 0;
     //  reinitialiser au debut de la ligne
    }
    // while(y * 32 <= 256)
    // {
    //     while(x * 32 <= 512)
    //     {
    //         mlx_put_image_to_window(mlx, mlx_win, img.img, x++ * 32, y * 32); // remplir ligne
    //     }
    //     y++; // ligne suivante
    //     x = 0;  //  reinitialiser au debut de la ligne
    // }
    mlx_loop(mlx);
}