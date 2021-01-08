/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:45 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/08 00:03:12 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFFER_SIZE
#define BUFFER_SIZE 10
#endif

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int 	get_next_line(int fd, char **line);
int		ft_strchr_int(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src,
		size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *line, char const *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif