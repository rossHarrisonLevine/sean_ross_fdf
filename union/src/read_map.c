/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:39:22 by sjones            #+#    #+#             */
/*   Updated: 2017/10/27 16:04:57 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_num(char *line)
{
	char		tmp[ft_strlen(line)];
	int			i;

	i = 0;
	while (line[i] && line[i] != ',')
	{
		tmp[i] = line[i];
		i++;
	}
	return (ft_atoi(tmp));
}

static long int	get_col(char *line)
{
	int			i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	i++;
	if (!(line[i]))
		return (0xFFFFFF);
	return (strtol(line + i, NULL, 16));
}

static t_point	*make_line(char **l_split, int depth)
{
	t_point		*head;
	t_point		*tmp;
	int			i;

	i = 1;
	tmp = init_point(0, depth, get_num(l_split[0]), get_col(l_split[0]));
	head = tmp;
	while (l_split[i])
	{
		tmp->right = init_point(i, depth,\
			get_num(l_split[i]), get_col(l_split[i]));
		tmp = tmp->right;
		i++;
	}
	return (head);
}

static t_point	*add_line(t_point *head, t_point *new)
{
	t_point		*tmp1;
	t_point		*tmp2;

	if (head == NULL)
		return (new);
	tmp1 = head;
	tmp2 = new;
	while (tmp1->down)
		tmp1 = tmp1->down;
	while (tmp1)
	{
		tmp1->down = tmp2;
		tmp1 = tmp1->right;
		tmp2 = tmp2->right;
	}
	return (head);
}

t_point			*read_map(int fd)
{
	t_point		*head;
	char		*line;
	char		**l_split;
	int			depth;

	head = NULL;
	depth = 0;
	while (get_next_line(fd, &line) > 0)
	{
		l_split = ft_strsplit(line, ' ');
		head = add_line(head, make_line(l_split, depth));
		free(l_split);
		depth++;
	}
	return (head);
}
