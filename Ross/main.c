#include "fdf.h"

int main(int ac, char **av)
{
	t_map *map;

	if (ac == 2)
	{
		/*read and checks file outputs 2d array
		 filled with vectors in r3*/
		map = verify(av[1]);
		/*a hook that checks for input and rotates accoridingly*/
		/*draw lines*/
	}
	perror("usage: ./fdf [file]");
}