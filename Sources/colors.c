/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:09:56 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/01 12:23:08 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_len + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_color(int i, t_data *d)
{
	unsigned int	c;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	d->max_color = 0x0000000;
	if (i == MAX_ITER)
		return (d->max_color);
	r = (i * 5) * d->color;
	g = (255 - (i * 10)) * d->color;
	b = (255 - (i * 2)) * d->color;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
