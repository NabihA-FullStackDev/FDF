/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_put_choice.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:28:10 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:31:15 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fdf.h"
#include "includes/t_struct.h"

int			color_choice(int z)
{
	if (z < 5)
		return (0x0042FF);
	else if (z >= 10 && z < 20)
		return (0x00FF00);
	else if (z >= 20 && z < 30)
		return (0xFF4200);
	else if (z >= 30)
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
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
		w->simg.data[(y * WINX) + x] = vtx.color;
}
