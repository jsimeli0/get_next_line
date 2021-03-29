/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 12:42:45 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/11 16:13:46 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *buff_static, char const *buff_read);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strchr_int(const char *s, int c);
int		pop(char **buff_static, char **line, char c);
int		finish(char *buff_static, char **line);
int		get_next_line(int fd, char **line);

#endif
