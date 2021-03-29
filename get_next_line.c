/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:51 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/11 16:22:55 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_int(const char *s, int c)
{
	int		counter;

	if (c == '\0')
	{
		counter = ft_strlen(s);
		return (counter);
	}
	counter = 0;
	while (*s)
	{
		if (*s == c)
			return (counter);
		s++;
		counter++;
	}
	return (-1);
}

int		pop(char **buff_static, char **line, char c)
{
	int			cut;
	int			len;

	cut = ft_strchr_int(*buff_static, c);
	if (cut != -1)
	{
		*line = ft_substr(*buff_static, 0, cut);
		if (*line == NULL)
			return (-1);
		len = ft_strlen(*buff_static) - cut;
		ft_memmove(*buff_static, (*buff_static) + cut + 1, len);
		return (1);
	}
	return (0);
}

int		finish(char *buff_static, char **line)
{
	buff_static = ft_strjoin(buff_static, "");
	if (buff_static == NULL)
			return (-1);	
	pop(&buff_static, line, '\0');
	free(buff_static);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_return;
	static char	*buff_static;
	char		buff_read[BUFFER_SIZE + 1];

	if ((fd < 0 || !line || BUFFER_SIZE < 0))
		return (-1);
	if (buff_static)
		if (pop(&buff_static, line, '\n'))
			return (1);
	read_return = read(fd, buff_read, BUFFER_SIZE);
	while (read_return > 0)
	{
		buff_read[read_return] = 0;
		buff_static = ft_strjoin(buff_static, buff_read);
		if (buff_static == NULL)
			return (-1);
		if (pop(&buff_static, line, '\n'))
			return (1);
		read_return = read(fd, buff_read, BUFFER_SIZE);
	}
	if (read_return == 0)
		return (finish(buff_static, line));
	return (-1);
}
