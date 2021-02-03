/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:46:26 by jeson             #+#    #+#             */
/*   Updated: 2021/02/03 16:38:54 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					get_nl(char *save_backup)
{
	int				i;

	i = 0;
	while (save_backup[i])
	{
		if (save_backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int					get_line(char **save_backup, char **line, int idx_nl)
{
	char			*tmp_backup;
	int				res_len;

	(*save_backup)[idx_nl] = '\0';
	*line = ft_strdup(*save_backup);
	if ((res_len = ft_strlen(*save_backup + idx_nl + 1)) == 0)
	{
		free(*save_backup);
		*save_backup = 0;
		return (1);
	}
	tmp_backup = ft_strdup(*save_backup + idx_nl + 1);
	free(*save_backup);
	*save_backup = tmp_backup;
	return (1);
}

int					get_res(char **save_backup, char **line,
		int size_of_read)
{
	int				idx_nl;

	if (size_of_read < 0)
		return (-1);
	if (*save_backup && (idx_nl = get_nl(*save_backup)) >= 0)
		return (get_line(save_backup, line, idx_nl));
	else if (*save_backup)
	{
		*line = *save_backup;
		*save_backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				size_of_read;
	static char		*save_backup[OPEN_MAX];
	int				idx_nl;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size_of_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_of_read] = '\0';
		save_backup[fd] = ft_strjoin(save_backup[fd], buf);
		if ((idx_nl = get_nl(save_backup[fd])) >= 0)
			return (get_line(&save_backup[fd], line, idx_nl));
	}
	return (get_res(&save_backup[fd], line, size_of_read));
}
