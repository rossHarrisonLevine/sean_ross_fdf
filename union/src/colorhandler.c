/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:21:40 by sjones            #+#    #+#             */
/*   Updated: 2017/11/08 15:22:18 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_h0(t_bresen *bres)
{
	if (bres->dr > 0)
		bres->r = ABS((bres->dr * (bres->x1 - (float)bres->x)) / bres->run);
	else if (bres->dr < 0)
		bres->r = ABS((bres->dr * (bres->x2 - (float)bres->x)) / bres->run);
	if (bres->dg > 0)
		bres->g = ABS((bres->dg * (bres->x1 - (float)bres->x)) / bres->run);
	else if (bres->dg < 0)
		bres->g = ABS((bres->dg * (bres->x2 - (float)bres->x)) / bres->run);
	if (bres->db > 0)
		bres->b = ABS((bres->db * (bres->x1 - (float)bres->x)) / bres->run);
	else if (bres->db < 0)
		bres->b = ABS((bres->db * (bres->x1 - (float)bres->x)) / bres->run);
}

static void	color_h1(t_bresen *bres)
{
	if (bres->dr > 0)
		bres->r = ABS((bres->dr * (bres->y1 - (float)bres->y)) / bres->rise);
	else if (bres->dr < 0)
		bres->r = ABS((bres->dr * (bres->y2 - (float)bres->y)) / bres->rise);
	if (bres->dg > 0)
		bres->g = ABS((bres->dg * (bres->y1 - (float)bres->y)) / bres->rise);
	else if (bres->dg < 0)
		bres->g = ABS((bres->dg * (bres->y2 - (float)bres->y)) / bres->rise);
	if (bres->db > 0)
		bres->b = ABS((bres->db * (bres->y1 - (float)bres->y)) / bres->rise);
	else if (bres->db < 0)
		bres->b = ABS((bres->db * (bres->y2 - (float)bres->y)) / bres->rise);
}

void		color_diff(t_bresen *bres)
{
	bres->r = GET_R(bres->color);
	bres->g = GET_G(bres->color);
	bres->b = GET_B(bres->color);
	if (bres->flip == 0)
		color_h0(bres);
	else
		color_h1(bres);
	bres->color = GET_C((int)bres->r, (int)bres->g, (int)bres->b);
}
