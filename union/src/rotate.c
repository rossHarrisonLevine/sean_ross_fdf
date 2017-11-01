/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:41:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/01 15:42:37 by sjones           ###   ########.fr       */
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
		point->y = dir * ((y * cos(30)) + (z * sin(30)));
		point->z = dir * ((z * cos(30) - (y * sin(30))));
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
		point->x = dir * ((x * cos(30)) - (z * sin(30)));
		point->z = dir * ((x * sin(30) + (z * cos(30))));
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
		point->x = dir * ((x * cos(30)) + (y * sin(30)));
		point->y = dir * ((y * cos(30) - (x * sin(30))));
		point = point->right;
	}
}

void		rotate(char c, int dir, t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
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
