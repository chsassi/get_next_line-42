/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:24 by chsassi           #+#    #+#             */
/*   Updated: 2023/12/04 16:46:25 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
int		strlen_gnl(char *str);
void	*calloc_gnl(size_t nmemb, size_t size);
char	*strjoin_gnl(char **s1, char *s2);
int		strchr_idx(char *s, int c);
char	*substr_gnl(char *s, size_t start, size_t end);

#endif