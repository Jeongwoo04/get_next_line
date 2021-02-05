/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:09:44 by jeson             #+#    #+#             */
/*   Updated: 2021/02/05 16:24:04 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t			ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t			ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t		dest_len;
	size_t		src_len;
	size_t		i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && (dest_len + 1 + i < dstsize))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dstsize < dest_len)
		return (dstsize + src_len);
	return (dest_len + src_len);
}

char			*ft_strdup(char *s1)
{
	char		*res;
	int			i;

	i = ft_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	int			s1_len;
	int			s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(res, s1, s1_len + 1);
	free(s1);
	ft_strlcat(res + s1_len, s2, s2_len + 1);
	return (res);
}

int		main(void)
{
	static char	*aa[5];
	char		*s;
	char		*t;

	s = "567";
	t = "890";
	aa[0] = "123";
	printf("%p\n", &aa[0]);
	printf("%s\n", aa[0]);
	printf("%c\n", aa[0][0]);
	aa[1] = ft_strjoin(aa[1], s);
	printf("%s\n", aa[1]);
	printf("%p\n", &aa[1]);
	printf("%p\n", &aa[2]);
	free(aa[1]);
	aa[1] = ft_strjoin(aa[1], t);
	printf("%s\n", aa[1]);
	printf("%p\n", &aa[1]);
	printf("%p\n", &aa[2]);
	return (0);
}
