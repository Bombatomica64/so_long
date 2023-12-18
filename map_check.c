/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:55:35 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 17:27:26 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char *filename)
{
	int		fd;
	t_line	line;
	t_map	map;
	char	*line;

	map.width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read_bytes > 0)
	{
		line = get_next_line(fd);
		read_bytes = ft_strlen(line);
		i = 0;
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != 'P')
				return (0);
			i++;
		}
		map.width += read_bytes;
		free(line);
	}
}
