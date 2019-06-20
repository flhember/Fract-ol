/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:40:58 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 14:49:59 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_mouse_move_julia(int x, int y, t_env **data)
{
	if ((*data)->lock == 1 && x > 0 && y > 0 && x < RESO_X && y < RESO_Y)
	{
		(*data)->cr_incr = (x + ((*data)->pts.trans_x) * 14)
			/ (*data)->pts.zoom;
		(*data)->ci_incr = (y + ((*data)->pts.trans_y) * 14)
			/ (*data)->pts.zoom;
		if ((ft_print_fract_thr(**data)) == -1)
			return (-1);
	}
	return (0);
}

int			ft_mouse_press(int key, int x, int y, t_env **data)
{
	if ((*data)->lock == 0 && key == MOUSE_UP)
		ft_zoom_up(x, y, data);
	if ((*data)->lock == 0 && key == MOUSE_DWN)
		ft_zoom_down(x, y, data);
	if ((*data)->lock == 1 && key == 1 && (*data)->fract == 2)
		(*data)->lock = 0;
	else if (key == 1 && (*data)->fract == 2)
		(*data)->lock = 1;
	if ((*data)->fract != 3 && (*data)->lock_psy == 1)
	{
		(*data)->color_base = (*data)->tab_color[(*data)->index_color++];
		(*data)->index_color == 3 ? (*data)->index_color = 0
			: (*data)->index_color;
	}
	if ((ft_print_fract_thr(**data)) == -1)
		return (-1);
	return (0);
}

int			ft_key_press(int key, t_env **data)
{
	if (key == P)
		(*data)->lock_psy = 1;
	if (key == O)
		(*data)->lock_psy = 0;
	if (key == MAND || key == JULI || key == BURN)
		if ((ft_choose_fract(key, data)) == -1)
			return (-1);
	if (key == COLOR || key == COLOR1 || key == COLOR2)
		if ((ft_choose_color(key, data)) == -1)
			return (-1);
	if (key == ARW_UP || key == ARW_DN || key == ARW_LT || key == ARW_RT)
		if ((ft_move_trans(key, data)) == -1)
			return (-1);
	if (key == R)
		if ((ft_init_pts(data)) == -1)
			return (-1);
	if (key == ESC)
	{
		ft_free(data);
		exit(0);
	}
	return (0);
}
