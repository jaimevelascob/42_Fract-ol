/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:02:31 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/19 18:41:57 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_init_mandel(t_data *data)
{
	data->maxreal = 2;
	data->minreal = -2;
	data->maximg = 2;
	data->minimg = -2;
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

void	ft_init_julia(t_data *data)
{
	data->maxreal = 1.5;
	data->minreal = -1.5;
	data->maximg = 1.5;
	data->minimg = -1.5;
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*news1;
	unsigned char	*news2;

	i = 0;
	if (n == 0)
		return (0);
	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (news1[i] == news2[i] && news1[i] != '\0'
		&& news2[i] != '\0' && i < n)
		i++;
	if (i != n)
		return (news1[i] - news2[i]);
	return (0);
}
