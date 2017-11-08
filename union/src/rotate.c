/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:41:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/07 17:05:58 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *point, int dir, float my)
{
	float	y;
	float	z;

	while (point)
	{
		z = point->z;
		y = point->y;
		point->y = ((y * cos(dir * TH)) - (z * sin(dir * TH)) + ((1 - cos(dir * TH)) * my));
		point->z = ((z * cos(dir * TH)) + (y * sin(dir * TH)) + sin(dir * TH) * my);
		point = point->right;
	}
}

static void	rotate_y(t_point *point, int dir, float mx)
{
	float	x;
	float	z;

	while (point)
	{
		x = point->x;
		z = point->z;
		point->x = ((x * cos(TH * dir)) + (z * sin(TH * dir)) + ((1 - cos(dir * TH)) * mx));
		point->z = (-(x * sin(TH * dir)) + (z * cos(TH * dir)) - sin(dir * TH) * mx);
		point = point->right;
	}
}

static void	rotate_z(t_point *point, int dir)
{
	float x;
	float y;

	while (point)
	{
		x = point->x;
		y = point->y;
		point->x = ((x * cos(TH * dir)) + (y * sin(TH * dir)));
		point->y = ((y * cos(TH * dir) - (x * sin(TH * dir))));
		point = point->right;
	}
}

void		rotate(char c, int dir, t_map *map)
{
	t_point	*tmp;
	t_point	*row;

	tmp = map->map;
	getmidval(map);
	while (tmp)
	{
		row = tmp;
		if (c == 'x')
			rotate_x(row, dir, map->mx);
		if (c == 'y')
			rotate_y(row, dir, map->my);
		if (c == 'z')
			rotate_z(row, dir);
		tmp = tmp->down;
	}
}
