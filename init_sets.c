/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:02:31 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/18 21:02:49 by jvelasco         ###   ########.fr       */
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
