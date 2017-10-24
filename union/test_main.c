#include "fdf.h"

int main(int ac, char **av) {
	if (ac != 2) {
		printf("give me an input please\n");
		return 0;
	}
	int fd = open(av[1], O_RDONLY);
	print_map(read_map(fd));
}
