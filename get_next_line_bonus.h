/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:48:43 by jeson             #+#    #+#             */
/*   Updated: 2021/02/08 15:22:28 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

int				get_next_line(int fd, char **line);

size_t			ft_strlen(char *s);
size_t			ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, char *src, size_t dstsize);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);

#endif
