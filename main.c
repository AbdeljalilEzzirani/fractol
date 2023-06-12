/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:12 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/12 14:37:39 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void mlx_Function(t_data *x)
{	
    x->mlx_ptr = mlx_init();
    x->win_ptr = mlx_new_window(x->mlx_ptr, width, heigth, "the greate window in mlx 1337");
	x->img = mlx_new_image(x->mlx_ptr, width, heigth);
	x->addr = mlx_get_data_addr(x->img, &x->bits_per_pixel, &x->line_length, &x->endian);
}

void mlx_job(t_data *x)
{
	mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
    mlx_loop(x->mlx_ptr);
}

// int main(int ac, char **av)
// {
// 	t_data			x;
// 	int				i;

// 	i = 0;
// 	if (ac == 2 || av[1] == "./Mandelbrot")
// 	{
// 		mlx_Function(&x);
// 		MNDLBRT_function_pixel_put(&x);
// 	}
// 		mlx_job(&x);
	
// }

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t                  i;

        i = 0;
        if (n == 0)
                return (0);
        while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
                i++;
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int ac, char **av)
{
	t_data			x;
	int				i;

	i = 0;
	if (ac == 1)
	{
		mlx_Function(&x);
		if (ft_strncmp(av[0], "./Mandelbrot", 12))
			Julia_function_pixel_put(&x);
		else if (!ft_strncmp(av[1], "./Julia", 12))
			MNDLBRT_function_pixel_put(&x);
		else
			printf ("No mandelbrot |&&| No Julia");
	}
	mlx_job(&x);
}
