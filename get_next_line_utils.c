/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:04:42 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/19 18:19:26 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	size_t			i;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	if (char_dest == 0 && char_src == 0)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i ++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_memcpy(new + s1_len, s2, s2_len + 1);
	free((char *)s1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;
	const char	*ptr;

	i = 0;
	ptr = src;
	src_len = 0;
	while (*src)
	{
		src_len++;
		src++;
	}
	if (size == 0)
		return (src_len);
	src = ptr;
	while (i < size - 1 && i < src_len)
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	*dst = '\0';
	return (src_len);
}
