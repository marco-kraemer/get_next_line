#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int i;
	int fd;
	int j;
	char *line;

	fd = open("1.txt", O_RDONLY);
	i = 1;
	j = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		j++;
		printf("%s\n", line);
		if (line)
			free(line);
	}
}
