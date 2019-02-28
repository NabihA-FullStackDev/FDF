/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:23:19 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 09:43:55 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			refresh_screen(t_win *win)
{
	mlx_destroy_image(win->mlxp, win->simg.imgp);
	win->simg.imgp = mlx_new_image(win->mlxp, WINX, WINY);
	win->simg.data = (int*)mlx_get_data_addr(win->simg.imgp, \
												&(win->simg.bpp), \
													&(win->simg.s_l), \
														&(win->simg.endian));
	init_map(win);
	mlx_clear_window(win->mlxp, win->winp);
	mlx_put_image_to_window(win->mlxp, win->winp, win->simg.imgp, 0, 0);
}
