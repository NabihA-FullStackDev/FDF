/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:24:08 by naali             #+#    #+#             */
/*   Updated: 2018/12/10 19:31:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/get_next_line.h"
#include "includes/fdf.h"

int		**split_nb_to_tab(char **tab, t_map *m)
{
	int		i;
	int		j;
	char	**line;
	int		lizi;
	int		**tabnb;

	i = 0;
	line = NULL;
	lizi = 0;
	if ((tabnb = (int**)malloc(sizeof(int*) * tablen((const char**)tab))) == NULL)
		return (NULL);
	while (tab[i] != 0)
	{
		line = ft_strsplit(tab[i], ' ');
		if ((tabnb[i] = malloc(sizeof(int) * (lizi = tablen((const char**)line)))) == NULL)
			return (NULL);
		j = 0;
		while (j < lizi)
		{
			tabnb[i][j] = ft_atoi(line[j]);
			j = j + 1;
			if (m->xmax < j)
				m->xmax = j;
		}
		free_useless(&line, NULL, lizi);
		i = i + 1;
	}
	if (m->ymax < i)
		m->ymax = i;
	free_useless(&line, NULL, lizi);
	free_useless(&tab, NULL, tablen((const char**)tab));
	return (tabnb);
}

void	file_to_tab(char *path, t_map *m)
{
	m->xmax = 0;
	m->ymax = 0;
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
	m->tab = split_nb_to_tab(m->tbline, m);
	if (m->line != NULL)
		free(m->line);
	if (m->fd > 0)
		close(m->fd);
}
