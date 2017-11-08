/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:21:46 by sjones            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/07 17:02:45 by rlevine          ###   ########.fr       */
=======
/*   Updated: 2017/11/06 11:30:46 by sjones           ###   ########.fr       */
>>>>>>> 23e953a963a2a0b604eaa2540b33d7e2eed71b61
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawpoint(t_win *win, t_bresen *bres)
{
	bres->yw = win->h - bres->y;
<<<<<<< HEAD
	float ny;
	float nx;
	ny = bres->yw - ((win->h) / 2);
	nx = bres->x + ((win->w) / 2);
	//color_diff(bres);
	mlx_pixel_put(win->mlx, win->win, nx, ny, bres->color);
=======
	color_diff(bres);
	mlx_pixel_put(win->mlx, win->win, bres->x, bres->yw, bres->color);
>>>>>>> 23e953a963a2a0b604eaa2540b33d7e2eed71b61
}

static void	drawline_h0(t_win *win, t_bresen *bres)
{
	while (bres->x < bres->x2)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->y += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->x++;
	}
}

static void	drawline_h1(t_win *win, t_bresen *bres)
{
	while (bres->y < bres->y2)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->x += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->y++;
	}
}

/*
** handles cases where there is a hl vertical
** basicly positivise(bres, 0) but to include it
** would make stuff convoluted
*/

static void	flip(t_bresen *bres)
{
	int tmp;

	if (bres->y1 > bres->y2)
	{
		tmp = bres->y1;
		bres->y1 = bres->y2;
		bres->y2 = tmp;
		bres->y = bres->y1;
	}
}

/*
** draws verticals, pawns off steeps to drawline_h1
** and shallows to drawline_h0
*/

void		draw_line(t_point *p1, t_point *p2, t_win *win)
{
	t_bresen *bres;

	bres = init_bresen(p1, p2);
	if (bres->flip == 0)
		drawline_h0(win, bres);
	else if (bres->flip == 1)
		drawline_h1(win, bres);
	else if (bres->flip == 2)
	{
		flip(bres);
		while (bres->y < bres->y2)
		{
			drawpoint(win, bres);
			bres->y++;
		}
	}
	free(bres);
}
