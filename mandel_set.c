/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:15:49 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/18 19:57:21 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandel(t_data *data)
{
	data->maxreal = 2;
	data->minreal = -2;
	data->maximg = 2;
	data->minimg = -2;
}

void	ft_init_julia(t_data *data)
{
	data->maxreal = 1.5;
	data->minreal = -1.5;
	data->maximg = 1.5;
	data->minimg = -1.5;
}

t_data	*ft_blank(t_data *data, int num_fractol)
{
	data->wait = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->maxreal = .0;
	data->minreal = .0;
	data->minimg = .0;
	data->maximg = .0;
	data->xjul = .0;
	data->yjul = .0;
	data->cen_x = .0;
	data->cen_y = .0;
	data->w = 900;
	data->h = 600;
	data->max_iter = 100;
	data->scale = 1.0;
	data->angle = 0;
	data->fractol_val = num_fractol;
	return (data);
}


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
