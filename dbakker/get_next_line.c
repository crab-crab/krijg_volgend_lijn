/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:48:29 by dbakker           #+#    #+#             */
/*   Updated: 2025/06/17 10:31:41 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_returning_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*trim_leftover_line(char *buffer)
{
	char	*leftover_line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	leftover_line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!leftover_line)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		leftover_line[j++] = buffer[i++];
	free(buffer);
	return (leftover_line);
}

char	*fill_buffer(char *buffer, int fd)
{
	ssize_t	fd_bytes_read;
	char	*line;

	fd_bytes_read = 1;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		fd_bytes_read = read(fd, line, BUFFER_SIZE);
		if (fd_bytes_read == 0)
			break ;
		if (fd_bytes_read == -1)
			return (free(line), free(buffer), NULL);
		buffer = ft_strjoin(buffer, line, fd_bytes_read);
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	buffer = fill_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_returning_line(buffer);
	buffer = trim_leftover_line(buffer);
	return (line);
}
