/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:04:36 by flhember          #+#    #+#             */
/*   Updated: 2019/06/19 17:16:35 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_print_fract_thr(t_env data)
{
	int		i;
	int		ret;
	t_thr	tab[NB_THREAD];

	i = 0;
	ret = 0;
	while (!ret && i < NB_THREAD)
	{
		tab[i].index = i;
		tab[i].data = data;
		ret = pthread_create(&tab[i].thread, NULL, data.ptr_ft, &tab[i]);
		if (ret)
		{
			ft_putstr_fd("tread erreur\n", 2);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < NB_THREAD)
		pthread_join(tab[i++].thread, NULL);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr
			, data.img_ptr, 0, 0);
	return (0);
}
