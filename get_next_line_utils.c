/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:20:41 by maraurel          #+#    #+#             */
/*   Updated: 2021/02/19 15:46:45 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)str;
	while (str[i])
	{
		if (str[i] == c)
			return (p + i);
		i++;
	}
	if (c == '\0')
		return (p + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(p = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		p[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	p[ft_strlen(s1) + i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	length;
	char	*p;
	char	*k;

	k = (char *)s;
	length = ft_strlen(k) + 1;
	if (!(p = malloc(length)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = k[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(p = malloc(len + 1)))
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			p[i] = s[start];
			i++;
			start++;
		}
	}
	p[i] = '\0';
	return (p);
}

int		countstring(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

int		countchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

char	**to_free(char const **p, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)p[j]);
	}
	free(p);
	return (NULL);
}

char	**makearray(char const *s, char **p, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		p[j] = (char *)malloc(sizeof(char) * countchar(s, c, i) + 1);
		if (p[j] == NULL)
			return (to_free((char const **)p, j));
		while (s[i] != '\0' && s[i] != c)
			p[j][k++] = s[i++];
		p[j][k] = '\0';
		j++;
	}
	p[j] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	if (s == NULL)
		return (NULL);
	i = countstring(s, c);
	p = (char **)malloc(sizeof(char *) * (i + 1));
	if (p == NULL)
		return (NULL);
	return (makearray(s, p, c, i));
}
