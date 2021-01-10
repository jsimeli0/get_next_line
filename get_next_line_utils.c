/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:43 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/10 22:11:26 by jsimelio      ########   odam.nl         */
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
	char	*s3;
	size_t	i;

	if (!buff_static && !buff_read)
		return (NULL);
	strlen = ft_strlen(buff_static) + ft_strlen(buff_read);
	s3 = malloc((strlen + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		if (i < ft_strlen(buff_static))
			s3[i] = buff_static[i];
		else
			s3[i] = buff_read[i - ft_strlen(buff_static)];
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
