/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:20 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/20 19:22:07 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	// void	clean_stash();

	// void	extract_line();

char	*read_and_stash(char *stash_on_heap, int fd)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(BUFFER_SIZE +1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (ft_strchr(stash_on_heap, '\n') != '\n' && rd_bytes != '\0')
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash_on_heap = ft_strjoin(stash_on_heap, buff);
	}
	free(buff);
	return (stash_on_heap);
}

char	*get_next_line(int fd)
{
	char		*line_to_show;
	static char	*stash_on_heap;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash_on_heap = read_and_stash(stash_on_heap, fd);
	if (!stash_on_heap)
		return (NULL);
	line_to_show = extract_line(stash_on_heap);
	stash_on_heap = clean_stash(stash_on_heap);
	return (0);
}
