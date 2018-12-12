/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:27 by naali             #+#    #+#             */
/*   Updated: 2018/12/12 19:29:50 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINX 800
# define WINY 600

# define EYEX WINX/2
# define EYEY WINY/2
# define EYEZ 200

# define FLG 123
# define FLD 124
# define FLB 125
# define FLH 126

# define ESC 53

typedef enum		e_keys
{
	fg,
	fd,
	fb,
	fh,
	esc
}					te_keys;

typedef struct		s_vertex
{
	float		x;
	float		y;
	float		z;
}					t_vertex;

typedef struct		s_map
{
	int			fd;
	int			xmax;
	int			ymax;
	int			nbl;
	char		*line;
	char		**tbline;
	int			**tab;
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
	t_vertex	vec[3];
	float		xt;
	float		yt;
	float		rot;
	te_keys		keys;
}					t_win;

void			file_to_tab(char *path, t_map *m);
int				tablen(const char **tab);
void			free_useless(char ***tab, char **s1, int tmax);
char			**ft_pushback_str_to_tab(char ***tab, char **s1);

#endif
