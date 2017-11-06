/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:10:05 by sjones            #+#    #+#             */
/*   Updated: 2017/11/06 10:33:08 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_row(t_point *point)
{
	while (point)
	{
		printf("{%f, %f, %f},{%d}", \
			point->x, point->y, point->z, point->color);
		point = point->right;
		if (point)
			printf(" ");
		else
			printf("\n");
	}
}

void		print_map(t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
	while (tmp)
	{
		row = tmp;
		print_row(row);
		tmp = tmp->down;
	}
}

/*
**color shizz
**int r;
**int g;
**int b;
**int clr;
**
**r = 255;
**g = 255;
**b = 15;
**
**clr = r << 16 | g << 8 | b;
*/
