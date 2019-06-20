/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:56:49 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 11:57:05 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static unsigned int	ft_findcolor(t_env *data, int i, unsigned int color)
{
	int		r;
	int		g;
	int		b;

	r = (i * 255 / data->iter_max_start) * color;
	g = (i * 255 / data->iter_max_start) * color;
	b = (i * 255 / data->iter_max_start) * color;
	return ((r >> 16) + (g + 8) + b);
}

void				ft_color_psy(t_env *data, int x, int y, int i)
{
	int				pixel;
	unsigned int	color;

	color = ft_findcolor(data, i, data->color_base);
	pixel = (4 * x) + (4 * RESO_X * y);
	if (x >= 0 && y >= 0 && x < RESO_X && y < RESO_Y)
	{
		if (i == data->iter_max)
		{
			data->img_str[pixel] = 0;
			data->img_str[pixel + 1] = 0;
			data->img_str[pixel + 2] = 0;
		}
		else
		{
			data->img_str[pixel] = color;
			data->img_str[pixel + 1] = color >> 8;
			data->img_str[pixel + 2] = color >> 16;
		}
	}
}

void				ft_color_deg(t_env *data, int x, int y, int i)
{
	int				pixel;

	pixel = (4 * x) + (4 * RESO_X * y);
	if (x >= 0 && y >= 0 && x < RESO_X && y < RESO_Y)
	{
		if (i == data->iter_max)
		{
			data->img_str[pixel] = 0;
			data->img_str[pixel + 1] = 0;
			data->img_str[pixel + 2] = 0;
		}
		else
		{
			data->img_str[pixel] = 0;
			data->img_str[pixel + 1] = (i * 255 / data->iter_max_start);
			data->img_str[pixel + 2] = 0;
		}
	}
}
