#include "fdf.h"

static void     rotate_x(t_point *point, int dir)
{
    float y;
    float z;

    y = point->y;
    z = point->z;
	while (point)
	{
        point->y = dir * ((y * cos(30)) + (z * sin(30)));
        point->z = dir * ((z * cos(30) - (y * sin(30))));
		point = point->right;
	}
}

static void     rotate_y(t_point *point, int dir)
{
    float x;
    float z;

    x = point->x;
    z = point->z;
	while (point)
	{
        point->x = dir * ((x * cos(30)) - (z * sin(30)));
        point->z = dir * ((x * sin(30) + (z * cos(30))));
		point = point->right;
	}
}

static void     rotate_z(t_point *point, int dir)
{
    float x;
    float y;

    x = point->x;
    y = point->y;
	while (point)
	{
        point->x = dir * ((x * cos(30)) + (y * sin(30)));
        point->y = dir * ((y * cos(30) - (x * sin(30))));
		point = point->right;
	}
}

void            rotate(char c, int dir, t_point *point)
{
	t_point	*tmp;
	t_point	*row;

	tmp = point;
	while (tmp)
	{
		row = tmp;
		if (c == 'x')
            rotate_x(point, dir);
        if (c == 'y')
            rotate_y(point, dir);
        if (c == 'z')
            rotate_z(point, dir);
		tmp = tmp->down;
	}
}
