/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:36:03 by flhember          #+#    #+#             */
/*   Updated: 2019/06/11 11:24:51 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_close(t_env **data)
{
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_ptr);
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	free(*data);
	exit(0);
	return (0);
}
