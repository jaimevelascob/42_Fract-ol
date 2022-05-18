/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:22:30 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/18 21:08:24 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define DATA_WAIT 100
# include <mlx.h>
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "math.h"
# include "string.h"

typedef struct s_data {
	int		wait;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_iter;
	int		w;
	int		h;
	int		fractol_val;
	int		xjul;
	int		yjul;
	double	maxreal;
	double	scale;
	double	minreal;
	double	maximg;
	double	minimg;
	double	cen_x;
	double	cen_y;
	double	angle;
}	t_data;

typedef struct s_fractol {
	double	cr;
	double	ci;
	double	re;
	double	im;
}	t_fractol;

t_data	*ft_blank(t_data *data, int num_fractol);
void	ft_init_julia(t_data *data);
void	ft_init_mandel(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	put_pixel(t_data *data, int x, int y, int color);
int		mandel_fractol(t_data *data);
int		julia_fractol(t_data *data);
int		ship_fractol(t_data *data);
int		render_color(t_data *data, int iter);
void	ft_check_argv(char **argv);
void	ft_process_fractol(int num_fractol);
int		render_next_frame(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
void	ft_draw_fractol(t_data *data);
int		wait_next_frame(t_data *data);

#endif
