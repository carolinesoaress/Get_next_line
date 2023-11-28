/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:01:38 by cagoncal          #+#    #+#             */
/*   Updated: 2023/11/28 16:02:43 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*generate_line_return(char *line)
{
	char	*line_to_return;
	size_t	len;
	int		i;
	int		pos;

	len = ft_strlen(line);
	i = 0;
	
	while(line && line[i] != '\0')
	{
		if(line[i] == '\n')
			pos = len - i;
		i++;
	}
	line_to_return = ft_cpy(line, len - pos);
	
	if(!line_to_return)
	{
		free(line);
		return (NULL);
	}
	return(line_to_return);
}

char	*get_remainder(char *line)
{
	static char		*remainder = NULL;
	
	while(line && *line != '\0')
	{
		line++;
		if (*line == '\n')
		{
			remainder = ft_strdup(line + 1);
			if (!remainder)
                return (NULL);
			return (remainder);
		}	
	}
	remainder = ft_strdup("");
	if (!remainder)
        return (NULL);
	return (remainder);
}

char	*read_line(int fd, char *remainder)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	char			*line;
	char			*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, remainder);
	if (!line)
		return (NULL);
	remainder = get_remainder(line);
	 if (!remainder)
    {
        free(line);
        return (NULL);
    }
	line_to_return = generate_line_return(line);
	return (line_to_return);
}
