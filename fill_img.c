/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:59:33 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:43:46 by naali            ###   ########.fr       */
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

static void			old_init(t_win *w, t_vertex *old, t_matrice mtmp)
{
	w->z_start = (*old).z;
	*old = mult_vtex_by_mat(w->center_mat, *old);
	*old = mult_vtex_by_mat(mtmp, *old);
	w->start = init_vect((*old).x, ((*old).y - ((*old).z * 0.1)));
	w->c_start = (*old).color;
}

static void			send_to_sgmnt_trace(t_win *w, int i, int j, t_matrice mtmp)
{
	t_vertex	tmp;
	t_vertex	old;

	tmp = w->m.tab[i][j];
	tmp = mult_vtex_by_mat(set_t_matrice(w->m.xmax / -2,\
										w->m.ymax / -2, 0), tmp);
	tmp = mult_vtex_by_mat(mtmp, tmp);
	w->end = init_vect(tmp.x, (tmp.y - (tmp.z * 0.1)));
	if (i > 0)
	{
		old = w->m.tab[i - 1][j];
		old_init(w, &old, mtmp);
		w->c_end = tmp.color;
		print_line1(w, w->start, w->end);
	}
	if (j > 0)
	{
		old = w->m.tab[i][j - 1];
		old_init(w, &old, mtmp);
		w->c_end = tmp.color;
		print_line1(w, w->start, w->end);
	}
}

static void			draw_to_img(t_win *w, t_matrice mtmp, int i, int j)
{
	t_vertex	tmp;

	tmp = w->m.tab[i][j];
	w->z_end = tmp.z;
	tmp = mult_vtex_by_mat(set_t_matrice(w->m.xmax / -2,\
										w->m.ymax / -2, 0), tmp);
	tmp = mult_vtex_by_mat(mtmp, tmp);
	put_color_to_pix(w, tmp);
	send_to_sgmnt_trace(w, i, j, mtmp);
}

static t_matrice	init_mat_position(t_win *w)
{
	t_matrice	mtmp;

	w->x_mat = set_x_matrice(w->alpha);
	w->y_mat = set_y_matrice(w->beta);
	w->z_mat = set_z_matrice(w->ceta);
	w->t_mat = set_t_matrice(w->t_x, w->t_y, w->t_z);
	w->screen_mat = set_zoom_matrice(w->zoom);
	w->center_mat = set_t_matrice(w->m.xmax / -2,\
								w->m.ymax / -2, 0);
	mtmp = init_matrice();
	mtmp = mult_matrice(w->x_mat, mtmp);
	mtmp = mult_matrice(w->y_mat, mtmp);
	mtmp = mult_matrice(w->z_mat, mtmp);
	mtmp = mult_matrice(w->screen_mat, mtmp);
	mtmp = mult_matrice(w->t_mat, mtmp);
	return (mtmp);
}

void				init_map(t_win *w)
{
	int			i;
	int			j;
	t_matrice	mtmp;

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
