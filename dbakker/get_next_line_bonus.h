/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:48:34 by dbakker           #+#    #+#             */
/*   Updated: 2025/06/10 09:40:57 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h> // write()
# include <stdlib.h> // malloc() and free()
# include <stdint.h> // SIZE_MAX

char	*get_next_line(int fd);
char	*fill_buffer(char *buffer, int fd);
char	*get_returning_line(char *buffer);
char	*trim_leftover_line(char *buffer);
size_t	ft_strlen(char *string);
char	*ft_strjoin(char *buffer, char *line, ssize_t fd_bytes_read);
char	*ft_strchr(const char *buffer, int character);
void	*ft_calloc(size_t nmemb, size_t size);
#endif
