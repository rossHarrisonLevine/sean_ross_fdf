#include "fdf.h"

t_point	*init_point(int x, int y, int z, long int color)
{
	t_point *point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
	{
		perror("Not enough space for a point malloc\n");
		return NULL;
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	point->right = NULL;
	point->down = NULL;
	return point;
}
