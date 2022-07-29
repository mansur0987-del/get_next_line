/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:02:33 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:33 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*last;
	char		*str;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	last = ft_after_line(last, fd);
	if (last == NULL || *last == '\0')
	{
		free(last);
		return (NULL);
	}
	str = ft_strdup(last, '\n', 0);
	last = ft_strdup(last + ft_strlen(str), '\0', ft_strlen(str));
	return (str);
}
