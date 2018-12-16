/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:12:58 by naali             #+#    #+#             */
/*   Updated: 2018/12/16 16:28:41 by naali            ###   ########.fr       */
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
	int		i;
	int		j;

	i = 0;
	while (i < w->m.ymax)
	{
		j = 0;
		while (j < w->m.xmax)
		{
			w->m.tab[i][j] = mult_vtex_by_mat(set_X_matrice(-60), w->m.tab[i][j]);
//			w->m.tab[i][j] = mult_vtex_by_mat(set_X_matrice(45), w->m.tab[i][j]);
//			w->m.tab[i][j] = mult_vtex_by_mat(set_Y_matrice(3), w->m.tab[i][j]);
//			w->m.tab[i][j] = mult_vtex_by_mat(set_Z_matrice(20), w->m.tab[i][j]);
			w->m.tab[i][j] = mult_vtex_by_mat(set_zoom_matrice(5), w->m.tab[i][j]);
			w->m.tab[i][j] = mult_vtex_by_mat(set_T_matrice(200, 150, 0), w->m.tab[i][j]);
			if (w->m.tab[i][j].z < 10 && w->m.tab[i][j].z > -10)
				w->simg.data[(int)(((w->m.tab[i][j].y - (w->m.tab[i][j].z * 0.1)) * WINX) + w->m.tab[i][j].x)] = 0x0000FF;
			else if (w->m.tab[i][j].z >= 10 || w->m.tab[i][j].z <= -10)
				w->simg.data[(int)(((w->m.tab[i][j].y - (w->m.tab[i][j].z * 0.1)) * WINX) + w->m.tab[i][j].x)] = 0xFF0000;
//				w->simg.data[(int)((w->m.tab[i][j].y * WINX) + w->m.tab[i][j].x)] = 0xFF0000;
			j = j + 1;
		}
		i = i + 1;
	}
}
