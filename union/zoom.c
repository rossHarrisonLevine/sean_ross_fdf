#include "fdf.h"

static void     zoom_row(float mult, t_point *point)
{
	while (point)
	{
        point->x *= mult;
        point->y *= mult;
        point->z *= mult;
		point = point->right;
	}
}

void            zoom(float mult, t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
	while (tmp)
	{
		row = tmp;
		zoom_row(mult, row);
		tmp = tmp->down;
	}
}