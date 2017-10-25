#include "fdf.h"

float ft_fl_abs(float num)
{
	num *= ((num > 0) - (num < 0));
	return (num);
}

void	drawpoint(t_win *win, t_bresen *bres)
{
	bres->yw = win->h - bres->y;
	mlx_pixel_put(win->mlx, win->win, bres->x, bres->yw, 0x00FF00FF);
}

void	positivize(t_bresen *bres, int flag)
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
/*we can only draw in the case that m <= 1
this makes sure that it is and then ensures
that the line is drawn from small to big
along either x or y depending on if it's
steep or shallow*/

static void	initbres_help(t_bresen *bres)
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

/*Initialize all the things*/
t_bresen	*initbres(t_point *p1, t_point *p2)
{
	t_bresen	*bres;

	bres = (t_bresen*)malloc(sizeof(t_bresen));
	bres->x = p1->x;
	bres->y = p1->y;
	bres->x1 = p1->x;
	bres->x2 = p2->x;
	bres->y1 = p1->y;
	bres->y2 = p2->y;
	bres->rise = bres->y2 - bres->y1;
	bres->run = bres->x2 - bres->x1;
	if (bres->run == 0 && (bres->flip = 2))
		return bres;
	bres->threshold = .5;
	bres->thresholdinc = 1;
	bres->offset = 0;
	bres->slope = 1;
	bres->m = bres->rise / bres->run;
	bres->adjust = bres->m > 0 ? 1 : -1;
	initbres_help(bres);
	bres->m = ft_fl_abs(bres->m);
	return bres;
}

static void	drawline_h0(t_win *win, t_bresen *bres)
{
	while (bres->x < bres->x2 + 1)
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
	while (bres->y < bres->y2 + 1)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->x += bres->adjust))
			bres->threshold += bres->thresholdinc;
	bres->y++;
	}
}

/*handles cases where there is a hl vertical
basicly positivise(bres, 0) but to include it
would make stuff convoluted*/
static void	flip(t_bresen *bres)
{
	int tmp;
	if(bres->y1 > bres->y2)
	{
		tmp = bres->y1;
		bres->y1 = bres->y2;
		bres->y2 = tmp;
		bres->y = bres->y1;
	}
}

/*draws verticals, pawns off steeps to drawline_h1
and shallows to drawline_h0*/

void	draw_line(t_point *p1, t_point *p2, t_win *win)
{
	t_bresen *bres;

	bres = initbres(p1, p2);
	if (bres->flip == 0)
		drawline_h0(win, bres);
	else if (bres->flip == 1)
		drawline_h1(win, bres);
	else if (bres->flip == 2)
	{
		flip(bres);
		while (bres->y < bres->y2 + 1)
		{
			drawpoint(win, bres);
			bres->y++;
		}
	}
}

/*
Steep lh
	t_point *p1 = init_point(100, 100, 100, 0);
	t_point *p2 = init_point(95, 200, 100, 0);
Steep hl
	t_point *p1 = init_point(95, 200, 100, 0);
	t_point *p2 = init_point(100, 100, 100, 0);
shallow hl
	t_point *p1 = init_point(100, 100, 100, 0);
	t_point *p2 = init_point(400, 120, 100, 0);
Shallow lh
	t_point *p2 = init_point(400, 120, 100, 0);
	t_point *p2 = init_point(100, 100, 100, 0);
vertical lh
	t_point *p2 = init_point(100, 100, 100, 0);
	t_point *p2 = init_point(100, 200, 100, 0);
vertical hl
	t_point *p2 = init_point(100, 200, 100, 0);
	t_point *p2 = init_point(100, 100, 100, 0);
horiz lh
	t_point *p2 = init_point(100, 100, 100, 0);
	t_point *p2 = init_point(200, 100, 100, 0);
one lh
	t_point *p2 = init_point(100, 100, 100, 0);
	t_point *p2 = init_point(200, 200, 100, 0);
one hl
	t_point *p2 = init_point(200, 200, 100, 0);
	t_point *p2 = init_point(100, 100, 100, 0);
*/
