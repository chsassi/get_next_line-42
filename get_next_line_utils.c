/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:35 by chsassi           #+#    #+#             */
/*   Updated: 2023/12/04 16:46:36 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;
	int		s1_len;

	s1_len = ft_strlen(*s1);
	len = s1_len + ft_strlen(s2) + 1;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1 && i < s1_len)
		res[i++] = (*s1)[j++];
	j = 0;
	while (s2 && i < len)
		res[i++] = s2[j++];
	free(*s1);
	*s1 = NULL;
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	char	*ptr;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ptr = str;
	while (nmemb != 0)
	{
		*str = '\0';
		str++;
		nmemb--;
	}
	return (ptr);
}

int	ft_strchr(char *s, int c)
{
	int		i;
	int		slen;

	slen = ft_strlen(s);
	i = 0;
	while (s && i <= slen)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, size_t start, size_t end)
{
	char			*res;
	size_t			i;

	i = 0;
	res = ft_calloc((end - start + 1 + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (start <= end && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
