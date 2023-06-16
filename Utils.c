/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:35 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/16 01:42:41 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void    ft_putstr(char *s)
{
        int                                     i;

        i = 0;
        while (s[i])
        {
                write (1, &s[i], 1);
                i++;
        }
}

void msg_list_display(void)
{
	// t_data	x;
	ft_putstr("you can use fractol please read this list : \n");
	ft_putstr("if you use Mandelbrot print --> < ./fractol Mandelbrot > \n");
	ft_putstr("if you use Julia print --> < ./fractol Julia > \n");
	// ft_putstr("if you use  print --> < ./fractol  >");
	// mlx_destroy_window(x.mlx_ptr, x.win_ptr);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int flesh_key_hook(int keycode, t_data *param)
{
    double     x = 0.0;
    double     y = 0.0;
    
    if (keycode == 126)
        y = y - 0.2;
    else if (keycode == 125)
        y = y + 0.2;
    else if (keycode == 123)
        x = x - 0.2;
    else if (keycode == 124)
        x = x + 0.2;
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    mandelbrot(x, y, param);
    mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
    return (0);
}




// void	struct_double(t_data *x)
// {
//     x->x_initial;
//     x->y_initial;
//     x->x_final;
//     x->y_final;
// }

    // x->zoom = 1;

// x->x_min = -2.0;
// x->x_max = 2.0;
// x->y_min = -2.0;
// x->y_max = 2.0;