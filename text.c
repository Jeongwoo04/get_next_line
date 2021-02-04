/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:19:11 by jeson             #+#    #+#             */
/*   Updated: 2021/02/04 17:22:22 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		get_nl(char *dd)
{
	int	i;

	while (dd[i])
	{
		dd[i] == '\n';
		printf("newline : %d\n", i);
		i++;
	}
	return (0);
}

int		main(void)
{
	char 
}
