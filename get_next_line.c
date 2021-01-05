/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:51 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/05 21:32:26 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int 	ret_value;
	char	buffer[BUFFER_SIZE];
	int		cut;
	/* No need to declare another string here, just use *line later */

	/*	Safety checks */
	// if ((fd < 0 || line == NULL || read(fd, buffer, 0) < 0))
	// 	return (-1);
	**line = 0;
	// ret_value = read(fd, buffer, BUFFER_SIZE);
	while (ret_value = read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		if (cut = ft_strchr_int != -1)
		{
			buffer[cut + 1]  = 0;
			*line = ft_strjoin(*line, buffer);
			return (1);
		}
		*line = ft_strjoin(*line, buffer);
		line++;
	}
	if (ret_value == 0)
	{
		*line = ft_strjoin(*line, buffer);
		return (0);
	}
	else
		return (-1);
}
