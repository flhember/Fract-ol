/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:27:13 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 17:43:09 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_zoom_up(int x, int y, t_env **data)
{
	(*data)->iter_max += 1;
	(*data)->pts.x1 = ((x + (*data)->pts.trans_x) / (*data)->pts.zoom
			+ (*data)->pts.x1) - ((x + (*data)->pts.trans_x)
			/ ((*data)->pts.zoom * 1.2));
	(*data)->pts.y1 = ((y + (*data)->pts.trans_y) / (*data)->pts.zoom
			+ (*data)->pts.y1) - ((y + (*data)->pts.trans_y)
			/ ((*data)->pts.zoom * 1.2));
	(*data)->pts.zoom *= 1.2;
}

void		ft_zoom_down(int x, int y, t_env **data)
{
	(*data)->iter_max -= 1;
	(*data)->pts.x1 = ((x + (*data)->pts.trans_x) / (*data)->pts.zoom
			+ (*data)->pts.x1) - ((x + (*data)->pts.trans_x)
			/ ((*data)->pts.zoom / 1.2));
	(*data)->pts.y1 = ((y + (*data)->pts.trans_y) / (*data)->pts.zoom
			+ (*data)->pts.y1) - ((y + (*data)->pts.trans_y)
			/ ((*data)->pts.zoom / 1.2));
	(*data)->pts.zoom /= 1.2;
}

int			ft_choose_fract(int key, t_env **data)
{
	if (key == MAND && (*data)->fract != 1)
		(*data)->fract = 1;
	if (key == JULI && (*data)->fract != 2)
		(*data)->fract = 2;
	if (key == BURN && (*data)->fract != 3)
		(*data)->fract = 3;
	if ((ft_init_pts(data)) == -1)
		return (-1);
	return (0);
}

int			ft_choose_color(int key, t_env **data)
{
	if (key == COLOR && (*data)->color_base != ORANGE)
		(*data)->color_base = ORANGE;
	if (key == COLOR1 && (*data)->color_base != GREEN)
		(*data)->color_base = GREEN;
	if (key == COLOR2 && (*data)->color_base != PINK)
		(*data)->color_base = PINK;
	if ((ft_print_fract_thr(**data)) == -1)
		return (-1);
	return (0);
}

int			ft_move_trans(int key, t_env **data)
{
	if (key == ARW_UP)
		(*data)->pts.trans_y -= 30;
	if (key == ARW_DN)
		(*data)->pts.trans_y += 30;
	if (key == ARW_LT)
		(*data)->pts.trans_x -= 30;
	if (key == ARW_RT)
		(*data)->pts.trans_x += 30;
	if ((ft_print_fract_thr(**data)) == -1)
		return (-1);
	return (0);
}
