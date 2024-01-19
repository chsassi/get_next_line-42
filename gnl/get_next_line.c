/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:08 by chsassi           #+#    #+#             */
/*   Updated: 2023/12/13 14:23:48 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_find_nl(char **res, char **waste, char *line, int bytes)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (bytes == 0 && (!*res || !(**res)))
	{
		free(*res);
		*res = NULL;
		return (1);
	}
	i = strchr_idx(line, '\n');
	if (i == -1)
		tmp = strjoin_gnl(&tmp, line);
	else
	{
		tmp = substr_gnl(line, 0, i);
		*waste = strjoin_gnl(waste, line + i + 1);
	}
	*res = strjoin_gnl(res, tmp);
	free(tmp);
	return (i > -1);
}

static void	read_until_nl(int fd, char **res, char **waste, int bytes)
{
	char	*line;

	line = calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return ;
	while (bytes > 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		line[bytes] = '\0';
		if (ft_find_nl(res, waste, line, bytes))
			break ;
	}
	free(line);
}

char	*get_next_line(int fd)
{
	static char	*waste = NULL;
	char		*tmp;
	char		*res;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	res = NULL;
	bytes = 1;
	if (waste != NULL)
	{
		tmp = strjoin_gnl(&waste, NULL);
		bytes = !ft_find_nl(&res, &waste, tmp, 1);
		free(tmp);
	}
	read_until_nl(fd, &res, &waste, bytes);
	return (res);
}

/* int	main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	char	*res;

 	while (42)
	{
		res = get_next_line(fd);
		if (res)
		{
			printf("%s", res);
			free(res);
		}
		else
			break ;
	}
	printf("%s", get_next_line(fd));
	close(fd);
} */