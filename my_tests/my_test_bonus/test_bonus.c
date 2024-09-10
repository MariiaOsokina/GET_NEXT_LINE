
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line1;
	char	*line2;
	char	*line3;
	int		lines;
	int		fd1;
	int		fd2;
	int		fd3;


	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	int i = 0;
	lines = 0;
	while (i < 3)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		printf("%d -> %s, %s, %s\n", lines, line1, line2, line3);
		lines ++;
		free(line1);
		free(line2);
		free(line3);
		i++;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
