/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:19:23 by sjones            #+#    #+#             */
/*   Updated: 2017/10/28 17:15:54 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** translate will move the map depending on the values
** of x (horizantal) and y (vertical)
*/

static void		translate_row(float x, float y, float z, t_point *point)
{
	while (point)
	{
		point->x += x;
		point->y += y;
		point->z += z;
		point = point->right;
	}
}

void			translate_map(float x, float y, float z, t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
	while (tmp)
	{
		row = tmp;
		translate_row(x, y, z, row);
		tmp = tmp->down;
	}
}
