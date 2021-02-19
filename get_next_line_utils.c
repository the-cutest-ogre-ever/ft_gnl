/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:14:06 by ijose             #+#    #+#             */
/*   Updated: 2021/01/26 17:49:44 by ijose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 && !s2)
		return (0);
	if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	if (s1)
	{
		k = 0;
		while (s1[k])
			str[i++] = s1[k++];
	}
	if (s2)
	{
		k = 0;
		while (s2[k])
			str[i++] = s2[k++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(substr = malloc(sizeof(char) * 1)))
			return (0);
		substr[i] = '\0';
		return (substr);
	}
	if (!(substr = malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
