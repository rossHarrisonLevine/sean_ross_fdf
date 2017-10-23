#include "fdf.h"
#include "./libft/libft.h"
#include <stdio.h>

float ft_fl_abs(float num)
{
	num *= ((num > 0) - (num < 0));
	return (num);
}

void	drawpoint(t_env *win, t_bresen *bres)
{
	bres->yw = win->h - bres->y;
	mlx_pixel_put(win->mlx, win->win, bres->x, bres->yw, 0x00FF00FF);
}

void	positivize(t_env *win, int flag)
{
	if (win->x2 < win->x1 && flag == 0)
	{
		win->tmp = win->x1;
		win->x1 = win->x2;
		win->x2 = win->tmp;
	}
	if (win->y2 < win->y1 && flag == 1)
	{
		win->tmp = win->y1;
		win->y1 = win->y2;
		win->y2 = win->tmp;
	}
}

static void	initbres_help(t_bresen *bres, t_env *win)
{
	if (win->m <= 1 && win->m >= -1)
	{
		if (win->x2 < win->x1)
		{
			positivize(win, 0);
			bres->y = win->y2;
			bres->x = win->x1;
		}
		bres->flip = 0;
	}
	else
	{
		win->m = win->run / win->rise;
		if (win->y2 < win->y1)
		{
			positivize(win, 1);
			bres->x = win->x2;
			bres->y = win->y1;
		}
		bres->flip = 1;
	}
}

static void	flip(t_env *win)
{
	int tmp;

	tmp = win->y1;
	win->y1 = win->y2;
	win->y2 = tmp;
	tmp = win->x1;
	win->x1 = win->x2;
	win->x2 = tmp;
}

t_bresen	*initbres(t_env *win)
{
	t_bresen	*bres;

	bres = (t_bresen*)malloc(sizeof(t_bresen));
	if (win->y2 < win->y1)
		flip(win);
	bres->threshold = .5;
	bres->thresholdinc = 1;
	bres->offset = 0;
	bres->slope = 1;
	win->rise = win->y2 - win->y1;
	win->run = win->x2 - win->x1;
	bres->y = win->y1;
	bres->x = win->x1;
	if (win->run == 0 && (bres->flip = 2))
		return bres;
	win->m = win->rise / win->run;
	bres->adjust = win->m > 0 ? 1 : -1;
	initbres_help(bres, win);
	return bres;
}

static void	drawline_h0(t_env *win, t_bresen *bres)
{
	while (bres->x < win->x2 + 1)
	{
		drawpoint(win, bres);
		bres->offset += win->m;
		if (bres->offset >= bres->threshold && (bres->y += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->x++;
	}
}

static void	drawline_h1(t_env *win, t_bresen *bres)
{
	while (bres->y < win->y2 + 1)
	{
		drawpoint(win, bres);
		bres->offset += win->m;
		if (bres->offset >= bres->threshold && (bres->x += bres->adjust))
			bres->threshold += bres->thresholdinc;
	bres->y++;
	}
}

void	drawline(t_env *win)
{
	t_bresen *bres;

	bres = initbres(win);
	win->m = ft_fl_abs(win->m);
	if (bres->flip == 0)
		drawline_h0(win, bres);
	else if (bres->flip == 1)
		drawline_h1(win, bres);
	else if (bres->flip == 2)
	{
		while (bres->y < win->y2 + 1)
		{
			drawpoint(win, bres);
			bres->y++;
		}
	}
}

int main(void)
{
	t_env	*win;
	win = (t_env*)malloc(sizeof(t_env));
	win->tit = "I'm Mister Window, look at me!";
	win->mlx = mlx_init();
	win->h = 400;
	win->w = 500;
	win->win = mlx_new_window(win->mlx, win->w, win->h, win->tit);

	win->x1 = 20;
	win->x2 = 20;
	win->y1 = 200;
	win->y2 = 300;

	drawline(win);

	mlx_loop(win->mlx);
}
