/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:00:23 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/14 16:31:29 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE 10

int	main(void)
{
	char buff[BUFF_SIZE + 1];
	int fd = open("test.txt", O_RDONLY);
	int ret;
	while ((ret = read(fd, buff, BUFF_SIZE)))
		printf("%d\n", ret);
	return (0);
}
