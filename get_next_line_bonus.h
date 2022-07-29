/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:02:21 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/23 20:02:23 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
long	ft_strlen(char *str);
char	*ft_after_line(char *last, int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(char *src, char c, long g);
long	ft_search_line(char *str, char c);

#endif
