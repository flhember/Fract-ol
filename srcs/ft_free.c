/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:31:23 by flhember          #+#    #+#             */
/*   Updated: 2019/06/19 17:42:00 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_free(t_env **data)
{
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_ptr);
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	free(*data);
}
