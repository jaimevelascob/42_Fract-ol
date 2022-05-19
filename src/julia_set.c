/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:15:49 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/19 18:22:03 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_julia_fractol(t_data *data, int x, int y)
{
	int			iter;
	double		tr;
	int			color;
	t_fractol	fractol;

	fractol.re = (x / (data->w / (data->maxreal - data->minreal))
			+ data->minreal) / (data->scale) + data->cen_x;
	fractol.im = (y / (data->h / (data->maximg - data->minimg))
			+ data->minimg) / (data->scale) + data->cen_y;
	fractol.cr = sin(data->angle);
	fractol.ci = cos(data->angle * 3.123);
	iter = 0;
	while (iter < data->max_iter)
	{
		tr = fractol.re * fractol.re - fractol.im * fractol.im + fractol.cr;
		fractol.im = 2.0 * fractol.re * fractol.im + fractol.ci;
		fractol.re = tr;
		if (fractol.re * fractol.re + fractol.im * fractol.im > 4)
			break ;
		iter++;
	}
	color = render_color(data, iter);
	put_pixel(data, x, y, color);
}

int	julia_fractol(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->w)
	{
		y = 0;
		while (y < data->h)
			ft_julia_fractol(data, x, y++);
		x++;
	}
	return (1);
}
