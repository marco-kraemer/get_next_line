/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:46:04 by maraurel          #+#    #+#             */
/*   Updated: 2021/02/19 19:40:59 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int   main(void)
{
	char  *line;
	int	fd1;
	int	i;
	int	j = 0;
	
	i = 1;
	fd1 = open("file1.txt", O_RDONLY);
	while (i != 0)
	{
		i = get_next_line(fd1, &line);
		printf("%s$\n", line);
		j++;
	}
	return (0);
 }
