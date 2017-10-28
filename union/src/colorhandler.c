/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:21:40 by sjones            #+#    #+#             */
/*   Updated: 2017/10/28 16:47:11 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_diff(t_bresen *bres)
{
	int	r;
	int	g;
	int	b;

	r = bres->color >> 16;
	b = bres->color << 8 >> 16;
	g = bres->color << 16 >> 16;
	if (bres->flip == 0)
	{
		r += bres->dr / bres->x2 - bres->x;
		bres->dr -= bres->dr / bres->x2 - bres->x;
		g += bres->dg / bres->x2 - bres->x;
		bres->dg -= bres->dg / bres->x2 - bres->x;
		b += bres->db / bres->x2 - bres->x;
		bres->db -= bres->db / bres->x2 - bres->x;
	}
	else
	{
		r += bres->dr / bres->y2 - bres->y;
		bres->dr -= bres->dr / bres->y2 - bres->y;
		g += bres->dg / bres->y2 - bres->y;
		bres->dg -= bres->dg / bres->y2 - bres->y;
		b += bres->db / bres->y2 - bres->y;
		bres->db -= bres->db / bres->y2 - bres->y;
	}
	bres->color = r << 16 & g << 8 & b;
	return (bres->color);
}
