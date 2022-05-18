/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:15:49 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/18 21:02:45 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel_fractol(t_data *data, int x, int y)
{
	int			iter;
	double		tr;
	int			color;
	t_fractol	fractol;

	fractol.cr = (x / (data->w / (data->maxreal - data->minreal))
			+ data->minreal) / (data->scale) + data->cen_x;
	fractol.ci = (y / (data->h / (data->maximg - data->minimg))
			+ data->minimg) / (data->scale) + data->cen_y;
	fractol.re = 0;
	fractol.im = 0;
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

int	mandel_fractol(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->w)
	{
		y = 0;
		while (y < data->h)
			ft_mandel_fractol(data, x, y++);
		x++;
	}
	return (1);
}
