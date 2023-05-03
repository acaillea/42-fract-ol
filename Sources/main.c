/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:46:27 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/06 11:46:30 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	hi_window(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (0);
	d->mlx_win = mlx_new_window(d->mlx, W, H, "fractol @acaillea");
	if (d->mlx_win == NULL)
		return (0);
	d->img = mlx_new_image(d->mlx, W, H);
	if (d->img == NULL)
		return (0);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->line_len, &d->endian);
	if (d->addr == NULL)
		return (0);
	mlx_hook(d->mlx_win, 2, (1L << 0), &key_hook, d);
	mlx_mouse_hook(d->mlx_win, &mouse_hook, d);
	ft_init_fra(d);
	if (d->select == 1)
		julia_set(d);
	if (d->select == 2)
		mandelbrot_set(d);
	put_text(d);
	mlx_loop(d->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac == 2)
		d.select = ft_arg_select(av[1]);
	else
	{
		ft_putstr(ARG_ERR);
		ft_exit(LST_FR);
	}
	if (d.select == 1)
	{
		d.re = get_c_re();
		d.im = get_c_im();
	}
	ft_putstr(SUCC);
	if (hi_window(&d))
		return (ft_exit(MLX_ERR));
	return (0);
}
