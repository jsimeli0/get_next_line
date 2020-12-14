/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:13:30 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 17:06:03 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	// if (argc == 1)
	// 	fd = 0;
	// else if (argc == 2)
	// 	fd = open(argv[1], O_RDONLY);
	// else
	// 	return (2);
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	close(fd);
	return (0);
}