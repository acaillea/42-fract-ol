/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:04:45 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/17 13:04:47 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define USI unsigned int

# define ARG_ERR "\x1b[31mError : Expected format = \x1b[37m./fractol\033[0;39m\
 <\033[1;32mFractal's name\033[0;39m>\033[0;39m\n"
# define FR_NA_ERR "\x1b[31mError : Invalid fractal name, \
try again...\n\033[0;39m"
# define RE_IM_ERR "\x1b[31mError : Re & Im are DOUBLE defined between -2 & \
2\n\033[0;39m"
# define AGAIN_ERR "\x1b[31mAre you failing this on purpose...?\n\033[0;39m"
# define FR_NA_5_ERR "\x1b[31mYou tried.\n\033[0;39m"
# define MLX_ERR "\x1b[31mError : MLX is facing some bad issues.\n\033[0;39m"

# define LST_FR	"\x1b[1m\033[1;32mMenu :\n\033[0;39m\
	\"Julia\" set\n \033[1;32mOr\033[0;39m\n	\"Mandelbrot\" set\n\n"
# define C_VALUE "\x1b[4mGood choice but wait!\n\033[0;39mJulia set is defined\
 according to a basic\ncomplex number which will determine \
their\ngeneral behavior. Complex numbers are\nexpressed as z = x + iy \
where X is the real\npart and y is the imaginary part.\n\
They both have values \033[0;31m\x1b[4mbetween -2 and 2.\n\n\033[0;39m"
# define GET_RE "\x1b[4mEncode a real part :\n\033[0;39m"
# define GET_IM "\x1b[4mEncode a imaginary part :\n\033[0;39m"
# define SUCC "\033[1;32mEnjoy!\033[0;39m\n\
Use :\n- Mouse wheel to zoom in & out.\n- Space bar & delete to switch color.\n\
- Arrow keys to navigate.\n- ESC to quit.\n\033[0;39m"
# define END "\033[1;32mBye bye!\n\033[0;39m"

#endif
