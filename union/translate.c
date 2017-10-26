#include "fdf.h"

/* translate will move the map depending on the values
of x (horizantal) and y (vertical)*/

static void     translate_row(float x, float y, t_point *point)
{
	while (point)
	{
        point->x += x;
        point->y += y;
		point = point->right;
	}
}

void            translate_map(float x, float y, t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
	while (tmp)
	{
		row = tmp;
		translate_row(x, y, row);
		tmp = tmp->down;
	}
}
