/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:06:16 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/20 19:20:05 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_reset(t_data *data)
{
	data->scale = 1;
	data->cen_x = 0;
	data->cen_y = 0;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 123)
		data->cen_x += 0.2;
	else if (keycode == 124)
		data->cen_x -= 0.2;
	else if (keycode == 125)
		data->cen_y -= 0.2;
	else if (keycode == 126)
		data->cen_y += 0.2;
	else if (keycode == 29)
		ft_reset(data);
	else if (keycode == 78)
		data->angle -= 0.1;
	else if (keycode == 69)
		data->angle += 0.1;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 67)
		data->max_iter += 100;
	else if (keycode == 75)
		data->max_iter -= 100;
	data->wait = DATA_WAIT;
	return (1);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		data->scale += data->scale * 0.1;
		data->cen_x += ((float)(x - data->w / 2) / data->w) / 4 / data->scale;
		data->cen_y += -((float)(y - data->h / 2) / data->h) / 4 / data->scale;
	}
	else if (button == 4)
		data->scale -= data->scale * 0.1;
	data->wait = DATA_WAIT;
	return (1);
}
