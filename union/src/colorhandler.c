/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:21:40 by sjones            #+#    #+#             */
/*   Updated: 2017/11/06 14:15:23 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_diff(t_bresen *bres)
{
	float r;
	float g;
	float b;

	r = (float)bres->r1;
	g = (float)bres->g1;
	b = (float)bres->b1;
	if (bres->flip == 0)
	{
		if (bres->dr > 0)
			r = ABS(((float)bres->dr * (bres->x1 - (float)bres->x)) / bres->run);
		else if (bres->dr < 0)
			r = ABS(((float)bres->dr * (bres->x2 - (float)bres->x)) / bres->run);
		if (bres->dg > 0)
			g = ABS(((float)bres->dg * (bres->x1 - (float)bres->x)) / bres->run);
		else if (bres->dg < 0)
			g = ABS(((float)bres->dg * (bres->x2 - (float)bres->x)) / bres->run);
		if (bres->db > 0)
			b = ABS(((float)bres->db * (bres->x1 - (float)bres->x)) / bres->run);
		else if (bres->db < 0)
			b = ABS(((float)bres->db * (bres->x1 - (float)bres->x)) / bres->run);
	}
	else
	{
		if (bres->dr > 0)
			r = ABS(((float)bres->dr * (bres->y1 - (float)bres->y)) / bres->rise);
		else if (bres->dr < 0)
			r = ABS(((float)bres->dr * (bres->y2 - (float)bres->y)) / bres->rise);
		if (bres->dg > 0)
			g = ABS(((float)bres->dg * (bres->y1 - (float)bres->y)) / bres->rise);
		else if (bres->dg < 0)
			g = ABS(((float)bres->dg * (bres->y2 - (float)bres->y)) / bres->rise);
		if (bres->db > 0)
			b = ABS(((float)bres->db * (bres->y1 - (float)bres->y)) / bres->rise);
		else if (bres->db < 0)
			b = ABS(((float)bres->db * (bres->y2 - (float)bres->y)) / bres->rise);
	}
	bres->color = GET_C((int)r, (int)g, (int)b);
}
