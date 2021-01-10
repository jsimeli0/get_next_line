/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:43 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/10 22:46:08 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	static char *s2;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		s2 = malloc(sizeof(char*));
		if (!s2)
			return (NULL);
		*s2 = 0;
		return (s2);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, (s + start), len);
	s2[len] = 0;
	return (s2);
}

char	*ft_strjoin(char *buff_static, char const *buff_read)
{
	size_t	strlen;
	size_t	strlen_static;
	char	*s3;
	size_t	i;

	if (!buff_static && !buff_read)
		return (NULL);
	strlen_static = ft_strlen(buff_static);
	strlen = strlen_static + ft_strlen(buff_read);
	s3 = malloc((strlen + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		if (i < strlen_static)
			s3[i] = buff_static[i];
		else
			s3[i] = buff_read[i - strlen_static];
		i++;
	}
	s3[strlen] = 0;
	if (buff_static != NULL)
		free(buff_static);
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned const char	*src2;
	int					i;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (dst2 > src2 && (dst2 - src2) < (int)len)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dst2[i] = src2[i];
			i--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
