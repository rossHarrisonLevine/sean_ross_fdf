/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:21:40 by sjones            #+#    #+#             */
/*   Updated: 2017/11/06 11:07:27 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_diff(t_bresen *bres)
{
	int r;
	int g;
	int b;

	bres->dr = bres->r2 - bres->r1;
	bres->dg = bres->g2 - bres->g1;
	bres->db = bres->b2 - bres->b1;
	if (bres->flip == 0)
	{
		r = (bres->dr * bres->x) / (bres->x2 - bres->x1);
		g = (bres->dg * bres->x) / (bres->x2 - bres->x1);
		b = (bres->db * bres->x) / (bres->x2 - bres->x1);
	}
	else
	{
		r = (bres->dr * bres->y) / (bres->y2 - bres->y1);
		g = (bres->dg * bres->y) / (bres->y2 - bres->y1);
		b = (bres->db * bres->y) / (bres->y2 - bres->y1);
	}
	bres->color = GET_C(r, g, b);
}
