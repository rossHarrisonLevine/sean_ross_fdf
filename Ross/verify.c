#include "fdf.h"

int	verify(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (map->height == 0)
			map->width = ft_strlen(line) - (ft_strlen(line) - 1);
		if (ft_strlen(line) - (ft_strlen(line) - 1) != map->width)
			perror("different widths in map");
		map->height++;
	}

}

int main()
{
	t_map *map;
	map->height = 0;
	map = (t_map*)malloc(sizeof(t_map));
	verify("tits", map);
	return 0;
}	
