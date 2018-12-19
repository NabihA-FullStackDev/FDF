/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:12:58 by naali             #+#    #+#             */
/*   Updated: 2018/12/19 15:10:34 by naali            ###   ########.fr       */
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
#include "includes/t_struct.h"

void		init_map(t_win *w)
{
	int			i;
	int			j;
	t_vertex	tmp;
	t_matrice   x_mat;
	t_matrice   y_mat;
	t_matrice   z_mat;
	t_matrice   t_mat;
	t_matrice   screen_mat;
	t_matrice   center_mat;

	i = 0;
	x_mat = set_X_matrice(w->alpha);
	y_mat = set_Y_matrice(w->beta);
	z_mat = set_Z_matrice(w->ceta);
	t_mat = set_T_matrice(200, 150, 0);
	screen_mat = set_zoom_matrice(2);
	center_mat = set_T_matrice(w->m.xmax/-2, w->m.ymax/-2, 0);
	while (i < w->m.ymax)
	{
		j = 0;
		while (j < w->m.xmax)
		{
			tmp = w->m.tab[i][j];
//			tmp = mult_vtex_by_mat(set_X_matrice(w->alpha), w->m.tab[i][j]);
//			printf("x=%f, y=%f, z=%f\n", tmp.x, tmp.y, tmp.z);
			tmp = mult_vtex_by_mat(center_mat, tmp);
			tmp = mult_vtex_by_mat(x_mat, tmp);
			tmp = mult_vtex_by_mat(y_mat, tmp);
			tmp = mult_vtex_by_mat(z_mat, tmp);
			tmp = mult_vtex_by_mat(screen_mat, tmp);
			tmp = mult_vtex_by_mat(t_mat, tmp);
//			printf("%f\n", tmp.x);
			if (((((int)tmp.y - (int)(tmp.z * 0.1)) * WINX) + (int)tmp.x > 0)\
	&& ((((int)tmp.y - (int)(tmp.z * 0.1)) * WINX) + (int)tmp.x < WINX * WINY)\
	&& (((int)tmp.y - (int)(tmp.z * 0.1)) * WINX + (int)tmp.x) / WINX == (int)tmp.y - (int)(tmp.z * 0.1))
			{
				if (w->m.tab[i][j].z < 10 && w->m.tab[i][j].z > -10)
					w->simg.data[((((int)tmp.y - (int)(tmp.z * 0.1)) * WINX) + (int)tmp.x)] = 0xFFFFFF;
				else
					w->simg.data[((((int)tmp.y - (int)(tmp.z * 0.1)) * WINX) + (int)tmp.x)] = 0xFF0000;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
