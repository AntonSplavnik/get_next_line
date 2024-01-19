/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:20 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/19 19:37:33 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	looking_for_a_next_line(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (str[i] == '\n')
			return (i);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*show_next_line;

	buf = malloc(5);
	stash = malloc(1);
	show_next_line = malloc(looking_for_a_next_line);
	read(fd, buf, 5);
	stash = ft_strjoin(stash, buf);
	free(buf);
	//show_next_line = looking_for_a_next_line(stash);
	return (show_next_line);

	// void	read_and_stash();
	// void	add_to_stash();
	// void	extract_line();
	// void	clean_stash();
}
