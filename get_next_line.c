#include "get_next_line.h"

char	*read_line(int fd, char *remainder)
{
	char		*buffer;
	ssize_t 	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = gnl_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}
char	*get_next_line(int fd)
{
	static char *remainder = NULL;
	char		*line;
    
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_line(fd, remainder);
	if (!remainder)
		return (NULL);
}