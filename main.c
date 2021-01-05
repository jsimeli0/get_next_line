/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:13:30 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 23:50:24 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <errno.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

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

	// open is returning -1 for some reason.... 
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	close(fd);
	return (0);
}