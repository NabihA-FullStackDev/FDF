/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmnt_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:09:53 by naali             #+#    #+#             */
/*   Updated: 2019/01/25 16:16:02 by naali            ###   ########.fr       */
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

void		init_sgmt(t_sgmt *l, int swp, t_vect start, t_vect end)
{
	l->dx = end.x - start.x;
	l->dy = fabs(end.y - start.y);
	l->error = l->dx / 2.0f;
	l->ystep = (start.y < end.y) ? 1 : -1;
	l->x = (int)(start.x);
	l->y = (int)(start.y);
	l->maxX = (int)(end.x);
}

void		change_vect(int swp, t_vect *start, t_vect *end)
{
	double	tmp;

	if (swp >= 0)
	{
		refresh_vect(start, start->y, start->x);
		refresh_vect(end, end->y, end->x);
	}
	if (start->x > end->x)
	{
		tmp = start->x;
		start->x = end->x;
		end->x = tmp;
		tmp = start->y;
		start->y = end->y;
		end->y = tmp;
	}
}

void		print_line2(t_win *w, int swp, t_vect start, t_vect end)
{
	int		color;
	t_sgmt	l;

	color = w->color;
	init_sgmt(&l, swp, start, end);
	while (l.x < l.maxX)
	{
		if (swp >= 0)
			put_color_to_pix(w, init_vtex(l.y, l.x, 0, color));
		else
			put_color_to_pix(w, init_vtex(l.x, l.y, 0, color));
		l.error = l.error - l.dy;
		if (l.error < 0)
		{
			l.y += l.ystep;
			l.error = l.error + l.dx;
//			color = color_choice(fabs((end.y - l.y)/0.1));
		}
		l.x++;
	}
}

void		print_line1(t_win *w, t_vect start, t_vect end, int color)
{
	int		swp;

	swp = (int)(fabs(end.y - start.y) - fabs(end.x - start.x));
	change_vect(swp, &start, &end);
	w->color = color;
	print_line2(w, swp, start, end);
}
