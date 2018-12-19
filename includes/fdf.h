/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:27 by naali             #+#    #+#             */
/*   Updated: 2018/12/19 14:14:46 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ZPIX 4

# define WINX 800
# define WINY 600

# define EYEX WINX/2
# define EYEY WINY/2
# define ALPHA 45

# include "t_struct.h"

typedef struct		s_map
{
	int			fd;
	int			xmax;
	int			ymax;
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
}					t_win;

void			init_map(t_win *w);
t_vertex		*split_nb_to_tab2(t_map *m, char **line, int i, int *lizi);
t_vertex		**split_nb_to_tab1(char **tab, t_map *m);
void			file_to_tab(char *path, t_map *m);
int				tablen(const char **tab);
void			free_useless(char ***tab, char **s1, int tmax);
char			**ft_pushback_str_to_tab(char ***tab, char **s1);

#endif
