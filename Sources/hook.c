/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:16:57 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/01 12:23:23 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_putstr(END);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 123)
		data->pos_x -= 0.25 / data->zoom;
	if (keycode == 124)
		data->pos_x += 0.25 / data->zoom;
	if (keycode == 125)
		data->pos_y += 0.25 / data->zoom;
	if (keycode == 126)
		data->pos_y -= 0.25 / data->zoom;
	if (keycode == 49)
		data->color += 1750;
	if (keycode == 51)
		data->color -= 1750;
	if (data->select == 1)
		julia_set(data);
	if (data->select == 2)
		mandelbrot_set(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (keycode == 5)
	{
		data->zoom *= pow(1.001, 105.5);
		if (data->select == 1)
			julia_set(data);
		if (data->select == 2)
			mandelbrot_set(data);
	}
	if (keycode == 4)
	{
		data->zoom /= pow(1.001, 105.5);
		if (data->select == 1)
			julia_set(data);
		if (data->select == 2)
			mandelbrot_set(data);
	}
	return (0);
}
