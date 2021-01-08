/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:51 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/09 00:03:52 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Checks for a whole line in buff_static and saves it to *line */
int	pop(char *buff_static, char **line)
{
	int			cut;
	int			len;

	if ((cut = ft_strchr_int(buff_static, '\n')) != -1)
	{
		*line = ft_substr(buff_static, 0, cut);
		if (*line == NULL)
			return (-1);
		len = ft_strlen(buff_static) - cut;
		buff_static = ft_substr(buff_static, cut, len);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int 		read_return;
	static char	*buff_static;
	char		buff_read[BUFFER_SIZE + 1];

	/* Safety checks */
	// if ((fd < 0 || !line || read(fd, buffer, 0) < 0))
	// 	return (-1);
	/* Pop a line from buff_static - if available - and do a NULL-check */
	if (buff_static)	
		if (pop(buff_static, line))
			return (1);
	read_return = read(fd, buff_read, BUFFER_SIZE);
	if (read_return < 0)
		return (-1);
	else if (read_return == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	buff_read[BUFFER_SIZE] = 0;
	buff_static = ft_strjoin(buff_static, buff_read);
	if (buff_static == NULL)
		return (-1);
	get_next_line(fd, line);
	return (1);
	// if (read_return == BUFFER_SIZE)
	// {
	// 	get_next_line(fd, line);
	// }
	// else if (read_return == 0)
	// {

	// }	

	// while ((read_return = read(fd, buffer, BUFFER_SIZE)) == BUFFER_SIZE)
	// {
	// 	if ((cut = ft_strchr_int(buffer, '\n')) != -1)
	// 	{
	// 		buffer[cut + 1]  = 0;
	// 		*line = ft_strjoin(*line, buffer);
	// 		return (1);
	// 	}
	// 	*line = ft_strjoin(*line, buffer);
	// 	line++;
	// }
	// if (read_return == 0)
	// {
	// 	*line = ft_strjoin(*line, buffer);
	// 	return (0);
	// }
	// else
	// 	return (-1);

	
	
	// *line = malloc(ft_strlen(save));


}
