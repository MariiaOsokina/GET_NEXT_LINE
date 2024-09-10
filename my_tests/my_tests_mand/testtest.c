// Including the unistd header for the write(2) function
// Including the fcntl header for the open(2) function
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
    char	*line;
    int		lines;
	int		fd;
    char    *buf;
    int chars_read;
    int BUFFER_SIZE = 10;

	fd = open("text.txt", O_RDONLY);
    buf = malloc(sizeof(char)* (BUFFER_SIZE + 1));
    chars_read = read(fd, buf, BUFFER_SIZE);
	printf("chars_read %d\n", chars_read);
    printf("buffer %s\n", buf);
    free (buf);
	return (0);
}
