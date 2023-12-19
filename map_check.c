/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:55:35 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/19 17:34:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	retval = wrong_letters_in_map(fd);
	close(fd);
	if (retval == 0)
	{
		write(2, "Error Wrong letters in map\n", 27);
		return (retval);
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

	c = 0;
	line.read_bytes = 1;
	while (line.read_bytes > 0)
	{
		line.line = get_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		line.i = 0;
		if (line.read_bytes == 0)
			break ;
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
		line.line = get_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		if (line.read_bytes == 0)
			break ;
		if (line.line[line.read_bytes - 1] == '\n')
			line.read_bytes--;
		if (map.width == 0)
			map.width = line.read_bytes;
		map.height++;
		tile_count += line.read_bytes;
		free(line.line);
	}
	ft_printf("tile_count = %d\n", tile_count);
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
