/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:12 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/18 20:36:56 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void mlx_Function(t_data *x)
{	
    x->mlx_ptr = mlx_init();
    x->win_ptr = mlx_new_window(x->mlx_ptr, width, heigth, "fractol");
	x->img = mlx_new_image(x->mlx_ptr, width, heigth);
	x->addr = mlx_get_data_addr(x->img, &x->bits_per_pixel, &x->line_length, &x->endian);
}

void mlx_job(t_data *x)
{
	if(x->set == 1)
		mlx_hook(x->win_ptr, 6, 0, &julia_move, x);
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
	mlx_key_hook(x->win_ptr, flesh_key_hook, x);
	mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
	mlx_mouse_hook(x->win_ptr, f_zoom, x);// for zoom
	mlx_hook(x->win_ptr, 17, 0, ft_exit, x);
	mlx_loop(x->mlx_ptr);
}

void check_fractal(char *scmp, t_data *x)
{
	if (!ft_strcmp(scmp, "Mandelbrot"))
	{
		x->set = 0;
		MNDLBRT_function_pixel_put(x);
	}
	else if (!ft_strcmp(scmp, "Julia"))
	{
		x->set = 1;
		Julia_function_pixel_put(x);
	}
	// else if (!ft_strcmp(scmp, "Burning_Ship"))
	// {
	// 	x.set = 2;
	// 	Burning_Ship_function_pixel_put(&x);
	// }
	else
	{
		msg_list_display();
	}
}

int main(int ac, char **av)
{
	t_data			x;
	
	mlx_Function(&x);
	if (ac == 2)
	{
		x.zoom_width = (4.0 / width);
		x.zoom_height = (4.0 / heigth);
		x.var_wid = 2;
		x.var_hei = 2;
		check_fractal(av[1], &x);
		mlx_job(&x);
	}
    else
	{
		msg_list_display();
		return (2);
	}
	return (2);
}
