/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:29:41 by lpieck            #+#    #+#             */
/*   Updated: 2025/06/19 12:41:43 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;

}	t_list;

char	*get_next_line(int fd);
int		ft_len_to_newline(t_list *list);
void	ft_copy_str(t_list *list, char *str);
void	ft_clean_list(t_list **list, t_list *clean_node, char *buf);
char	*ft_strchr(const char *s, int c);
void	ft_create_list(t_list **list, int fd);
void	ft_append(t_list **list, char *buf);
char	*ft_get_line(t_list *list);
void	ft_trim_list(t_list **list);
void	ft_fill_list(t_list **list, int fd);

#endif
