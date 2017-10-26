/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:14:01 by sjones            #+#    #+#             */
/*   Updated: 2017/10/26 16:17:28 by rlevine          ###   ########.fr       */
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

static float	getmidval(char wat, t_map *map)
{
	int			i;
	float		ret;
	t_point		*tmp;

	tmp = map->map;
	i = 0;
	if (wat == 'x')
	{
		while (i < (map->w / 2))
		{
			tmp = tmp->right;
			i++;
		}
		ret = tmp->x;
	}
	else
	{
		while (i < (map->h / 2))
		{
			tmp = tmp->down;
			i++;
		}
		ret = tmp->y;
	}
	return (ret);
}

void			zoom(float mult, t_map *map)
{
	t_point	*tmp;
	t_point	*row;
	float	midvalx;
	float	midvaly;

	if (mult < 1 && map->map->right->x - map->map->x < 1)
		return ;
	tmp = map->map;
	midvalx = getmidval('x', map);
	midvaly = getmidval('y', map);
	while (tmp)
	{
		row = tmp;
		zoom_row(mult, row, midvalx, midvaly);
		tmp = tmp->down;
	}
}