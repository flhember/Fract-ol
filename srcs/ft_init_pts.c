/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:33:58 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 14:53:15 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_init_pts_mandel(t_env **data)
{
	(*data)->iter_max = 50;
	(*data)->pts.x1 = -2.1;
	(*data)->pts.y1 = -1.2;
	(*data)->pts.trans_x = -50;
	(*data)->pts.trans_y = 0;
	(*data)->pts.zoom = 300;
	(*data)->iter_max_start = (*data)->iter_max;
	(*data)->ptr_ft = ft_calc_mandelbrot;
}

static void	ft_init_pts_julia(t_env **data)
{
	(*data)->iter_max = 50;
	(*data)->pts.x1 = -2.1;
	(*data)->pts.y1 = -1.2;
	(*data)->pts.trans_x = -50;
	(*data)->pts.trans_y = 0;
	(*data)->cr_incr = 0;
	(*data)->ci_incr = 0;
	(*data)->pts.zoom = 300;
	(*data)->iter_max_start = (*data)->iter_max;
	(*data)->ptr_ft = ft_calc_julia;
}

static void	ft_init_pts_burning_ship(t_env **data)
{
	(*data)->iter_max = 50;
	(*data)->pts.x1 = -2.1;
	(*data)->pts.y1 = -1.2;
	(*data)->pts.trans_x = -200;
	(*data)->pts.trans_y = -170;
	(*data)->pts.zoom = 250;
	(*data)->iter_max_start = (*data)->iter_max;
	(*data)->ptr_ft = ft_calc_burning_ship;
}

int			ft_init_pts(t_env **data)
{
	if ((*data)->fract == 1)
		ft_init_pts_mandel(data);
	else if ((*data)->fract == 2)
		ft_init_pts_julia(data);
	else if ((*data)->fract == 3)
		ft_init_pts_burning_ship(data);
	if ((ft_print_fract_thr(**data)) == -1)
		return (-1);
	return (0);
}
