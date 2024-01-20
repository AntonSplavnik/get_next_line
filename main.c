/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:58:50 by asplavni          #+#    #+#             */
/*   Updated: 2024/01/20 16:21:12 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDWR);
	char	*test_result = get_next_line(fd);

	printf("Result: %s\n", test_result);
	return (0);
}
