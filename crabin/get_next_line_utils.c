/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:26:58 by crabin            #+#    #+#             */
/*   Updated: 2025/06/17 12:58:42 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len])
		len++;
	return (len);
}

/* The memset() function fills the first n bytes of the memory area pointed to
by s with the constant byte c. 
The memset() function returns a pointer to the memory area s.*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (ULONG_MAX / nmemb < size || ULONG_MAX / size < nmemb)
		return (NULL);
	total_size = nmemb * size;
	temp = malloc(total_size);
	if (temp)
	{
		(void)ft_memset(temp, 0, total_size);
		return (temp);
	}
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	int		i;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dsize > 1)
	{
		dst[i] = src[i];
		i++;
		dsize --;
	}
	if (dsize > 0)
		dst[i] = '\0';
	return (src_len);
}

/* Allocates memory (using malloc(3)) and returns a new string, which is the
result of concatenating ’s1’ and ’s2’. Return NULL if malloc fails*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = BUFFER_SIZE;
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	(void)ft_strlcpy(new_str, s1, s1_len + 1);
	(void)ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	new_str[s1_len + s2_len] = '\0';
	if (s1)
		free((void *)s1);
	return (new_str);
}
