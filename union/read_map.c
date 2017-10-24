#include "fdf.h"

int map_len(int fd)
{
	int i;
	char *line;

	i = 0;
	while (get_next_line(fd, NULL)) > 0)
		i++;


int	**read_map(int fd)
{
	int **map;
	char *line;
	char **l_split;

	while (get_next_line(fd, &line) > 0)
	{
		l_split = str_split(line, ' ');
		
