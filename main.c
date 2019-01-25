/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/01/25 15:58:39 by naali            ###   ########.fr       */
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

void	refresh_screen(t_win *win)
{
	mlx_destroy_image(win->mlxp, win->simg.imgp);
	win->simg.imgp = mlx_new_image(win->mlxp, WINX, WINY);
	win->simg.data = (int*)mlx_get_data_addr(win->simg.imgp, &(win->simg.bpp), &(win->simg.s_l), &(win->simg.endian));
	init_map(win);

	mlx_clear_window (win->mlxp, win->winp);
//		Fonction de tracer
	mlx_put_image_to_window(win->mlxp, win->winp, win->simg.imgp, 0, 0);
}

int		deal_with_keyboard(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == /*ESC*/53)
	{
		/*free les variables*/
		printf("%s, %d\n", "Echap", key);
		exit(0);
	}
	else if (key == 91)
	{
		(tmp->alpha) = (tmp->alpha) + 5;
		refresh_screen(tmp);
	}
	else if (key == 84)
	{
		(tmp->alpha) = (tmp->alpha) - 5;
		refresh_screen(tmp);
	}
	else if (key == 86)
	{
		(tmp->beta) = (tmp->beta) - 5;
		refresh_screen(tmp);
	}
	else if (key == 88)
	{
		(tmp->beta) = (tmp->beta) + 5;
		refresh_screen(tmp);
	}
	else if (key == 83)
	{
		(tmp->ceta) = (tmp->ceta) + 5;
		refresh_screen(tmp);
	}
	else if (key == 89)
	{
		(tmp->ceta) = (tmp->ceta) - 5;
		refresh_screen(tmp);
	}
	else if (key == 123)
	{
		tmp->t_x = tmp->t_x - 1;
		refresh_screen(tmp);
	}
	else if (key == 124)
	{
		tmp->t_x = tmp->t_x + 1;
		refresh_screen(tmp);
	}
	else if (key == 125)
	{
		tmp->t_y = tmp->t_y + 1;
		refresh_screen(tmp);
	}
	else if (key == 126)
	{
		tmp->t_y = tmp->t_y - 1;
		refresh_screen(tmp);
	}
	else if (key == 69)
	{
		tmp->zoom = tmp->zoom + 1;
		refresh_screen(tmp);
	}
	else if (key == 78)
	{
		tmp->zoom = tmp->zoom - 1;
		refresh_screen(tmp);
	}
	else
		printf("%s, %d\n", "Autre", key);
	return (0);
}

void	init_struct_window(t_win *w, char *file)
{
	w->m.nbl = 0;
	w->mlxp = mlx_init();
	w->winp = mlx_new_window(w->mlxp, WINX, WINY, "FDF");
	w->alpha = 0;
	w->beta = 0;
	w->ceta = 0;
	w->t_x = 200;
	w->t_y = 150;
	w->t_z = 42;
	w->zoom = 5;
	file_to_tab(file, &(w->m));
	w->m.mat = init_matrice();
}

int		main(int ac, char **av)
{
	t_win		w;

	if (ac != 2)
	{
		printf("Usage: ./fdf [map]\n");
		return (0);
	}
	init_struct_window(&w, av[1]);
	w.simg.imgp = mlx_new_image(w.mlxp, WINX, WINY);
	w.simg.data = (int*)mlx_get_data_addr(w.simg.imgp,\
					 &(w.simg.bpp), &(w.simg.s_l), &(w.simg.endian));
	init_map(&w);
	mlx_put_image_to_window(w.mlxp, w.winp, w.simg.imgp, 0, 0);
	mlx_hook(w.winp, 2, 1L<<0, deal_with_keyboard, &w);
	mlx_loop(w.mlxp);
	return (0);
}
