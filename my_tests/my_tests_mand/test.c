
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		lines;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf ("\nnull");
			break ;
		}
		printf("%d -> %s", lines, line);
		lines ++;
		free(line);
	}
	close(fd);
	return (0);
}
