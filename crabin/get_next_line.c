/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:26:52 by crabin            #+#    #+#             */
/*   Updated: 2025/06/18 11:34:10 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlchr(char *s, int c, size_t l)
{
	if (!s)
		return (NULL);
	while (*s && l > 0)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
		l--;
	}
	return (NULL);
}

int	fill_buffer(char **buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*swap;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (-1);
	while (!ft_strlchr(*buffer, '\n', __SIZE_MAX__))
	{
		ft_memset(temp, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*buffer)
				free (*buffer);
			free(temp);
			return (*buffer = NULL, -1);
		}
		if (bytes_read == 0)
			break ;
		swap = ft_strjoin(*buffer, temp);
		*buffer = swap;
	}
	free(temp);
	return (1);
}

int	extract_returns(char **buffer, char **next_line)
{
	char	*next_seperator;
	char	*temp;
	int		str_len;

	next_seperator = ft_strlchr(*buffer, '\n', __SIZE_MAX__);
	str_len = next_seperator - *buffer + 2;
	if (!next_seperator)
		str_len = ft_strlen(*buffer) + 1;
	*next_line = ft_calloc(str_len + 1, sizeof(char));
	if (!*next_line)
		return (-1);
	ft_strlcpy(*next_line, *buffer, str_len);
	if (next_seperator)
		str_len = ft_strlen(next_seperator + 1) + 1;
	else
		return (free(*buffer), *buffer = NULL, 1);
	temp = *buffer;
	*buffer = ft_calloc(str_len + 1, sizeof(char));
	if (!*buffer)
		return (-1);
	ft_strlcpy(*buffer, next_seperator + 1, str_len);
	if (temp)
		return (free(temp), temp = NULL, 1);
	return (1);
}

void	free_vars(char **buffer, char **next_line)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (*next_line)
	{
		free(*next_line);
		*next_line = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*next_line;
	ssize_t				bytes_read;

	next_line = NULL;
	bytes_read = fill_buffer(&buffer, fd);
	if (bytes_read < 0)
	{
		free_vars(&buffer, &next_line);
		return (NULL);
	}
	if (bytes_read == 1 && ft_strlen(buffer) == 0)
	{
		free_vars(&buffer, &next_line);
		return (NULL);
	}
	if (extract_returns(&buffer, &next_line) < 0)
		return (NULL);
	return (next_line);
}
