/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:46:26 by jeson             #+#    #+#             */
/*   Updated: 2021/01/29 13:55:25 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_new_line(char *aa)
{
	int			i;

	i = 0;
	while (aa[i])
	{
		if (aa[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				ft_split_line(char **aa, char **line, int idx)
{
	char		*tmp;
	int			line_len;

	(*aa)[idx] = '\0';
	*line = ft_strdup(*aa);
	line_len = ft_strlen(*aa + idx + 1);
	if (line_len == 0)
	{
		free(*aa);
		*aa = 0;
		return (1);
	}
	tmp = ft_strdup(*aa + idx + 1);
	free(*aa);
	*aa = tmp;
	return (1);
}

int				ft_return(char **aa, char **line, int read_size)
{
	int			idx;

	if (read_size < 0)
		return (-1);
	if (*aa && (idx = ft_new_line(*aa)) >= 0)
		return (ft_split_line(aa, line, idx));
	else if (*aa)
	{
		*line = *aa;
		*aa = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*aa[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			idx;

	if ((fd < 0) || (line = 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		aa[fd] = ft_strjoin(aa[fd], buf);
		if ((idx = ft_new_line(aa[fd])) >= 0)
			return (ft_split_line(&aa[fd], line, idx));
	}
	return (ft_return(&aa[fd], line, read_size));
}
