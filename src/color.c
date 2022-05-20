/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:02:26 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/20 18:28:13 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	render_color(t_data *data, int iter)
{
	if (iter < 16)
		iter = create_trgb(0, iter * 8, iter * 8, 128 + iter * 4);
	else if (iter < 64)
		iter = create_trgb(0, 128 + iter -16, 128
				+ iter - 16, 192 + iter - 16);
	else if (iter >= 64 && iter < data->max_iter)
		iter = create_trgb(0, data->max_iter - iter, 128
				+ (data->max_iter - iter) / 2, data->max_iter - iter);
	else
		iter = create_trgb(0, 0, 0, 0);
	return (iter);
}
