/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:10:47 by dbakker           #+#    #+#             */
/*   Updated: 2025/06/10 12:09:23 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	i = 0;
	if (argc < 3)
		return (printf("Needs to be atleast 3 arguments: %i\n", argc));
	if (strcmp(argv[1], "1") == 0)
		fd = open("txt_lorem_ipsum.txt", O_RDONLY);
	else if (strcmp(argv[1], "2") == 0)
		fd = open("txt_long_line.txt", O_RDONLY);
	else if (strcmp(argv[1], "3") == 0)
		fd = open("txt_123456789.txt", O_RDONLY);
	else if (strcmp(argv[1], "4") == 0)
		fd = open("txt_bee_movie_script.txt", O_RDONLY);
	else if (strcmp(argv[1], "5") == 0)
		fd = open("txt_empty.txt", O_RDONLY);
	else if (strcmp(argv[1], "6") == 0)
		fd = open("txt_simple.txt", O_RDONLY);
	else if (strcmp(argv[1], "7") == 0)
		fd = open("txt_abcd", O_RDONLY);
	else if (strcmp(argv[1], "8") == 0)
		fd = open("txt_newlines.txt", O_RDONLY);
	else if (strcmp(argv[1], "9") == 0)
		fd = open("txt_only_nl.txt", O_RDONLY);
	else if (strcmp(argv[1], "10") == 0)
		fd = open("txt_1char_nl.txt", O_RDONLY);
	else if (strcmp(argv[1], "11") == 0)
		fd = open("txt_lines_around_10_nl.txt", O_RDONLY);
	else if (strcmp(argv[1], "12") == 0)
		fd = open("txt_read_error.txt", O_RDONLY);
	else
		return (printf("Invalid .txt argument\n"));
	line = "start";
	while (i < atoi(argv[2]))
	{
		line = get_next_line(fd);
		if (argc == 4)
			if (!line && strcmp(argv[3], "true") == 0)
				break ;
		if (line)
			printf("--> %s", line);
		else
			printf("\n%s", line);
		free(line);
		i++;
	}
	close(fd);
	printf("\n");
	return (0);
}
