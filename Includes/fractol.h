/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:46:35 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/01 12:56:32 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "messages.h"

/*- WINDOW SETTINGS -----*/
# define W 750
# define H 550
# define MAX_ITER 42

/*- FRACTAL & IMAGE -----*/
typedef struct s_data
{
	int		select;
	int		x;
	int		y;
	int		i;
	int		count;
	double	re;
	double	im;
	double	pr;
	double	pi;
	double	new_re;
	double	new_im;
	double	tmp_re;
	double	tmp_im;
	double	pos_x;
	double	pos_y;
	double	zoom;
	int		color;
	USI		max_color;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

/*----- ATOF ------------*/
typedef struct s_atof
{
	double	res;
	int		sign;
	int		count;
	int		i;
}				t_atof;

/*--	MAIN.c ------------------------*/
int		hi_window(t_data *data);

/*--    FRACTALS.c --------------------*/
void	julia_set(t_data *data);
void	mandelbrot_set(t_data *data);
int		ft_iter(t_data *d);

/*--	INIT.c ------------------------*/
int		ft_arg_select(char *str);
float	get_c_re(void);
float	get_c_im(void);
void	ft_init_fra(t_data *data);
int		put_text(t_data *d);

/*--	HOOK.c ------------------------*/
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);

/*--	COLORS.c ----------------------*/
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
USI		ft_color(int i, t_data *data);

/*--	GNL.c -------------------------*/
double	ft_atof(const char *s);
char	*ft_strjoin_gnl(char *line, char c);
char	*get_next_line(int const fd);
int		ft_check_for_atof(const char *s);

/*--	UTILS.c -----------------------*/
void	ft_putstr(char *str);
int		ft_exit(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
int		ft_lenint(int n);

#endif
