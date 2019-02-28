/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_put_choice.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:28:10 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 09:01:43 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			color_choice(int z)
{
	if (z <= 2)
		return (0x00CCFF);
	else if (z > 2 && z <= 10)
		return (0x009900);
	else if (z > 10 && z <= 15)
		return (0x804000);
	else if (z > 15)
		return (0xFFFFFF);
	return (0);
}

void		put_color_to_pix(t_win *w, t_vertex vtx)
{
	int		x;
	int		y;

	x = (int)vtx.x;
	y = ((int)vtx.y - (int)(vtx.z * 0.1));
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) \
			&& ((y * WINX + x) / WINX == y)))
		w->simg.data[(y * WINX) + x] = vtx.color;
}
