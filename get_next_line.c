/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:51 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 19:36:21 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int 	ret_value;
	char	buff[BUFFER_SIZE + 1];

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	ret_value = read(fd, buff, BUFFER_SIZE);
	if (ret_value)
	{
		*line = ft_strdup(buff);
		line++;
		return (1);
	}
	return (0);
}
