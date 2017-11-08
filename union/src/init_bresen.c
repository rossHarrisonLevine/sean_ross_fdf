/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bresen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:28:00 by sjones            #+#    #+#             */
/*   Updated: 2017/11/08 15:17:21 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_fl_abs(float num)
{
	num *= ((num > 0) - (num < 0));
	return (num);
}

static void		positivize(t_bresen *bres, int flag)
{
	int tmp;

	if (flag == 0)
	{
		tmp = bres->x1;
		bres->x1 = bres->x2;
		bres->x2 = tmp;
		bres->y = bres->y2;
		bres->x = bres->x1;
	}
	if (flag == 1)
	{
		tmp = bres->y1;
		bres->y1 = bres->y2;
		bres->y2 = tmp;
		bres->x = bres->x2;
		bres->y = bres->y1;
	}
}

/*
** we can only draw in the case that m <= 1
** this makes sure that it is and then ensures
** that the line is drawn from small to big
** along either x or y depending on if it's
** steep or shallow
*/

static void		initbres_help(t_bresen *bres)
{
	if (bres->m <= 1 && bres->m >= -1)
	{
		if (bres->x2 < bres->x1)
			positivize(bres, 0);
		bres->flip = 0;
	}
	else
	{
		bres->m = bres->run / bres->rise;
		if (bres->y2 < bres->y1)
			positivize(bres, 1);
		bres->flip = 1;
	}
}

static void		initbres_color(t_bresen *bres, int col1, int col2)
{
	bres->color = col1;
	bres->dr = (GET_R(col2)) - (GET_R(col1));
	bres->dg = (GET_G(col2)) - (GET_G(col1));
	bres->db = (GET_B(col2)) - (GET_B(col1));
}

t_bresen		*init_bresen(t_point *p1, t_point *p2)
{
	t_bresen	*bres;

	bres = (t_bresen*)malloc(sizeof(t_bresen));
	bres->x = p1->x;
	bres->y = p1->y;
	bres->x1 = p1->x;
	bres->x2 = p2->x;
	bres->y1 = p1->y;
	bres->y2 = p2->y;
	initbres_color(bres, p1->color, p2->color);
	bres->rise = bres->y2 - bres->y1;
	bres->run = bres->x2 - bres->x1;
	if (bres->run == 0 && (bres->flip = 2))
		return (bres);
	bres->threshold = .5;
	bres->thresholdinc = 1;
	bres->offset = 0;
	bres->m = bres->rise / bres->run;
	bres->adjust = bres->m > 0 ? 1 : -1;
	initbres_help(bres);
	bres->m = ft_fl_abs(bres->m);
	return (bres);
}
