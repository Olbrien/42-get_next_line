/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:42:45 by marvin            #+#    #+#             */
/*   Updated: 2021/01/08 18:10:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_line_break(char *final)
{
	int i;

	i = 0;
	if (!final)
		return (0);
	while (final[i] != '\n')
	{
		if (final[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*string;
	int		len;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (!s1)
		return (NULL);
	if (!s2 && s1)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(string = malloc(len + 1 * sizeof(string))))
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		string[i++] = s2[b++];
	string[i] = '\0';
	free(s1);
	return (string);
}

char		*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	if (!(dest = malloc(sizeof(*dest) * len + 1)))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			return_if_null(char *final)
{
	int i;

	i = 0;
	while (final != NULL && final[i] != '\0')
	{
		if (final[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
