/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:59:04 by sbritani          #+#    #+#             */
/*   Updated: 2023/03/06 10:59:57 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**read_lines(char *path)
{
	int		fd;
	char	**res;
	char	*line;
	int		i;

	res = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = readline(fd);
	i = 0;
	while (line)
	{
		res = add_string_to_string_arr(line, res, i);
		i++;
		line = readline(fd);
	}
	return (res);
}
