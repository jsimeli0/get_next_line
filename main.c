/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:13:30 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/07 00:15:14 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
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

int	main(void)
{
	int		fd;
	char	*line = malloc(1000);

	// if (argc == 1)
	// 	fd = 0;
	// else if (argc == 2)
	// 	fd = open(argv[1], O_RDONLY);
	// else
	// 	return (2);

	// open is returning -1 for some reason.... 


	fd = open("test2", O_RDONLY);
	if (fd == -1)
		printf("errno = %d\n", errno);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl_fd(line, 1);
	}
	close(fd);
	free(line);
	return (0);
}