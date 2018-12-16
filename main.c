/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2018/12/16 14:40:11 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft/libft.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "includes/fdf.h"

void	refresh_screen(t_win *win)
{
		mlx_destroy_image(win->mlxp, win->simg.imgp);
		win->simg.imgp = mlx_new_image(win->mlxp, WINX, WINY);
		win->simg.data = (int*)mlx_get_data_addr(win->simg.imgp, &(win->simg.bpp), &(win->simg.s_l), &(win->simg.endian));

//		Fonction de remplissage d'image ICI

		mlx_put_image_to_window(win->mlxp, win->winp, win->simg.imgp, 0, 0);
}

int		deal_with_keyboard(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == /*ESC*/53)
	{
		/*free les variables*/
		printf("%s, %d\n", "Echap", key);
		exit(0);
	}
	else
		printf("%s, %d\n", "Autre", key);
	return (0);
}

int		main(int ac, char **av)
{
	t_win		w;

	w.m.nbl = 0;
	if (ac != 2)
	{
		printf("Usage: ./fdf [map]\n");
		return (0);
	}

// Initialisation des variables (mlx)
	w.mlxp = mlx_init();
	w.winp = mlx_new_window(w.mlxp, WINX, WINY, "FDF");
//	init_vectors(&w, w.vec);
	(void)av;

// Recuperation du nombre de ligne
	file_to_tab(av[1], &(w.m));
	w.m.mat = init_matrice();

// Creation d'image
	w.simg.imgp = mlx_new_image(w.mlxp, WINX, WINY);
	w.simg.data = (int*)mlx_get_data_addr(w.simg.imgp,\
					 &(w.simg.bpp), &(w.simg.s_l), &(w.simg.endian));

// Remplisage ICI
	init_map(&w);

// Affichage
	mlx_put_image_to_window(w.mlxp, w.winp, w.simg.imgp, 0, 0);

// Boucle de recuperation
//	mlx_mouse_hook(w.winp, deal_key, &w);
	mlx_key_hook(w.winp, deal_with_keyboard, &w);

// Boucle finale (infinie)
	mlx_loop(w.mlxp);
	return (0);
}
