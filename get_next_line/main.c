#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("filenonl.txt", O_RDONLY);
	printf("GNL =|%s|\n", get_next_line(fd));
	printf("GNL = |%s|\n", get_next_line(fd));
	printf("GNL = |%s|\n", get_next_line(fd));

	return(0);
}
