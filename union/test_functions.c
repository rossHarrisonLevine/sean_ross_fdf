#include "fdf.h"

static void print_row(t_point *point) {
	while (point) {
		printf("{%d, %d, %d},{%ld}", point->x, point->y, point->z, point->color);
		point = point->right;
		if (point)
			printf(" ");
		else
			printf("\n");
	}
}

void print_map(t_point *point) {
	t_point *tmp = point;
	t_point *row;
	while (tmp) {
		row = tmp;
		print_row(row);
		tmp = tmp->down;
	}
}


/*  color shizz
int r;
int g;
int b;
int clr;

r = 255;
g = 255;
b = 15;

clr = r << 16 | g << 8 | b;
*/
