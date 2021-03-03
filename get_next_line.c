/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:20:19 by maraurel          #+#    #+#             */
/*   Updated: 2021/03/03 11:19:45 by maraurel         ###   ########.fr       */
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
	if (!(saved))
		return (0);
	l = line;
	while (l[k])
		k++;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (0);
	}
	tmp = ft_substr(saved, k + 1, (ft_strlen(saved) - i));
	j = 0;
	while (tmp[j])
		j++;
	tmp[j] = '\0';
	free(saved);
	return (tmp);
}

int			has_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*saved;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = 1;
	while (!ft_strchr(saved, '\n') && i != 0)
	{
		if ((i = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	free(buf);
	*line = save_line(saved);
	saved = new_saved(saved, *line);
	if (i == 0)
		return (0);
	return (1);
}