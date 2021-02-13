/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:37:22 by marvin            #+#    #+#             */
/*   Updated: 2021/02/10 04:37:24 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		write_to_line(char *stat_str, char **line, int char_pos)
{
	char	*temp;

	temp = ft_strdup(stat_str);
	temp[char_pos] = '\0';
	if (temp[0] == '\0')
		*line = ft_strdup("");
	else
		*line = ft_strdup(temp);
	free(temp);
}

static int		find_break_or_null(char *stat_str, t_struct *vars)
{
	int	i;

	i = 0;
	if (stat_str[0] == '\0')
	{
		vars->return_number = 0;
		return (0);
	}
	while (stat_str[i] != '\0')
	{
		if (stat_str[i] == '\n')
		{
			vars->return_number = 1;
			break ;
		}
		i++;
		vars->return_number = 0;
	}
	return (i);
}

static char		*arrangements(char *stat_str, t_struct *vars, char **line)
{
	char	*temp;
	int		i;
	int		char_pos;

	i = 0;
	char_pos = find_break_or_null(stat_str, vars);
	write_to_line(stat_str, line, char_pos);
	if (stat_str[char_pos] == '\0')
	{
		stat_str[0] = '\0';
		return (stat_str);
	}
	char_pos++;
	temp = malloc(sizeof(char) * ft_strlen(stat_str) + 1);
	if (temp == NULL)
		return (NULL);
	while (stat_str[char_pos] != '\0')
		temp[i++] = stat_str[char_pos++];
	temp[i] = '\0';
	free(stat_str);
	return (temp);
}

static char		*add_to_final(char *stat_str, t_struct *vars)
{
	char	*temp;

	vars->buffer[vars->ret] = '\0';
	if (stat_str == NULL)
	{
		stat_str = ft_strdup(vars->buffer);
		return (stat_str);
	}
	else
	{
		temp = ft_strjoin(stat_str, vars->buffer);
		free(stat_str);
		return (temp);
	}
}

int				get_next_line(int fd, char **line)
{
	static char		*stat_str[ARRAY_MAX_SIZE];
	t_struct		vars;

	if (fd < 0 || fd == 1 || fd == 2 || line == NULL
		|| BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	vars.buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (vars.buffer == NULL)
		return (-1);
	vars.ret = read(fd, vars.buffer, BUFFER_SIZE);
	stat_str[fd] = add_to_final(stat_str[fd], &vars);
	while (vars.ret > 0 && !ft_strchr(vars.buffer, '\n'))
	{
		vars.ret = read(fd, vars.buffer, BUFFER_SIZE);
		stat_str[fd] = add_to_final(stat_str[fd], &vars);
	}
	stat_str[fd] = arrangements(stat_str[fd], &vars, line);
	free(vars.buffer);
	return (vars.return_number);
}
