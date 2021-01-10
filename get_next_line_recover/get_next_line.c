/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:51 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/10 16:19:03 by jsimelio      ########   odam.nl         */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_2;
	char	*src_2;

	dst_2 = (char*)dst;
	src_2 = (char*)src;
	if (n == 0 || dst == src)
		return (dst);
	while ((int)n)
	{
		*dst_2 = *src_2;
		dst_2++;
		src_2++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* Checks for a whole line in buff_static and saves it to *line */
int	pop(char **buff_static, char **line, char c)
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
		*buff_static = ft_substr(*buff_static, cut + 1, len);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int 		read_return;
	static char	*buff_static;
	char		buff_read[BUFFER_SIZE + 1];

	buff_read[0] = 0;
	if ((fd < 0 || !line || BUFFER_SIZE < 0))
		return (-1);
	if (buff_static)
		if (pop(&buff_static, line, '\n'))
			return (1);
	while ((read_return = read(fd, buff_read, BUFFER_SIZE)) > 0)
	{
		buff_read[read_return] = 0;
		buff_static = ft_strjoin(buff_static, buff_read);
		if (buff_static == NULL)
			return (-1);
		if (pop(&buff_static, line, '\n'))
			return (1);
	}
	if (read_return == 0)
	{
		buff_static = ft_strjoin(buff_static, "");
		pop(&buff_static, line, '\0');
		return (0);
	}
	return (-1);
}
