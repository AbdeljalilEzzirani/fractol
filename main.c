/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:12 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/07 03:22:39 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void mlx_func(int i, int j)
// {
// 	t_data			x;
	
// 	x.mlx_ptr = mlx_init();
//     x.win_ptr = mlx_new_window(x.mlx_ptr, i, j, "the greate window in mlx 1337");
// 	x.img = mlx_new_image(x.mlx_ptr, i, j);
// 	x.addr = mlx_get_data_addr(x.img, &x.bits_per_pixel,&x.line_length, &x.endian);
// }

int main()
{
	t_data x;
	double i = 0.0;
	double j;
	
    x.mlx_ptr = mlx_init();
    x.win_ptr = mlx_new_window(x.mlx_ptr, 800, 800, "the greate window in mlx 1337");
	x.img = mlx_new_image(x.mlx_ptr, 800, 800);
	x.addr = mlx_get_data_addr(x.img, &x.bits_per_pixel,&x.line_length, &x.endian);
	while (i < 800){
        j = 0.0;
		while (j < 800) 
		{
			if(mandelbrot(i, j) == ITR)
				my_mlx_pixel_put(&x,i,j, 0xFF00FF);
			else
				my_mlx_pixel_put(&x,i,j, 0x008000);
			j++;
		}
        i++;
	}
	mlx_put_image_to_window(x.mlx_ptr,x.win_ptr,x.img, 0, 0);
    mlx_loop(x.mlx_ptr);
}





//cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
