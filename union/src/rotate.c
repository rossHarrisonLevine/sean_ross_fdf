/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:41:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/07 17:10:05 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static void	rotate_x(t_point *point, int dir, double theta, float my)
{
	float	y;
	float	z;

	while (point)
	{
		z = point->z;
		y = point->y;
		point->y = ((y * cos(dir * theta)) - (z * sin(dir * theta)) \
			+ ((1 - cos(dir * theta)) * my));
		point->z = ((z * cos(dir * theta)) + (y * sin(dir * theta)) \
			+ sin(dir * theta) * my);
		point = point->right;
	}
}

static void	rotate_y(t_point *point, int dir, double theta, float mx)
{
	float	x;
	float	z;

	while (point)
	{
		x = point->x;
		z = point->z;
		point->x = ((x * cos(theta * dir)) + (z * sin(theta * dir)) \
			+ ((1 - cos(dir * theta)) * mx));
		point->z = (-(x * sin(theta * dir)) + (z * cos(theta * dir)) \
			- sin(dir * theta) * mx);
		point = point->right;
	}
}

static void	rotate_z(t_point *point, int dir, double theta)
{
	float x;
	float y;

	while (point)
	{
		x = point->x;
		y = point->y;
		point->x = ((x * cos(theta * dir)) + (y * sin(theta * dir)));
		point->y = ((y * cos(theta * dir) - (x * sin(theta * dir))));
		point = point->right;
	}
}

void		rotate(char c, int dir, double theta, t_map *map)
{
	t_point	*tmp;
	t_point	*row;

	tmp = map->map;
	getmidval(map);
	while (tmp)
	{
		row = tmp;
		if (c == 'x')
			rotate_x(row, dir, theta, map->mx);
		if (c == 'y')
			rotate_y(row, dir, theta, map->my);
		if (c == 'z')
			rotate_z(row, dir, theta);
		tmp = tmp->down;
	}
}
