/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:45 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 19:36:26 by jsimelio      ########   odam.nl         */
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
char	*ft_strchr(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#endif