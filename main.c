/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2018/12/12 19:44:53 by naali            ###   ########.fr       */
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

void	print_square(t_win *w);

/*
** Test de recuperation des touche
*/

void	zoom(t_win *w, float pas)
{
	(w->vec[0]).x = (w->vec[0]).x * pas;
	(w->vec[0]).y = (w->vec[0]).y * pas;
	(w->vec[0]).z = (w->vec[0]).z * pas;

	(w->vec[1]).x = (w->vec[1]).x * pas;
	(w->vec[1]).y = (w->vec[1]).y * pas;
	(w->vec[1]).z = (w->vec[1]).z * pas;

	(w->vec[2]).x = (w->vec[2]).x * pas;
	(w->vec[2]).y = (w->vec[2]).y * pas;
	(w->vec[2]).z = (w->vec[2]).z * pas;
}

void	translation(t_win *w, float x, float y)
{
	w->xt = w->xt + x;
	w->yt = w->yt + y;
}

void	rotation(t_win *w, float rot)
{
	w->rot = w->rot + rot;
}

int		deal_key(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == ESC)
	{
		/*free les variables*/
		printf("%s, %d\n", "Echap", key);
		exit(0);
	}
	if (key == FLG)
	{
		translation(tmp, -1, 0);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
		printf("%s, %d\n", "Fleche Gauche", key);
	}
	if (key == FLD)
	{
		translation(tmp, 1, 0);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
		printf("%s, %d\n", "Fleche Droite", key);
	}
	if (key == FLB)
	{
		translation(tmp, 0, 1);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
		printf("%s, %d\n", "Fleche Basse", key);
	}
	if (key == FLH)
	{
		translation(tmp, 0, -1);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
		printf("%s, %d\n", "Fleche Haute", key);
	}
	else if (key == 69)
	{
		zoom(tmp, 1.2);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
	}
	else if (key == 78)
	{
		zoom(tmp, 0.8);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
	}
	else if (key == 117)
	{
		rotation(tmp, -0.1);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
	}
	else if (key == 119)
	{
		rotation(tmp, 0.1);

		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		tmp->simg.imgp = mlx_new_image(tmp->mlxp, WINX, WINY);
		tmp->simg.data = (int*)mlx_get_data_addr(tmp->simg.imgp, &(tmp->simg.bpp), &(tmp->simg.s_l), &(tmp->simg.endian));

		print_square(tmp);

		mlx_put_image_to_window(tmp->mlxp, tmp->winp, tmp->simg.imgp, 0, 0);
	}
	else
		printf("%s, %d\n", "Autre", key);
	return (0);
}

/*
** Affiche un carre
*/

void	print_square(t_win *w)
{
	int		x;
	int		xs;
	int		y;
	int		z;

	x = 0;
	y = 0;
	mlx_clear_window(w->mlxp, w->winp);
	w->y = 0;
	while (w->y < w->m.ymax && w->y < WINY)
	{
		w->x = 0;
		while (w->x < w->m.xmax && w->x < WINX)
		{
			x = (int)((w->x * (w->vec[0]).x + w->y * (w->vec[1]).x + z * (w->vec[2]).x) + w->xt);
			y = (int)((w->y * (w->vec[0]).y + w->y * (w->vec[1]).y + z * (w->vec[2]).y) + w->yt);
			z = (w->m).tab[w->y][w->x];
			xs = (int)(x*cos(w->rot) + (y * -sin(w->rot)));
			y = (int)(y*cos(w->rot) + (x * sin(w->rot)));
			x = xs;
			if ((y * WINX + x)/WINX == (y * WINX + (int)(x - w->xt))/WINX && (y * WINX + x) < (WINX * WINY) && (y * WINX + x) >= 0)
			{
				if (z <= 9)
					w->simg.data[(y * WINX + x)] = 0x0000FF;
				else if (z > 9 && z < 20)
					w->simg.data[(y * WINX + x)] = 0xFF0000;
			}
			w->x++;
		}
		w->y++;
	}
}

void	init_vectors(t_win *w, t_vertex *vec)
{
	(vec[0]).x = 1.0;
	(vec[0]).y = 0.0;
	(vec[0]).z = 0.0;

	(vec[1]).x = 0.0;
	(vec[1]).y = 1.0;
	(vec[1]).z = 0.0;

	(vec[2]).x = 0.0;
	(vec[2]).y = 0.0;
	(vec[2]).z = 1.0;

	w->xt = 0;
	w->yt = 0;
	w->rot= 0;
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
	init_vectors(&w, w.vec);

// Recuperation du nombre de ligne
	file_to_tab(av[1], &(w.m));

// Creation d'image
	w.simg.imgp = mlx_new_image(w.mlxp, WINX, WINY);
	w.simg.data = (int*)mlx_get_data_addr(w.simg.imgp, &(w.simg.bpp), &(w.simg.s_l), &(w.simg.endian));

// Remplisage
	print_square(&w);

// Affichage
	mlx_put_image_to_window(w.mlxp, w.winp, w.simg.imgp, 0, 0);

// Boucle de recuperation
	mlx_key_hook(w.winp, deal_key, &w);

// Boucle finale (infinie)
	mlx_loop(w.mlxp);
	return (0);
}
