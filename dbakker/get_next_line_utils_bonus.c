/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:48:40 by dbakker           #+#    #+#             */
/*   Updated: 2025/06/10 09:52:27 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *string)
{
	size_t	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *buffer, char *line, ssize_t fd_bytes_read)
{
	char	*new_str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer || !line)
		return (NULL);
	new_str = ft_calloc(ft_strlen(buffer) + ft_strlen(line) + 1, sizeof(char));
	if (!new_str)
		return (free(buffer), NULL);
	while (buffer[j])
		new_str[i++] = buffer[j++];
	j = 0;
	while (line[j] && j < fd_bytes_read)
		new_str[i++] = line[j++];
	free(buffer);
	return (new_str);
}

char	*ft_strchr(const char *buffer, int character)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == (char)character)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (char)character)
		return ((char *)&buffer[i]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (!ptr || size > SIZE_MAX / nmemb)
		return (NULL);
	while (i < bytes)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}
