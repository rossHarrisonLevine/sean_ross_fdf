#include "fdf.h"

float ft_fl_abs(float num)
{
	num *= ((num > 0) - (num < 0));
	return (num);
}

void	drawpoint(t_env *win, t_bresen *bres)
{
	bres->yw = win->h - bres->y1;
	mlx_pixel_put(win->mlx, win->win, bres->x1, bres->yw, 0x00FF00FF);
}

void	positivize(t_bresen *bres, int flag)
{
	int tmp;

	if (bres->x2 < bres->x1 && flag == 0)
	{
		tmp = bres->x1;
		bres->x1 = bres->x2;
		bres->x2 = tmp;
	}
	if (bres->y2 < bres->y1 && flag == 1)
	{
		tmp = bres->y1;
		bres->y1 = bres->y2;
		bres->y2 = tmp;
	}
}

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

static void	flip(t_bresen *bres)
{
	int tmp;

	tmp = bres->y1;
	bres->y1 = bres->y2;
	bres->y2 = tmp;
	tmp = bres->x1;
	bres->x1 = bres->x2;
	bres->x2 = tmp;
}

t_bresen	*initbres(t_point *p1, t_point *p2)
{
	t_bresen	*bres;

	bres = (t_bresen*)malloc(sizeof(t_bresen));
	bres->threshold = .5;
	bres->thresholdinc = 1;
	bres->offset = 0;
	bres->slope = 1;
	bres->x1 = p1->x;
	bres->y1 = p1->y;
	bres->x2 = p2->x;
	bres->y2 = p2->y;
	if (bres->y2 < bres->y1)
		flip(bres);
	bres->rise = bres->y2 - bres->y1;
	bres->run = bres->x2 - bres->x1;
	if (bres->run == 0 && (bres->flip = 2))
		return bres;
	bres->m = bres->rise / bres->run;
	bres->adjust = bres->m > 0 ? 1 : -1;
	initbres_help(bres);
	return bres;
}

static void	drawline_h0(t_env *win, t_bresen *bres)
{
	while (bres->x1 < bres->x2 + 1)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->y1 += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->x1++;
	}
}

static void	drawline_h1(t_env *win, t_bresen *bres)
{
	while (bres->y1 < bres->y2 + 1)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->x1 += bres->adjust))
			bres->threshold += bres->thresholdinc;
	bres->y1++;
	}
}

void	drawline(t_point *p1, t_point *p2, t_env *win)
{
	t_bresen *bres;

	bres = initbres(p1, p2);
	bres->m = ft_fl_abs(bres->m);
	if (bres->flip == 0)
		drawline_h0(win, bres);
	else if (bres->flip == 1)
		drawline_h1(win, bres);
	else if (bres->flip == 2)
	{
		while (bres->y1 < bres->y2 + 1)
		{
			drawpoint(win, bres);
			bres->y1++;
		}
	}
}

int main(void)
{
	t_env	*win;
	t_point *p1 = init_point(200, 100, 100, 0);
	t_point *p2 = init_point(150, 200, 100, 0);
	win = (t_env*)malloc(sizeof(t_env));
	win->tit = "I'm Mister Window, look at me!";
	win->mlx = mlx_init();
	win->h = 400;
	win->w = 500;
	win->win = mlx_new_window(win->mlx, win->w, win->h, win->tit);
	drawline(p1, p2, win);
	mlx_loop(win->mlx);
}
