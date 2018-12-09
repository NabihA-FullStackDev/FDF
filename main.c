/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2018/12/09 15:46:42 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int		deal_key(int key, void *ptr)
{
	if (ptr != (void*)53)
		printf("%d\n, %s", key, ptr);
	else
		exit(0);
	return (0);
}

int		main()
{
	float		x;
	float		y;
	void	*mlx_ptr;
	void	*win_ptr;

	x = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Test");
	while (x < 800)
	{
		y = 0;
		while (y < 600)
		{
			if ((x <= 400 + 50 && x >= 400 - 50) && (y == 300 + 50 || y == 300 - 50))
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
			if ((y <= 300 + 50 && y >= 300 - 50) && (x == 400 + 50 || x == 400 - 50))
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF00);
			y++;
		}
		x = x + 1;
	}
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	mlx_loop(mlx_ptr);
	return (0);
}












