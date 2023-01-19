/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:18:17 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/19 16:40:55 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = ft_strlen(s);
	str = malloc(size + 1);
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j])
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char )c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len == 0)
		return (NULL);
	if (len < ft_strlen(s + start))
		sub = (char *)malloc(len + 1);
	else
		sub = (char *)malloc(ft_strlen(s + start) + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (*(s + start + i) && i < len)
		{
			*(sub + i) = *(s + start + i);
			i++;
		}
	}
	*(sub + i) = 0;
	return (sub);
}
