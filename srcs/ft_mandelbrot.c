/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:30:53 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 14:55:27 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_init_c_z(t_thr *thr)
{
	thr->data.pts.c_i = (double)thr->data.pts.y / thr->data.pts.zoom
		+ thr->data.pts.y1;
	thr->data.pts.z_r = 0;
	thr->data.pts.z_i = 0;
}

static void	ft_calc_z(t_thr *thr)
{
	thr->data.pts.tmp = thr->data.pts.z_r;
	thr->data.pts.z_r = (thr->data.pts.z_r * thr->data.pts.z_r)
		- (thr->data.pts.z_i * thr->data.pts.z_i) + thr->data.pts.c_r;
	thr->data.pts.z_i = (2 * thr->data.pts.z_i * thr->data.pts.tmp)
					+ thr->data.pts.c_i;
}

static void	ft_calc_pixel(t_thr *thr)
{
	int		i;

	i = 0;
	while ((thr->data.pts.z_r * thr->data.pts.z_r) + (thr->data.pts.z_i
			* thr->data.pts.z_i) < 4 && i < thr->data.iter_max)
	{
		ft_calc_z(thr);
		i++;
	}
	ft_color_psy(&thr->data, thr->data.pts.x - thr->data.pts.trans_x
		, thr->data.pts.y - thr->data.pts.trans_y, i);
}

void		*ft_calc_mandelbrot(void *thd)
{
	t_thr	*thr;

	thr = (t_thr*)thd;
	thr->data.pts.x = thr->data.pts.trans_x + ((RESO_X / NB_THREAD)
			* thr->index);
	while (thr->data.pts.x < thr->data.pts.trans_x + ((RESO_X / NB_THREAD)
				* (thr->index + 1)))
	{
		thr->data.pts.y = thr->data.pts.trans_y;
		thr->data.pts.c_r = thr->data.pts.x / thr->data.pts.zoom
			+ thr->data.pts.x1;
		while (thr->data.pts.y < RESO_Y + thr->data.pts.trans_y)
		{
			ft_init_c_z(thr);
			ft_calc_pixel(thr);
			thr->data.pts.y++;
		}
		thr->data.pts.x++;
	}
	return (thr);
}
