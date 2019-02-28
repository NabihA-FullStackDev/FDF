/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vertex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:08:50 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 00:19:53 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_struct.h"

t_vertex	init_vtex(double p_x, double p_y, double p_z, int color)
{
	t_vertex	vertex;

	vertex.x = p_x;
	vertex.y = p_y;
	if (p_z > 1000)
		vertex.z = 1000;
	else if (p_z < -1000)
		vertex.z = -1000;
	else
		vertex.z = p_z;
	vertex.color = color;
	return (vertex);
}

void		refresh_vtex(t_vertex *vertex, double p_x, double p_y, double p_z)
{
	vertex->x = p_x;
	vertex->y = p_y;
	if (p_z > 10000)
		vertex->z = 1000;
	else if (p_z < -1000)
		vertex->z = -1000;
	else
		vertex->z = p_z;
}
