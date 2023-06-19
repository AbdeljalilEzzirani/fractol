/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:35 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/19 17:14:18 by abez-zir         ###   ########.fr       */
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
	ft_putstr("if you use Burning_Ship print --> < ./fractol Burning_Ship > \n");
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void keyhook(int keycode, t_data *param)
{
    if (keycode == 49)
        param->zawm = 49;
    else if (keycode == 48)
        param->zawm = 48;

    if (keycode == 257)
        param->trgb = 257;
    if (keycode == 1)
        param->trgb = 1;
    if (keycode == 2)
        param->trgb = 2;
    if (keycode == 3)
        param->trgb = 3;
    if (keycode == 4)
        param->trgb = 4;
    if (keycode == 5)
        param->trgb = 5;
}

int flesh_key_hook(int keycode, t_data *param)
{
    keyhook(keycode, param);
    if (keycode == 53)
        ft_exit(param);
    if (keycode == 126)
        param->y += 10;
    else if (keycode == 125)
        param->y -= 10;
    else if (keycode == 123)
        param->x += 10;
    else if (keycode == 124)
        param->x -= 10;
	if(param->set == 0)
    {
        mlx_clear_window(param->mlx_ptr, param->win_ptr);
		MNDLBRT_function_pixel_put(param);
    }
	else if(param->set == 1)
    {    
		Julia_function_pixel_put(param);
    }
	else if(param->set == 2)
		Burning_Ship_function_pixel_put(param);
    return (0);
}

int    ft_exit(t_data *param)
{
    mlx_destroy_image(param->mlx_ptr, param->img);
    mlx_clear_window(param->mlx_ptr, param->win_ptr);
    mlx_destroy_window(param->mlx_ptr, param->win_ptr);
    exit(0);
}
