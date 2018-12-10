/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:27 by naali             #+#    #+#             */
/*   Updated: 2018/12/10 19:34:24 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINX 800
# define WINY 600

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

typedef struct		s_scale
{
	float		xs;
	float		ys;
	float		zs;

	float		xt;
	float		yt;
	float		zt;

	float		xr;
	float		yr;
	float		zr;
}

typedef struct		s_map
{
	int			fd;
	int			xmax;
	int			ymax;
	char		*line;
	char		**tbline;
	int			nbl;
	int			**tab;
	int			xs;
	int			ys;
	int			xt;
	int			yt;
	int			rot;
}					t_map;

typedef struct		s_img
{
	void		*imgp;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_fdf
{
	void		*mlxp;
	void		*winp;
	int			x;
	int			y;
	t_img		simg;
	te_keys		keys;
}					t_fdf;

void			file_to_tab(char *path, t_map *m);
int				tablen(const char **tab);
void			free_useless(char ***tab, char **s1, int tmax);
char			**ft_pushback_str_to_tab(char ***tab, char **s1);

#endif
