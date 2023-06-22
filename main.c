/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:12 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/20 19:15:44 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_function(t_data *x)
{
	x->mlx_ptr = mlx_init();
	x->win_ptr = mlx_new_window(x->mlx_ptr, WIDTH, HEIGTH, "fractol");
	x->img = mlx_new_image(x->mlx_ptr, WIDTH, HEIGTH);
	x->addr = mlx_get_data_addr(x->img, &x->bits_per_pixel,
			&x->line_length, &x->endian);
}

void	mlx_job(t_data *x)
{
	if (x->set == 1)
		mlx_hook(x->win_ptr, 6, 0, &julia_move, x);
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
	mlx_key_hook(x->win_ptr, flesh_key_hook, x);
	mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, x->img, 0, 0);
	mlx_mouse_hook(x->win_ptr, f_zoom, x);
	mlx_hook(x->win_ptr, 17, 0, ft_exit, x);
	mlx_loop(x->mlx_ptr);
}

void	check_fractal(char *scmp, t_data *x)
{
	if (!ft_strcmp(scmp, "Mandelbrot"))
	{
		x->set = 0;
		mndlbrt_function_pixel_put(x);
	}
	else if (!ft_strcmp(scmp, "Julia"))
	{
		x->set = 1;
		julia_function_pixel_put(x);
	}
	else if (!ft_strcmp(scmp, "Burning_Ship"))
	{
		x->set = 2;
		burning_ship_function_pixel_put(x);
	}
	else
	{
		msg_list_display();
	}
}

int	main(int ac, char **av)
{
	t_data			x;

	mlx_function(&x);
	if (ac == 2)
	{
		x.zoom_wid = (4.0 / WIDTH);
		x.zoom_hei = (4.0 / HEIGTH);
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
	return (0);
}
