/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:29:38 by lpieck            #+#    #+#             */
/*   Updated: 2025/06/19 13:30:19 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list[MAX_FD];
	char			*next_line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
	{
		ft_clean_list(&list[fd], NULL, NULL);
		return (NULL);
	}
	ft_create_list(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	next_line = ft_get_line(list[fd]);
	if (!next_line)
	{
		ft_clean_list(&list[fd], NULL, NULL);
		return (NULL);
	}
	ft_trim_list(&list[fd]);
	return (next_line);
}

/*checks static list if another \n is available to avoid abundant read calls*/
void	ft_create_list(t_list **list, int fd)
{
	t_list	*current;

	if (!list)
		return ;
	current = *list;
	while (current && !ft_strchr(current->str_buf, '\n'))
		current = current->next;
	if (current && ft_strchr(current->str_buf, '\n'))
		return ;
	ft_fill_list(list, fd);
}

/*keeps reading and appending nodes until \n or \0 is found*/
void	ft_fill_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buf;
	t_list	*current;

	if (!list)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_clean_list(list, NULL, NULL));
	chars_read = read(fd, buf, BUFFER_SIZE);
	if (chars_read <= 0)
	{
		free(buf);
		if (chars_read < 0 || !*list)
			ft_clean_list(list, NULL, NULL);
		return ;
	}
	buf[chars_read] = '\0';
	ft_append(list, buf);
	current = *list;
	while (current && !ft_strchr(current->str_buf, '\n'))
		current = current->next;
	if (!current || !ft_strchr(current->str_buf, '\n'))
		ft_fill_list(list, fd);
}

/*keeps addding nodes to the back of the list*/
void	ft_append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (free(buf));
	new_node->str_buf = buf;
	new_node->next = NULL;
	if (!list)
		return (free(buf), free(new_node));
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

//copies remainder after \n > calls ft_clean_list
void	ft_trim_list(t_list **list)
{
	t_list	*last_node;
	t_list	*remainder;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(BUFFER_SIZE + 1);
	remainder = malloc(sizeof(t_list));
	if (!buf || !remainder || !list || !*list)
		return (free(buf), free(remainder), ft_clean_list(list, NULL, NULL));
	remainder->str_buf = buf;
	remainder->next = NULL;
	last_node = *list;
	while (last_node->next)
		last_node = last_node->next;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	if (last_node->str_buf[i] == '\n')
		i++;
	while (last_node->str_buf[i])
		buf[j++] = last_node->str_buf[i++];
	buf[j] = '\0';
	return (ft_clean_list(list, remainder, buf));
}
