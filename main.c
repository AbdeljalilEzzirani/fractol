/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:12 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/13 15:32:48 by abez-zir         ###   ########.fr       */
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
	if(x->digit == 1)
		mlx_hook(x->win_ptr, 6, 0, &julia_move, x);
	// mlx_clear_window(x->mlx_ptr, x->win_ptr);
	mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
    mlx_loop(x->mlx_ptr);
}

int ft_strcmp(char *s1, char *s2)
{
        int                     i;

        i = 0;
        while (s1[i] && s2[i] && s1[i] == s2[i])
        {
                i++;
        }
        return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
	t_data			x;

	mlx_Function(&x);
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
		{
			x.digit = 0;
			MNDLBRT_function_pixel_put(&x);
			// return (0);
		}
		else if (!ft_strcmp(av[1], "Julia"))
		{
			x.digit = 1;
			Julia_function_pixel_put(&x);
		}
		else
		{
			printf ("⛔️ No mandelbrot |&&| No Julia ⛔️ \n");
			return (0);
		}
		mlx_job(&x);
	}
    else
		printf ("🚨 Please enter Just two arguments 🚨 \n");
}
