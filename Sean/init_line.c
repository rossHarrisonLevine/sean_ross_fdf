/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:23:01 by sjones            #+#    #+#             */
/*   Updated: 2017/03/21 15:00:56 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*init_line(int x1, int y1, int x2, int y2)
{
	t_line	*l;

	if (!(l = malloc(sizeof(t_line))))
		return (NULL);
	l->x = x1;
	l->y = y1;
	l->x1 = x1;
	l->x2 = x2;
	l->y1 = y1;
	l->y2 = y2;
	l->dx = (x2 - x1) > 0 ? (x2 - x1) : (x1 - x2);
	l->dy = (y2 - y1) > 0 ? (y2 - y1) : (y1 - y2);
	l->sx = x1 < x2 ? 1 : -1;
	l->sy = y1 < y2 ? 1 : -1;
	l->e1 = (l->dx > l->dy ? l->dx : -(l->dy)) / 2;
	l->e2 = 0;
	return (l);
}

/*
int		main()
{
	t_line *thing1;
	t_line *thing2;

	thing1 = init_line(2, 4, 4, 5);
	thing2 = init_line(1, 2, 4, 3);
	printf("x1 = %d x2 = %d y1 = %d y2 = %d dx = %d dy = %d m = %f b = %f\n", 
	thing1->x1, thing1->x2, thing1->y1, thing1->y2, thing1->dx, thing1->dy, thing1->m, thing1->b);
	printf("x1 = %d x2 = %d y1 = %d y2 = %d dx = %d dy = %d m = %f b = %f\n", 
	thing2->x1, thing2->x2, thing2->y1, thing2->y2, thing2->dx, thing2->dy, thing2->m, thing2->b);
	return (0);
}*/
