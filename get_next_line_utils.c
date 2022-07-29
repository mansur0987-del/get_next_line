/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:02:29 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:31 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_strlen(char *str)
{
	long	len;

	len = 0;
	while (str != NULL && str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src, char c, long g)
{
	char	*str;
	long	i;

	i = 0;
	if (!src || !ft_strlen(src))
	{
		free(src - g);
		return (NULL);
	}
	str = (char *) malloc(ft_strlen((char *) src) + 1);
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0' && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	if (c == '\0')
		free(src - g);
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	long	len_s1;
	long	len_s2;
	char	*output;

	if (*s2 == '\0')
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	output = (char *) malloc (sizeof(char) * (len_s1 + len_s2) + 1);
	if (output == NULL)
		return (NULL);
	len_s2 = -1;
	while (s1 != NULL && s1[++len_s2] != '\0')
		output[len_s2] = s1[len_s2];
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		output[len_s1++] = s2[len_s2++];
	output[len_s1] = '\0';
	free (s1);
	return (output);
}

long	ft_search_line(char *str, char c)
{
	long	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (i + 1);
	}
	return (0);
}

char	*ft_after_line(char *last, int fd)
{
	long	ret;
	char	*str;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	ret = 1;
	while (!ft_search_line(last, '\n') && ret > 0)
	{
		ret = read(fd, str, BUFFER_SIZE);
		if (ret < 0)
			free(str);
		if (ret < 0)
			return (NULL);
		str[ret] = '\0';
		if (ret != 0)
			last = ft_strjoin(last, str);
	}
	free (str);
	return (last);
}
