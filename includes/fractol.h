/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:16:44 by flhember          #+#    #+#             */
/*   Updated: 2019/06/19 17:43:39 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/includes/libft.h"
# include <mlx.h>
# include <pthread.h>

# define NB_THREAD	4
# define ORANGE		0xFFC71A
# define GREEN		0x005028
# define PINK		0xF469BD
# define MAND		83
# define JULI		84
# define BURN		85
# define COLOR		89
# define COLOR1		91
# define COLOR2		92
# define R			15
# define P			35
# define O			31
# define ARW_UP 	126
# define ARW_DN		125
# define ARW_LT		123
# define ARW_RT		124
# define ESC		53
# define PLUS		69
# define RESO_X		1280
# define RESO_Y		720
# define MOUSE_UP	4
# define MOUSE_DWN	5

typedef struct		s_pts
{
	int				x;
	int				y;
	double			tmp;
	double			x1;
	double			y1;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			trans_x;
	double			trans_y;
	double			zoom;
}					t_pts;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned char	*img_str;
	int				endian;
	int				s_l;
	int				bpp;
	int				iter_max;
	int				iter_max_start;
	int				fract;
	void			*ptr_ft;
	int				lock;
	int				lock_psy;
	double			cr_incr;
	double			ci_incr;
	unsigned int	color_base;
	int				index_color;
	unsigned int	tab_color[3];
	struct s_pts	pts;
}					t_env;

typedef	struct		s_thr
{
	pthread_t		thread;
	int				index;
	struct s_env	data;
}					t_thr;

int					ft_check_param(char *fract);
int					ft_fractol(int nb_fract);
int					ft_close(t_env **data);
int					ft_print_fract_thr(t_env data);
int					ft_mouse_press(int button, int x, int y, t_env **data);
int					ft_mouse_move_julia(int x, int y, t_env **data);
int					ft_key_press(int key, t_env **data);
int					ft_init_pts(t_env **data);
void				ft_color_psy(t_env *thr, int x, int y, int i);
void				ft_color_deg(t_env *thr, int x, int y, int i);
void				*ft_calc_mandelbrot(void *thr);
void				*ft_calc_julia(void *thr);
void				*ft_calc_burning_ship(void *thr);
int					ft_move_trans(int key, t_env **data);
int					ft_choose_fract(int key, t_env **data);
void				ft_zoom_up(int x, int y, t_env **data);
void				ft_zoom_down(int x, int y, t_env **data);
int					ft_choose_color(int key, t_env **data);
void				ft_free(t_env **data);

#endif
