/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:10:47 by dbakker           #+#    #+#             */
/*   Updated: 2025/06/10 12:26:32 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;

	line = NULL;
	i = 0;
	if (argc < 2)
		return (printf("Needs to be atleast 2 arguments: %i\n", argc));
	fd1 = open("txt_lorem_ipsum.txt", O_RDONLY);
	fd2 = open("txt_lines_around_10.txt", O_RDONLY);
	fd3 = open("txt_abcd", O_RDONLY);
	while (i++ < atoi(argv[1]))
	{
		line = get_next_line(fd1);
		if (line)
			printf("fd1 --> %s", line);
		else
			printf("fd1 --> %s\n", line);
		free(line);
		line = get_next_line(fd2);
		if (line)
			printf("fd2 --> %s", line);
		else
			printf("fd2 --> %s\n", line);
		free(line);
		line = get_next_line(fd3);
		if (line)
			printf("fd3 --> %s", line);
		else
			printf("fd3 --> %s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	printf("\n");
	return (0);
}
