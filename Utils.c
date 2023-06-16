/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:35 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/16 23:26:47 by abez-zir         ###   ########.fr       */
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
	ft_putstr("if you can use fractol please read this list : \n");
	ft_putstr("if you use Mandelbrot print --> < ./fractol Mandelbrot > \n");
	ft_putstr("if you use Julia print --> < ./fractol Julia > \n");
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
    if(keycode == 53)
    {
        mlx_destroy_image(param->mlx_ptr, param->img);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        mlx_clear_window(param->mlx_ptr, param->win_ptr);
        exit(0);
    }
    if (keycode == 257 || keycode == 258)
    {
        color_degrade_Julia((ITR / 255) * 255);
    }
    if (keycode == 126)
        param->y -= 50;
    else if (keycode == 125)
        param->y += 50;
    else if (keycode == 123)
        param->x -= 50;
    else if (keycode == 124)
        param->x += 50;
	if(param->set == 0)
		MNDLBRT_function_pixel_put(param);
	else if(param->set == 1)
		Julia_function_pixel_put(param);
    return (0);
}

