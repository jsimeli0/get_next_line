/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:43 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 17:12:51 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

char	*ft_strdup(const char *s1)
{
	void	*memory;
	int		strlen;

	strlen = ft_strlen(s1) + 1;
	memory = malloc(strlen * sizeof(char));
	if (!memory)
		return (NULL);
	ft_memcpy(memory, s1, strlen);
	return (memory);
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

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}