/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:37:47 by jeson             #+#    #+#             */
/*   Updated: 2021/02/01 14:46:30 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	buf[OPEN_MAX];
	int		read_size;

	if (!(fd = open("text.txt", O_RDONLY)))
		return (0);
	if(!(read_size = read(fd, buf, BUFFER_SIZE)))
		return (0);
	printf("%d", read_size);
	return (0);
}
