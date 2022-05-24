/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:56:28 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/24 19:48:32 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_draw_fractol(t_data *data)
{
	if (!data->img)
	{
		data->img = mlx_new_image(data->mlx, data->w, data->h);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
	}
	if (data->fractol_val == 1)
	{
		ft_init_mandel(data);
		mandel_fractol(data);
	}
	if (data->fractol_val == 2)
	{
		ft_init_julia(data);
		julia_fractol(data);
	}
	if (data->fractol_val == 3)
	{
		ft_init_mandel(data);
		newset(data);
	}
}

int	wait_next_frame(t_data *data)
{
	if (data->wait == 1)
		render_next_frame(data);
	else
		data->wait--;
	return (0);
}

int	render_next_frame(t_data *data)
{
	ft_draw_fractol(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

void	ft_process_fractol(int num_fractol)
{
	t_data	data;

	data = *ft_blank(&data, num_fractol);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.w, data.h, "just a window");
	render_next_frame(&data);
	mlx_loop_hook(data.mlx, wait_next_frame, (void *) &data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
}

int	main(__attribute((unused))int argc, char **argv)
{
	if (!argv[1])
	{		
		printf("1. mandelbrot\n");
		printf("2. julia\n");
		printf("3. ship\n");
	}
	else
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			ft_process_fractol(1);
		else if (!ft_strncmp(argv[1], "julia", 5))
			ft_process_fractol(2);
		else if (!strcmp(argv[1], "ship"))
			ft_process_fractol(3);
		else
		{
			printf("1. mandelbrot\n");
			printf("2. julia\n");
			printf("3. ship\n");
		}
	}
	return (0);
}
