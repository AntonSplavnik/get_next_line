/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:01:10 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/20 20:02:44 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <aio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//main
int		main(int argc, char **argv);

//get_next_line
char	*get_next_line(int fd);

//utils
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *stash, char *buff);
char	*extract_line(char *left_str);
char	*clean_stash(char *left_str);

#endif