/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:29:27 by lpieck            #+#    #+#             */
/*   Updated: 2025/06/19 13:18:39 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

//copies text from node to string
void	ft_copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j] = '\n';
				str[++j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
	return ;
}

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = ft_len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	ft_copy_str(list, next_str);
	return (next_str);
}

/*free & clean list OR make remainder the first node of list for next call*/
void	ft_clean_list(t_list **list, t_list *remainder, char *buf)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (remainder && remainder->str_buf && remainder->str_buf[0])
		*list = remainder;
	else
	{
		if (buf)
			free(buf);
		if (remainder)
			free(remainder);
	}
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
