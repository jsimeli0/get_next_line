/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 23:15:06 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/06 23:21:19 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int	main(void)
{
	int fd = open("test2", O_RDONLY);
	printf("fd = %d, errno = %d\n", fd, errno);

}
