/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:55:35 by lmicheli          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/12/18 16:56:10 by lmicheli         ###   ########.fr       */
=======
/*   Updated: 2023/12/18 18:24:39 by mruggier         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

<<<<<<< Updated upstream
int	map_checker(char *filename)
=======
int	map_checker(char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	retval = wrong_letters_in_map(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	retval = map_is_closed(fd, retval);
	if (retval == 0)
		return (retval);
}

int	wrong_letters_in_map(int fd)
{
	t_line	line;
	char	c;

	while (line.read_bytes > 0)
	{
		line.line = get_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		line.i = 0;
		while (line.line[line.i])
		{
			c = line.line[line.i];
			if (c != '1' && c != '0' && c != 'N' && c != 'C'
				&& c != 'E' && c != 'P' && c != '\n')
			{
				free(line.line);
				return (0);
			}
			line.i++;
		}
		free(line.line);
	}
	return (1);
}

int	map_is_closed(int fd, int retval)
{
	t_line		line;
	t_map		map;
	int			tile_count;

	if (retval == 0)
		return (retval);
	tile_count = 0;
	map.width = 0;
	while (line.read_bytes > 0)
	{
		line.line = get_next_line(fd);
		line.read_bytes = ft_strlen(line.line);ft_flood_fill
		if (map.width == 0)
			map.width = line.read_bytes;
		map.height++;
		tile_count += line.read_bytes;
		free(line.line);
	}
	if (tile_count != map.width * map.height)
		return (0);
	return (1);
}
>>>>>>> Stashed changes
