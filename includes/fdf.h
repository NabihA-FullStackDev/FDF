/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:27 by naali             #+#    #+#             */
/*   Updated: 2019/02/06 18:41:41 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ZPIX 4
# define WINX 1600
# define WINY 1200
# define EYEX WINX/2
# define EYEY WINY/2
# define ALPHA 45
# include "t_struct.h"

typedef struct		s_sgmt
{
	double			dx;
	double			dy;
	double			error;
	int				ystep;
	int				x;
	int				y;
	int				maxx;
}					t_sgmt;

typedef struct		s_map
{
	int			fd;
	int			xmax;
	int			ymax;
	int			zmax;
	int			nbl;
	char		*line;
	char		**tbline;
	t_vertex	**tab;
	t_matrice	mat;
}					t_map;

typedef struct		s_img
{
	void		*imgp;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_win
{
	int			x;
	int			y;
	void		*mlxp;
	void		*winp;
	t_img		simg;
	t_map		m;
	float		xt;
	float		yt;
	float		rot;
	double		alpha;
	double		beta;
	double		ceta;
	double		t_x;
	double		t_y;
	double		t_z;
	double		zoom;
	t_vect		start;
	t_vect		end;
	int			color;
	int			c_start;
	int			c_end;
	int			z_start;
	int			z_end;
	int			cstep;
	t_matrice	x_mat;
	t_matrice	y_mat;
	t_matrice	z_mat;
	t_matrice	t_mat;
	t_matrice	screen_mat;
	t_matrice	center_mat;
}					t_win;

void				init_map(t_win *w);
int					file_to_tab(char *path, t_map *m);
int					tablen(const char **tab);
void				free_useless(char ***tab, char **s1, int tmax);
char				**ft_pushback_str_to_tab(char ***tab, char **s1);
int					color_choice(int z);
void				print_line1(t_win *w, t_vect start, t_vect end);
void				put_color_to_pix(t_win *w, t_vertex vtx);
int					color_choice(int z);
int					deal_with_keyboard(int key, void *ptr);
void				refresh_screen(t_win *win);

#endif
