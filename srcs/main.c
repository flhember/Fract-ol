/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:18:28 by flhember          #+#    #+#             */
/*   Updated: 2019/06/19 17:42:48 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int		main(int arc, char **arv)
{
	int		nb_fract;

	if (arc != 2 || (nb_fract = ft_check_param(arv[1])) == 0)
	{
		ft_putstr_fd("Usage :\n - ./fractol Julia"
				"\n - ./fractol Mandelbrot"
				"\n - ./fractol Burning_ship\n", 2);
		return (-1);
	}
	if (ft_fractol(nb_fract) == -1)
		return (-1);
	return (0);
}
