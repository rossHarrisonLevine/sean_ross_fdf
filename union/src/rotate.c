/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:41:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/03 16:43:56 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *point, int dir)
{
	float	y;
	float	z;

	while (point)
	{
		z = point->z;
		y = point->y;
		point->y = dir * ((y * cos(TH)) - (z * sin(TH)));
		point->z = dir * ((z * cos(TH)) + (y * sin(TH)));
		point = point->right;
	}
}

static void	rotate_y(t_point *point, int dir)
{
	float	x;
	float	z;

	while (point)
	{
		x = point->x;
		z = point->z;
		point->x = dir * ((x * cos(TH)) + (z * sin(TH)));
		point->z = dir * (-(x * sin(TH)) + (z * cos(TH)));
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
		point->x = dir * ((x * cos(TH)) + (y * sin(TH)));
		point->y = dir * ((y * cos(TH) - (x * sin(TH))));
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
			rotate_x(row, dir);
		if (c == 'y')
			rotate_y(row, dir);
		if (c == 'z')
			rotate_z(row, dir);
		tmp = tmp->down;
	}
}
