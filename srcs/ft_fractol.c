/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:29:35 by flhember          #+#    #+#             */
/*   Updated: 2019/06/20 14:50:23 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_set_tab_color(t_env **data)
{
	(*data)->tab_color[0] = ORANGE;
	(*data)->tab_color[1] = GREEN;
	(*data)->tab_color[2] = PINK;
}

static int	ft_even(t_env **data)
{
	if ((mlx_hook((*data)->win_ptr, 6, 0, ft_mouse_move_julia, data)) == -1)
		return (-1);
	if ((mlx_hook((*data)->win_ptr, 2, 0, ft_key_press, data)) == -1)
		return (-1);
	mlx_hook((*data)->win_ptr, 17, 0, ft_close, data);
	if ((mlx_hook((*data)->win_ptr, 4, 0, ft_mouse_press, data)) == -1)
		return (-1);
	mlx_loop((*data)->mlx_ptr);
	return (0);
}

int			ft_fractol(int nb_fract)
{
	t_env	*data;

	data = NULL;
	if (!(data = (t_env*)ft_memalloc(sizeof(t_env))))
	{
		ft_putstr_fd("Malloc erreur\n", 2);
		return (-1);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, RESO_X, RESO_Y, "Fractol");
	ft_set_tab_color(&data);
	data->fract = nb_fract;
	data->color_base = ORANGE;
	data->img_ptr = mlx_new_image(data->mlx_ptr, RESO_X, RESO_Y);
	data->img_str = (unsigned char*)mlx_get_data_addr(data->img_ptr,
		&data->bpp, &data->s_l, &data->endian);
	ft_init_pts(&data);
	if ((ft_even(&data)) == -1)
	{
		ft_free(&data);
		return (-1);
	}
	return (0);
}
