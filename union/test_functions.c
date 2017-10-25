/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 22:09:53 by sjones            #+#    #+#             */
/*   Updated: 2017/10/25 12:06:54 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_row(t_point *point)
{
	while (point)
	{
		printf("{%f, %f, %f},{%ld}", \
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
