/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:00:04 by sjones            #+#    #+#             */
/*   Updated: 2017/03/22 14:20:38 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
	{
		ft_putendl("can't malloc enought space for map");
		return (NULL);
	}
	if (map)
	{
		if (!(map->data = (int**)malloc(sizeof(int*) * 10000)))
			return (NULL);
		map->max_x = 0;
		map->max_y = 0;
		map->max_z = 0;
	}
	return (map);
}

int		space_cnt(char *s)
{
	int c;
	int i;

	c = 0;
	i = 0;
	if (s)
		while (s[i++])
			if (ft_isdigit(s[i]) == 1 && (s[i + 1] == ' '))
				c++;
	return (c);
}

char	*next_num(char *s)
{
	while (ft_isdigit(*s) == 1)
		s++;
	while (*s == ' ')
		s++;
	return (s);
}

void	init_mapij(t_map *m)
{
	int	i;

	i = 0;
	if (!(m->trans_i = (int**)malloc(sizeof(int*) * m->max_y)))
		return ;
	if (!(m->trans_j = (int**)malloc(sizeof(int*) * m->max_y)))
		return ;
	while (i < m->max_x)
	{
		m->trans_i[i] = ft_memalloc(m->max_x);
		m->trans_j[i] = ft_memalloc(m->max_x);
		i++;
	}
}

t_map	*read_map(int fd)
{
	t_map	*map;
	int 	i;
	int		j;
	char 	*line;

	map = init_map();
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < map->max_y)
	{
		j = 0;
		map->max_x = space_cnt(line) + 1;
		map->data[i] = (int*)malloc(sizeof(int) * map->max_x);
		while (j++ <= map->max_x)
		{
			map->data[i][j] = ft_atoi(line);
			if (map->data[i][j] > map->max_z)
				map->max_z = map->data[i][j];
			line = next_num(line);
		}
		i++;
	}
	map->max_y = i;
	init_mapij(map);
	return (map);
}
