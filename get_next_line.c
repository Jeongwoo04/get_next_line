/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:46:26 by jeson             #+#    #+#             */
/*   Updated: 2021/02/04 17:34:45 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					get_nl(char *save_backup)
{
	int				i;

	i = 0;
	while (save_backup[i])
	{
		if (save_backup[i] == '\n')
		{
			printf("---New Line --- : %d 번째", i + 1);
			return (i);
		}
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

void	test_fd(char **buffer, char const *filename, int fd)
{
	int	r;

	if (fd == STDIN_FILENO)
		printf("Reading stdin...\n---\n");
	else
		printf("Reading %s...\n---\n", filename);
	while ((r = get_next_line(fd, buffer)) > 0)
	{
		printf("%2d-%s\n", r, *buffer);
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	if (r >= 0)
		printf("- End Of File - : X 없음 %d-%s\n---\n", r, *buffer);
	else
		printf("%2d#error\n---\n", r);
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

int
	main(void)
{
	char		*buffer = NULL;
	int			i, fd;
	int			test_count;
	char const	*tests[100] = {
		"test_file1",
		"test_file2",
		"test_file3",
		"test_file4",
		"test_file5",
		"test_file7",
		"test_file8",
		"test_file9",
		"test_file10",
		"test_file11",
		"test_file12",
		"test_file13",
		"test_file14",
		"test_file15",
		"test_file16",
		"test_file17",
		NULL
	};

	test_count = 0;
	while (tests[test_count])
		test_count++;
	i = 0;
	while (i < test_count)
	{
		fd = open(tests[i], O_RDONLY);
		test_fd(&buffer, tests[i++], fd);
		printf("%d\n", fd);
		close(fd);
	}
	test_fd(&buffer, "Invalid file descriptor", 42);
	test_fd(&buffer, NULL, STDIN_FILENO);
	return (0);
}
