/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:53:52 by jeson             #+#    #+#             */
/*   Updated: 2021/01/26 15:12:13 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = 0;
	if (dstsize == 0)
		return (src_len);
	while (dest_len < dstsize && dest[dest_len])
		dest_len++;
	if (dstsize <= dest_len)
		return (dstzise + src_len);
	i = 0;
	while (dstsize && (--dstsize - dest_len) && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = ft_strlen(src);
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = ft_strlen(src);
	return (i);
}

char		*ft_strdup(char *s1)
{
	char	*res;
	size_t	i;

	i = ft_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (*s1)
	{
		*res++ = *s1++;
	}
	while (*s2)
		*++res = *s2++;
	*res = '\0';
	return (res);
}
