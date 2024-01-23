/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:20 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/21 18:20:33 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_stash(char *stash, int fd)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(BUFFER_SIZE +1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(stash, '\n') && rd_bytes != '\0')
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line_to_show;
	static char	*stash[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	stash[fd] = read_and_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line_to_show = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line_to_show);
}

// int	main(int argc, char **argv)
// {
// 	int		file;
// 	int		file2;
// 	char	*temp;
// 	int		fd;

// 	(void)argc;
// 	(void)argv;
// 	file = open(argv[1], O_RDWR);
// 	file2= open(argv[2], O_RDWR);

// 	temp = get_next_line(file);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(file2);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(file);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(file2);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(file);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(file2);
// 	printf("%s", temp);
// 	close(file);
// 	close(file2);
// 	free(temp);
// }