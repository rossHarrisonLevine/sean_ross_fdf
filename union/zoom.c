#include "fdf.h"

/*void			handle_trans(t_map *map)
{
	int i;
	t_point *tmpw;
	t_point *tmph;

	tmpw = map->map;
	tmph = map->map;
	i = 0;
	while (i < (map->w / 2))
	{
		tmpw = tmpw->right;
		i++;
	}
	i = 0;
	while (i < (map->h / 2))
	{
		tmph = tmph->down;
		i++
	}
	translate_map(-(tmp->x));
	translate_map(-(tmp->x));
}*/
static void     zoom_row(float alpha, t_point *point, float mx, float my)
{
	while (point)
	{
        point->x = (alpha * point->x) - (mx * alpha) + mx;
        point->y = (alpha * point->y) - (my * alpha) + my;
        point->z *= alpha;
		point = point->right;
	}
}

static float	getmidval(char wat, t_map *map)
{
	int	i;
	float ret;
	t_point	*tmp;

	tmp = map->map;
	i = 1;
	if (wat == 'x')
	{
		printf("%d\n", (map->w /2));
		while (i < (map->w / 2))
		{
			tmp = tmp->right;
			i ++;
		}
		ret = tmp->x;
		return (ret);
	}
	else
	{
		while (i < (map->h / 2))
		{
			tmp = tmp->down;
			i ++;
		}
		ret = tmp->y;
		return (ret);
	}

}
void            zoom(float mult, t_map *map)
{
	t_point	*tmp;
	t_point	*row;
	float	midvalx;
	float	midvaly;

	tmp = map->map;
	midvalx = getmidval('x', map);
	midvaly = getmidval('y', map);
/*	handle_trans(map);
*/	while (tmp)
	{
		row = tmp;
		zoom_row(mult, row, midvalx, midvaly);
		tmp = tmp->down;
	}
}