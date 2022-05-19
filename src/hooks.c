/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:06:16 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/19 18:21:53 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	{
		data->scale = 1;
		data->cen_x = 0;
		data->cen_y = 0;
	}
	else if (keycode == 78)
		data->angle -= 0.1;
	else if (keycode == 69)
		data->angle += 0.1;
	else if (keycode == 53)
		exit(0);
	data->wait = DATA_WAIT;
	return (1);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 5)
		data->scale += (data->scale * 0.1);
	else if (button == 4)
		data->scale -= data->scale * 0.1;
	data->wait = DATA_WAIT;
	return (1);
}
