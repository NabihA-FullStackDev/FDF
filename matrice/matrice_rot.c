/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:48:06 by naali             #+#    #+#             */
/*   Updated: 2018/12/16 16:06:13 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/t_struct.h"

t_matrice		set_X_matrice(double degree)
{
	t_matrice	matrice;
	double		radian;

	radian = conv_deg_to_rad(degree);
	matrice.tab[0][0] = 1;
	matrice.tab[0][1] = 0;
	matrice.tab[0][2] = 0;
	matrice.tab[0][3] = 0;

	matrice.tab[1][0] = 0;
	matrice.tab[1][1] = cos(radian);
	matrice.tab[1][2] = sin(radian);
	matrice.tab[1][3] = 0;

	matrice.tab[2][0] = 0;
	matrice.tab[2][1] = -sin(radian);
	matrice.tab[2][2] = cos(radian);
	matrice.tab[2][3] = 0;

	matrice.tab[3][0] = 0;
	matrice.tab[3][1] = 0;
	matrice.tab[3][2] = 0;
	matrice.tab[3][3] = 1;
	return (matrice);
}

t_matrice		set_Y_matrice(double degree)
{
	t_matrice	matrice;
	double		radian;

	radian = conv_deg_to_rad(degree);
	matrice.tab[0][0] = cos(radian);
	matrice.tab[0][1] = 0;
	matrice.tab[0][2] = -sin(radian);
	matrice.tab[0][3] = 0;

	matrice.tab[1][0] = 0;
	matrice.tab[1][1] = 1;
	matrice.tab[1][2] = 0;
	matrice.tab[1][3] = 0;

	matrice.tab[2][0] = sin(radian);
	matrice.tab[2][1] = 0;
	matrice.tab[2][2] = cos(radian);
	matrice.tab[2][3] = 0;

	matrice.tab[3][0] = 0;
	matrice.tab[3][1] = 0;
	matrice.tab[3][2] = 0;
	matrice.tab[3][3] = 1;
	return (matrice);
}

t_matrice		set_Z_matrice(double degree)
{
	double		radian;
	t_matrice	matrice;

	radian = conv_deg_to_rad(degree);
	matrice.tab[0][0] = cos(radian);
	matrice.tab[0][1] = sin(radian);
	matrice.tab[0][2] = 0;
	matrice.tab[0][3] = 0;

	matrice.tab[1][0] = -sin(radian);
	matrice.tab[1][1] = cos(radian);
	matrice.tab[1][2] = 0;
	matrice.tab[1][3] = 0;

	matrice.tab[2][0] = 0;
	matrice.tab[2][1] = 0;
	matrice.tab[2][2] = 1;
	matrice.tab[2][3] = 0;

	matrice.tab[3][0] = 0;
	matrice.tab[3][1] = 0;
	matrice.tab[3][2] = 0;
	matrice.tab[3][3] = 1;
	return (matrice);
}
