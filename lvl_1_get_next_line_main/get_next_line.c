/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:37:22 by marvin            #+#    #+#             */
/*   Updated: 2021/02/10 04:34:36 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main()
{
	int fd;
	int fd2;
	char *line;

	fd = open("texto.txt", O_RDONLY);
	fd2 = open("texto3.txt", O_RDONLY);

	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
}
