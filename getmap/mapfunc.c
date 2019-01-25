/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:24:08 by naali             #+#    #+#             */
/*   Updated: 2019/01/25 13:47:44 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/get_next_line.h"
#include "../includes/fdf.h"
#include "../includes/t_struct.h"

static t_vertex		*split_nb_to_tab2(t_map *m, char **line, int i, int *lizi)
{
	int			j;
	t_vertex	*tabnb;

	*lizi = 0;
	if ((tabnb = (t_vertex*)malloc(sizeof(t_vertex)\
			* (*lizi = tablen((const char**)line)))) == NULL)
		return (NULL);
	j = 0;
	while (j < *lizi)
	{
		tabnb[j] = init_vtex((double)j, (double)i, \
							(double)ft_atoi(line[j]), \
							 color_choice(ft_atoi(line[j])));
		if (m->zmax < ft_atoi(line[j]))
			m->zmax = ft_atoi(line[j]);
		j = j + 1;
	}
	if (m->xmax < j && i == 0)
		m->xmax = j;
	else if (i > 0 && m->xmax != j)
	{
		free_useless(&line, NULL, *lizi);
		exit(-1);
	}
	return (tabnb);
}

static t_vertex		**split_nb_to_tab1(char **tab, t_map *m)
{
	int			i;
	int			lizi;
	char		**line;
	t_vertex	**tabnb;

	i = 0;
	line = NULL;
	if ((tabnb = (t_vertex**)malloc(sizeof(t_vertex*)\
					* tablen((const char**)tab))) == NULL)
		return (NULL);
	while (tab[i] != 0)
	{
		line = ft_strsplit(tab[i], ' ');
		tabnb[i] = split_nb_to_tab2(m, line, i, &lizi);
		free_useless(&line, NULL, lizi);
		i = i + 1;
	}
	if (m->ymax < i)
		m->ymax = i;
	free_useless(&line, NULL, lizi);
	free_useless(&tab, NULL, tablen((const char**)tab));
	return (tabnb);
}

void				file_to_tab(char *path, t_map *m)
{
	m->xmax = 0;
	m->ymax = 0;
	m->zmax = 0;
	m->tbline = NULL;
	if ((m->fd = open(path, O_RDONLY)) == -1 || m->fd == 0)
	{
		printf("%s est invalide\n", path);
		return ;
	}
	while (get_next_line(m->fd, &(m->line)) > 0)
	{
		m->tbline = ft_pushback_str_to_tab(&(m->tbline), &(m->line));
		m->nbl++;
	}
	m->tab = split_nb_to_tab1(m->tbline, m);
	if (m->line != NULL)
		free(m->line);
	if (m->fd > 0)
		close(m->fd);
}
