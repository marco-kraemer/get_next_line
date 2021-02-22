/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:20:19 by maraurel          #+#    #+#             */
/*   Updated: 2021/02/19 19:51:55 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_line(char *saved)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!saved)
		return (0);
	while (saved[i] && saved[i] != '\n')
		i++;
	tmp = ft_substr(saved, 0, i);
	tmp[i] = '\0';
	return (tmp);
}

char	*new_saved(char *saved, char *line)
{
	char	*tmp;
	char	*l;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(saved || line))
		return (0);
	l = line;
	while (l[k])
		k++;
	while (saved[i] && saved[i] != '\n')
		i++;
	tmp = ft_substr(saved, k + 1, (ft_strlen(saved) - i));
	j = 0;
	while (tmp[j])
		j++;
	tmp[j] = '\0';
	free(saved);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*saved;
	char		*buf;
	int			i;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = 1;
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (i == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		if (saved == NULL)
			saved = ft_strdup(buf);
		else
			saved = ft_strjoin(saved, buf);
		if (ft_strchr(saved, '\n'))
			break ;
	}
	free(buf);
	*line = save_line(saved);
	saved = new_saved(saved, *line);
	if (i == 0 && ft_strlen(saved) == 0)
	{
		return (0);
	}
	return (1);
}
