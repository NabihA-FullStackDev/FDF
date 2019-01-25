/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:59:33 by naali             #+#    #+#             */
/*   Updated: 2019/01/25 16:24:13 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "libft/libft.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "includes/fdf.h"
#include "includes/t_struct.h"

int			color_choice(int z)
{
	if (z < 5)
		return (0x0000FF);
	else if (z >= 5 && z < 10)
		return (0x00FF00);
	else if (z >= 10 && z < 15)
		return (0xFF0000);
	else if (z >= 15)
		return (0xFFFFFF);
	else
		return (0x000000);
}

void		put_color_to_pix(t_win *w, t_vertex vtx)
{
	int		x;
	int		y;

	x = (int)vtx.x;
	y = ((int)vtx.y - (int)(vtx.z * 0.1));
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
	w->simg.data[(y * WINX) + x] = vtx.color;
}

void		draw_to_img(t_win *w, t_matrice mtmp, int i, int j)
{
	int			z;
	t_vertex	tmp;
	t_vertex	old;

	z = (int)w->m.tab[i][j].z;
	tmp = w->m.tab[i][j];
	tmp = mult_vtex_by_mat(mtmp, tmp);
	w->x = (int)tmp.x;
	w->y = ((int)tmp.y - (int)(tmp.z * 0.1));
	put_color_to_pix(w, tmp);
	if (j > 0)
	{
		w->end = init_vect(tmp.x, (tmp.y - (tmp.z * 0.1)));
		old = w->m.tab[i][j - 1];
		old = mult_vtex_by_mat(mtmp, old);
		w->start = init_vect(old.x, (old.y - (old.z * 0.1)));
		print_line1(w, w->start, w->end, (w->m.tab[i][j].z < w->m.tab[i][j - 1].z) ? tmp.color : old.color);
	}
	if (i > 0)
	{
		w->end = init_vect(tmp.x, (tmp.y - (tmp.z * 0.1)));
		old = w->m.tab[i - 1][j];
		old = mult_vtex_by_mat(mtmp, old);
		w->start = init_vect(old.x, (old.y - (old.z * 0.1)));
		print_line1(w, w->start, w->end, (w->m.tab[i][j].z < w->m.tab[i - 1][j].z) ? tmp.color : old.color);
	}
}

t_matrice	init_mat_position(t_win *w)
{
	t_matrice   mtmp;

	w->x_mat = set_X_matrice(w->alpha);
	w->y_mat = set_Y_matrice(w->beta);
	w->z_mat = set_Z_matrice(w->ceta);
	w->t_mat = set_T_matrice(w->t_x, w->t_y, w->t_z);
	w->screen_mat = set_zoom_matrice(w->zoom);
	w->center_mat = set_T_matrice(w->m.xmax/-2, w->m.ymax/-2, w->m.zmax/-2);
	mtmp = mult_matrice(w->center_mat, w->x_mat);
	mtmp = mult_matrice(w->y_mat, mtmp);
	mtmp = mult_matrice(w->z_mat, mtmp);
	mtmp = mult_matrice(w->screen_mat, mtmp);
	mtmp = mult_matrice(w->t_mat, mtmp);
	return (mtmp);
}

void		init_map(t_win *w)
{
	int			i;
	int			j;
	t_vertex	tmp;
	t_matrice   mtmp;

	i = 0;
	mtmp = init_mat_position(w);
	while (i < w->m.ymax)
	{
		j = 0;
		while (j < w->m.xmax)
		{
			draw_to_img(w, mtmp, i, j);
			j = j + 1;
		}
		i = i + 1;
	}
}
