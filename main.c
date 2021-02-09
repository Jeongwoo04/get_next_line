/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:58:26 by jeson             #+#    #+#             */
/*   Updated: 2021/02/09 17:59:05 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int 		main(void)
{
    char	*line = 0;
    int		ret;
    int		fd;
    int		i;
	i = 0;
	fd = open("test_file1", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s i = %d\n", line, i);
        free(line);
        i++;
    }
    printf("%s\n i = %d\n", line, i);
    free(line);
    while (1){
	}
    return (0);
}
