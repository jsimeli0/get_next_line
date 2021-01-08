/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 23:15:06 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/07 23:21:14 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define BUFFER_SIZE 12

int	main(void)
{
	// int i = 0;
	// char *s = "Hello";

	// while (s[i] != '\0')
	// 	i++;
	//  printf("%d\n", i);
	
	char *buffer = malloc(1000);
	int fd = open("test2", O_RDONLY);
	if (fd == -1)
		printf("errno = %d\n", errno);
	printf("%zd\n", read(fd, buffer, BUFFER_SIZE));
	printf("%zd\n", read(fd, buffer, BUFFER_SIZE));
	free(buffer);
	return 0;
}
