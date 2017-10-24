#include "fdf.h"

static void print_row(t_point *point) {
	while (point->right) {
		printf("{%d, %d, %d},{%ld} ", point->x, point->y, point->z, point->color);
		point = point->right;
	}
}

void print_map(t_point *point) {
	t_point *tmp = point;
	t_point *row;
	printf("entering print_map\n");
	while (tmp->down) {
		printf("loopin\n");
		row = tmp;
		print_row(row);
		tmp = tmp->down;
	}
	printf("exiting print_map\n");
}
