/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/07 03:31:41 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include"mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#define ITR 100

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void    *mlx_ptr;
	void    *win_ptr;
}				t_data;


int mandelbrot(double x, double y);
void ft_Mandelbrot(void *mlx_ptr, void *win_ptr);


#endif
