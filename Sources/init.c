/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:21:58 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/01 12:57:56 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	ft_arg_select(char *str)
{
	if (ft_strcmp(str, "Julia") == 0)
		return (1);
	else if (ft_strcmp(str, "Mandelbrot") == 0)
		return (2);
	else
	{
		ft_putstr(FR_NA_ERR);
		ft_exit(LST_FR);
	}
	return (0);
}

float	get_c_re(void)
{
	double	tmp;
	int		count;

	tmp = 0.0;
	count = 1;
	ft_putstr(C_VALUE);
	while (19)
	{
		ft_putstr(GET_RE);
		tmp = ft_atof(get_next_line(1));
		if (tmp <= -2.0 || tmp >= 2.0)
		{
			ft_putstr(RE_IM_ERR);
			if (count > 5)
				ft_exit(FR_NA_5_ERR);
			if (count > 2)
				ft_putstr(AGAIN_ERR);
		}
		else
			return (tmp);
		count++;
	}
	return (0);
}

float	get_c_im(void)
{
	double	tmp;
	int		count;

	tmp = 0.0;
	count = 1;
	while (19)
	{
		ft_putstr(GET_IM);
		tmp = ft_atof(get_next_line(1));
		if (tmp <= -2.0 || tmp >= 2.0)
		{
			ft_putstr(RE_IM_ERR);
			if (count > 5)
				ft_exit(FR_NA_5_ERR);
			if (count > 2)
				ft_putstr(AGAIN_ERR);
		}
		else
			return (tmp);
		count++;
	}
	return (0);
}

void	ft_init_fra(t_data *d)
{
	d->pos_x = 0;
	d->pos_y = 0;
	d->zoom = 1;
	d->color = 5;
	d->count = 0;
}

int	put_text(t_data *d)
{
	char	*fractal;
	int		text_color;

	text_color = 0x0000000;
	if (d->select == 1)
		fractal = "Julia";
	else
		fractal = "Mandelbrot";
	mlx_string_put(d->mlx, d->mlx_win, 10, 20, text_color, "Choosen set  =");
	mlx_string_put(d->mlx, d->mlx_win, 112, 20, text_color, fractal);
	mlx_string_put(d->mlx, d->mlx_win, 10, 37, text_color, "Iterations   =");
	return (0);
}
