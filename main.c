/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:13:30 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/10 23:00:45 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include "get_next_line.c"
#include <errno.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

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

int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	int 	l = 1;
	fd = open("/Users/jsimelio/Codam/get_next_line/test_file9", O_RDONLY);
	// fd = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%i | %i | %s\n ", l, i, line);
		free(line);
		l++;
	}
	// system("leaks a.out");
	close(fd);
	return (0);

}