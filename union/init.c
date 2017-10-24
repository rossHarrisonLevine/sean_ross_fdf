#include "fdf.h"

struct t_point	init_point(int x, int y, int z)
{
	struct t_point *point;

	if (!(point = (struct t_point*)malloc(sizeof(struct t_point))))
	{
		perror("Not enough space for a point malloc\n");
		return NULL;
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->right = NULL;
	point->down = NULL;
}
