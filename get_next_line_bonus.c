/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:02:14 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:15 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*last[10000];
	char		*str;
	int			i;

	i = 0;
	if (fd != 0)
		i = fd - 2;
	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	last[i] = ft_after_line(last[i], fd);
	if (last[i] == NULL || *last[i] == '\0')
	{
		free(last[i]);
		return (NULL);
	}
	str = ft_strdup(last[i], '\n', 0);
	last[i] = ft_strdup(last[i] + ft_strlen(str), '\0', ft_strlen(str));
	return (str);
}
