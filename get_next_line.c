/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:20 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/17 18:15:36 by asplavni         ###   ########.fr       */
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
void ft_strlcpy()
{

}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*safe_place;
	char		*show_next_line;

	buf = malloc(5);
	safe_place = malloc(1);
	show_next_line = malloc(looking_for_a_next_line);

	read(fd, buf, 5);

	safe_place = ft_strjoin(safe_place, buf);
	free(buf);


	return (safe_place);
}
