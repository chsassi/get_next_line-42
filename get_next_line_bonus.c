/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:08 by chsassi           #+#    #+#             */
/*   Updated: 2023/12/13 14:23:48 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	i = ft_strchr(line, '\n');
	if (i == -1)
		tmp = ft_strjoin(&tmp, line);
	else
	{
		tmp = ft_substr(line, 0, i);
		*waste = ft_strjoin(waste, line + i + 1);
	}
	*res = ft_strjoin(res, tmp);
	free(tmp);
	return (i > -1);
}

static void	read_until_nl(int fd, char **res, char **waste, int bytes)
{
	char	*line;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
	static char	*waste[4096] = {NULL};
	char		*tmp;
	char		*res;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	res = NULL;
	bytes = 1;
	if (waste[fd] != NULL)
	{
		tmp = ft_strjoin(&waste[fd], NULL);
		bytes = !ft_find_nl(&res, &waste[fd], tmp, 1);
		free(tmp);
	}
	read_until_nl(fd, &res, &waste[fd], bytes);
	return (res);
}

/* int main(int ac, char **av)
{
	int fd = open("text.txt", O_RDONLY);
	int fd2 = open("text.txt", O_RDONLY);
	char *s;
	char *s2;

	(void)av;
	if (ac % 2 == 0){
		for (int i = 0; i < 5; i ++){
			s = get_next_line(fd);
			s2 = get_next_line(fd);
			printf("FILE[1] LINE[%d][%s]", i + 1, s);
			printf("FILE[2] LINE[%d][%s]", i + 1, s2);
			free(s);
			free(s2);
		}
		return (0);
	}
	int line = 1;
	for (char *s= get_next_line(fd), *s2 = get_next_line(fd2); 
			s; s = get_next_line(fd), s2 = get_next_line(fd2)){
		printf("FILE[1] LINE[%d][%s]", line, s);
		printf("FILE[2] LINE[%d][%s]", line++, s2);
		free(s);
		free(s2);
	}
}  */