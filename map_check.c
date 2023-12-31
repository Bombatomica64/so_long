/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:55:35 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/02 17:07:40 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (0);
	retval = wrong_letters_in_map(fd);
	close(fd);
	if (retval == 0)
	{
		write(2, "Error Wrong letters in map\n", 27);
		return (0);
	}
	fd = open(filename, O_RDONLY);
	retval = map_is_rectangular(fd, retval);
	if (retval == 0)
	{
		write(2, "Error Map is not rectangular\n", 29);
		return (retval);
	}
	close(fd);
	return (retval);
}

int	wrong_letters_in_map(int fd)
{
	t_line	line;
	char	c;
	int		wrongletter;

	wrongletter = 0;
	c = 0;
	line.read_bytes = 1;
	while (line.read_bytes > 0)
	{
		line.line = bad_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		line.i = 0;
		while (line.i < line.read_bytes)
		{
			c = line.line[line.i];
			if (c != '1' && c != '0' && c != 'N' && c != 'C'
				&& c != 'E' && c != 'P')
				wrongletter = 1;
			line.i++;
		}
		free(line.line);
	}
	if (wrongletter == 1)
		return (0);
	return (1);
}

int	map_is_rectangular(int fd, int retval)
{
	t_line		line;
	t_map		map;
	int			tile_count;

	if (retval == 0)
		return (retval);
	tile_count = 0;
	map.width = 0;
	map.height = 0;
	line.read_bytes = 1;
	while (line.read_bytes > 0)
	{
		line.line = bad_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		if (line.read_bytes == 0)
			break ;
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

int	map_is_closed(t_map map)
{
	int	i;

	i = 0;
	while (map.map[0][i])
	{
		if (map.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map.map[map.height - 1][i])
	{
		if (map.map[map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map.map[i])
	{
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
