/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:37:22 by marvin            #+#    #+#             */
/*   Updated: 2021/01/21 05:02:46 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*remove_after_line_break(char *final)
{
	t_list lista;

	lista.a = 0;
	if (get_line_break(final) + 1 > (int)ft_strlen(final))
		lista.i = get_line_break(final);
	else
		lista.i = get_line_break(final) + 1;
	if (!(lista.temp = malloc((ft_strlen(final) + 1 - lista.i) * sizeof(char))))
		return (NULL);
	if (final[lista.i] == '\0')
	{
		free(lista.temp);
		free(final);
		return (NULL);
	}
	while (final[lista.i] != '\0')
		lista.temp[lista.a++] = final[lista.i++];
	lista.temp[lista.a] = '\0';
	if (lista.a == 0)
	{
		free(lista.temp);
		return (final);
	}
	free(final);
	return (lista.temp);
}

static char		*get_next_line_return_if_null(char **line,
											char *final, char *temp)
{
	final = ft_strdup(temp);
	temp[get_line_break(temp)] = '\0';
	*line = ft_strdup(temp);
	temp[0] = '\0';
	final = remove_after_line_break(final);
	free(temp);
	return (final);
}

static char		*get_next_line_return(char **line, char *final)
{
	int		linebreak;
	char	*temp;

	linebreak = get_line_break(final);
	temp = ft_strdup(final);
	temp[linebreak] = '\0';
	*line = ft_strdup(temp);
	temp[0] = '\0';
	final = remove_after_line_break(final);
	free(temp);
	return (final);
}

static int		return_final(char *final, int ret, char *tempo, char **line)
{
	int		a;

	if (ret < 0)
		return (-1);
	if (tempo != NULL)
		free(tempo);
	if (ret == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	a = 0;
	while (final[a] != '\0')
	{
		if (final[a] == '\n')
			break ;
		a++;
	}
	if (final[a] == '\0')
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*final[ARRAY_MAX_SIZE];
	t_list			lista;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (!(lista.buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	lista.buffer[0] = '\0';
	lista.temp = ft_strdup(lista.buffer);
	if (final[fd] == NULL)
	{
		while ((lista.ret = read(fd, lista.buffer, BUFFER_SIZE)) > 0)
		{
			lista.buffer[lista.ret] = '\0';
			lista.temp = ft_strjoin(lista.temp, lista.buffer);
		}
		if ((lista.ret < 0) || (lista.ret == 0 && lista.temp[0] == '\0'))
			return (return_final(final[fd], lista.ret, lista.temp, line));
		lista.return_number = return_if_null(lista.temp);
		final[fd] = get_next_line_return_if_null(line, final[fd], lista.temp);
		return (lista.return_number);
	}
	lista.return_number = return_final(final[fd], 1, lista.temp, line);
	final[fd] = get_next_line_return(line, final[fd]);
	return (lista.return_number);
}
