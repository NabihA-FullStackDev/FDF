/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2018/12/10 19:30:20 by naali            ###   ########.fr       */
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

/*
** Test de recuperation des touche
*/

int		deal_key(int key, void *ptr)
{
	t_fdf	*test;
	test = (t_fdf*)ptr;
	if (key == ESC)
	{
		test->keys = esc;
		printf("%s, %d\n", "Echap", test->keys);
		exit(0);
	}
	if (key == FLG)
	{
		test->keys = fg;
		printf("%s, %d\n", "Fleche Gauche", test->keys);
	}
	if (key == FLD)
	{
		test->keys = fd;
		printf("%s, %d\n", "Fleche Gauche", test->keys);
	}
	if (key == FLB)
	{
		test->keys = fb;
		printf("%s, %d\n", "Fleche Gauche", test->keys);
	}
	if (key == FLH)
	{
		test->keys = fh;
		printf("%s, %d\n", "Fleche Gauche", test->keys);
	}
	return (0);
}

/*
** Affiche un carre
*/

void	print_square(t_fdf *s, t_map *m)
{
	s->y = 0;
	while (s->y < m->ymax)
	{
		s->x = 0;
		while (s->x < m->xmax)
		{
			if (m->tab[s->y][s->x] == 0)
				s->simg.data[(s->y * WINX + s->x)*10] = 0xFFFFFF;
			else if (m->tab[s->y][s->x] > 0)
				s->simg.data[(s->y * WINX + s->x)*10] = 0xFF0000;
			s->x++;
		}
		s->y++;
	}
}

int		main(int ac, char **av)
{
	t_fdf	s;
	t_map	m;

	m.nbl = 0;
	if (ac != 2)
	{
		printf("Usage: ./fdf [map]\n");
		return (0);
	}
// Initialisation des variables (mlx)
	s.mlxp = mlx_init();
	s.winp = mlx_new_window(s.mlxp, WINX, WINY, "Test");

// Recuperation du nombre de ligne
	file_to_tab(av[1], &m);
	printf("xmax = %d, ymax = %d\n", m.xmax, m.ymax);
// Creation d'image
	s.simg.imgp = mlx_new_image(s.mlxp, WINX, WINY);
	s.simg.data = (int*)mlx_get_data_addr(s.simg.imgp, &(s.simg.bpp), &(s.simg.s_l), &(s.simg.endian));

// Remplisage
	print_square(&s, &m);

// Affichage
	mlx_put_image_to_window(s.mlxp, s.winp, s.simg.imgp, 0, 0);

// Boucle de recuperation
	mlx_key_hook(s.winp, deal_key, &s);

// Boucle finale
	mlx_loop(s.mlxp);
	return (0);
}
