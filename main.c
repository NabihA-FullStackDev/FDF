/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:20:57 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft/libft.h"
#include "includes/fdf.h"

void	init_struct_window(t_win *w, char *file)
{
	w->m.nbl = 0;
	w->mlxp = mlx_init();
	w->winp = mlx_new_window(w->mlxp, WINX, WINY, "FDF");
	w->alpha = -45;
	w->beta = 45;
	w->ceta = -60;
	w->t_x = (WINX / 2) - (w->m.xmax / 2);
	w->t_y = (WINY / 2) - (w->m.ymax / 2);
	w->t_z = 42;
	w->zoom = 25;
	if (file_to_tab(file, &(w->m)) == -1)
		exit(-1);
	w->m.mat = init_matrice();
}

int		main(int ac, char **av)
{
	t_win		w;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf [map]\n");
		return (0);
	}
	init_struct_window(&w, av[1]);
	w.simg.imgp = mlx_new_image(w.mlxp, WINX, WINY);
	w.simg.data = (int*)mlx_get_data_addr(w.simg.imgp,\
					&(w.simg.bpp), &(w.simg.s_l), &(w.simg.endian));
	init_map(&w);
	mlx_put_image_to_window(w.mlxp, w.winp, w.simg.imgp, 0, 0);
	mlx_hook(w.winp, 2, 1L << 0, deal_with_keyboard, &w);
	mlx_loop(w.mlxp);
	return (0);
}
