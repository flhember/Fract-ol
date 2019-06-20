/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:31:54 by flhember          #+#    #+#             */
/*   Updated: 2019/06/18 12:10:05 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_check_param(char *fract)
{
	if (ft_strcmp("Mandelbrot", fract) == 0)
		return (1);
	else if (ft_strcmp("Julia", fract) == 0)
		return (2);
	else if (ft_strcmp("Burning_ship", fract) == 0)
		return (3);
	return (0);
}
