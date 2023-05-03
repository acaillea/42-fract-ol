/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:10:49 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/01 12:23:40 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	ft_iter(t_data *d)
{
	double	add_x;
	double	add_y;

	d->i = 0;
	if (d->select == 1)
	{
		add_x = d->re;
		add_y = d->im;
	}
	if (d->select == 2)
	{
		add_x = d->pr;
		add_y = d->pi;
	}
	while (d->i < MAX_ITER)
	{
		d->tmp_re = d->new_re;
		d->tmp_im = d->new_im;
		d->new_re = pow(d->tmp_re, 2) - pow(d->tmp_im, 2) + add_x;
		d->new_im = 2 * d->tmp_re * d->tmp_im + add_y;
		if ((pow(d->new_re, 2) + pow(d->new_im, 2)) > 4)
			break ;
		d->i++;
	}
	return (d->i);
}

void	julia_set(t_data *d)
{
	if (d->count >= 5)
	{
		mlx_clear_window(d->mlx, d->mlx_win);
		d->count = 0;
	}
	d->y = 0;
	while (d->y < H)
	{
		d->x = 0;
		while (d->x < W)
		{
			d->new_re = 1.5 * (d->x - W / 2) / (0.5 * d->zoom * W) + d->pos_x;
			d->new_im = (d->y - H / 2) / (0.5 * d->zoom * H) + d->pos_y;
			d->i = ft_iter(d);
			my_mlx_pixel_put(d, d->x, d->y, ft_color(d->i, d));
			d->x++;
		}
		d->y++;
	}
	d->count++;
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	put_text(d);
}

void	mandelbrot_set(t_data *d)
{
	if (d->count >= 5)
	{
		mlx_clear_window(d->mlx, d->mlx_win);
		d->count = 0;
	}
	d->y = 0;
	while (d->y < H)
	{
		d->x = 0;
		while (d->x < W)
		{
			d->pr = 1.5 * (d->x - W / 2) / (0.5 * d->zoom * W) + d->pos_x;
			d->pi = (d->y - H / 2) / (0.5 * d->zoom * H) + d->pos_y;
			d->new_re = 0.0;
			d->new_im = 0.0;
			d->i = ft_iter(d);
			my_mlx_pixel_put(d, d->x, d->y, ft_color(d->i, d));
			d->x++;
		}
		d->y++;
	}
	d->count++;
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	put_text(d);
}
