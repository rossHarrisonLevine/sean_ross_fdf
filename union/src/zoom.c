/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:14:01 by sjones            #+#    #+#             */
/*   Updated: 2017/11/01 16:30:39 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom_row(float alpha, t_point *point, float mx, float my)
{
	while (point)
	{
		point->x = (alpha * point->x) - (mx * alpha) + mx;
		point->y = (alpha * point->y) - (my * alpha) + my;
		point->z *= alpha;
		point = point->right;
	}
}

void			getmidval(t_map *map)
{
	int			i;
	t_point		*tmp;

	tmp = map->map;
	i = 0;
	while (i < (map->w / 2))
	{
		tmp = tmp->right;
		i++;
	}
	map->mx = tmp->x;
	i = 0;
	while (i < (map->h / 2))
	{
		tmp = tmp->down;
		i++;
	}
	map->my = tmp->y;
}

void			zoom(float mult, t_map *map)
{
	t_point	*tmp;
	t_point	*row;

	if (mult < 1 && map->map->right->x - map->map->x < 1)
		return ;
	tmp = map->map;
	getmidval(map);
	while (tmp)
	{
		row = tmp;
		zoom_row(mult, row, map->mx, map->my);
		tmp = tmp->down;
	}
}
