/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:52:01 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 09:43:26 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotation_call(int key, t_win *tmp)
{
	if (key == 84)
		(tmp->alpha) = (tmp->alpha) - 5;
	if (key == 91)
		(tmp->alpha) = (tmp->alpha) + 5;
	if (key == 86)
		(tmp->beta) = (tmp->beta) + 5;
	if (key == 88)
		(tmp->beta) = (tmp->beta) - 5;
	if (key == 92)
		(tmp->ceta) = (tmp->ceta) + 5;
	if (key == 89)
		(tmp->ceta) = (tmp->ceta) - 5;
}

static void		translation_call(int key, t_win *tmp)
{
	if (key == 123)
		tmp->t_x = tmp->t_x - 5;
	if (key == 124)
		tmp->t_x = tmp->t_x + 5;
	if (key == 125)
		tmp->t_y = tmp->t_y + 5;
	if (key == 126)
		tmp->t_y = tmp->t_y - 5;
}

static void		zoom_call(int key, t_win *tmp)
{
	if (key == 69)
		tmp->zoom = tmp->zoom + 1;
	if (key == 78)
		tmp->zoom = tmp->zoom - 1;
	if (tmp->zoom > 100)
		tmp->zoom = 100;
	if (tmp->zoom < 0)
		tmp->zoom = 0;
}

static void		iso_plan(t_win *tmp)
{
	static int	flg = 0;

	if (flg == 1)
	{
		tmp->alpha = 45;
		tmp->beta = 0;
		tmp->ceta = -45;
		tmp->zoom = (tmp->m.xmax >= 100) ? 2 : 25;
		flg = 0;
	}
	else
	{
		tmp->alpha = 0;
		tmp->beta = 0;
		tmp->ceta = 0;
		tmp->zoom = (tmp->m.xmax >= 100) ? 2 : 25;
		flg = 1;
	}
}

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == 53)
	{
		mlx_destroy_image(tmp->mlxp, tmp->simg.imgp);
		mlx_destroy_window(tmp->mlxp, tmp->winp);
		exit(0);
	}
	if (key == 84 || key == 91 || key == 86 \
			|| key == 88 || key == 92 || key == 89)
		rotation_call(key, tmp);
	else if (key == 123 || key == 124 \
			|| key == 125 || key == 126)
		translation_call(key, tmp);
	else if (key == 69 || key == 78)
		zoom_call(key, tmp);
	else if (key == 48)
		iso_plan(tmp);
	refresh_screen(tmp);
	return (0);
}
