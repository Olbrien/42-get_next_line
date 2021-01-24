/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:37:41 by marvin            #+#    #+#             */
/*   Updated: 2021/01/21 04:56:24 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef ARRAY_MAX_SIZE
#  define ARRAY_MAX_SIZE 4096
# endif

typedef struct	s_list
{
	int		i;
	int		a;
	char	*temp;
	int		ret;
	int		return_number;
	char	*buffer;
}				t_list;

int				get_next_line(int fd, char **line);

int				get_line_break(char *final);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
int				return_if_null(char *final);
char			*ft_strjoin(char *s1, char const *s2);

#endif
