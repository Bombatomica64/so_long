/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:41:23 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 19:14:04 by lmicheli         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(char *filename)
{
	t_line	line;
	int		count;
	int		fd;

	fd = open(filename, O_RDONLY);
	count = 0;
	line.read_bytes = 1;
	while (line.read_bytes > 0)
	{
		line.line = get_next_line(fd);
		line.read_bytes = ft_strlen(line.line);
		count++;
		free(line.line);
	}
	close(fd);
	return (count);
}

t_map	get_map(char *filename)
{
	t_map	map;
	int		fd;
	int		i;

	map.height = ft_count_lines(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	map.map = malloc(sizeof(char *) * (map.height + 1));
	while (i < map.height)
	{
		map.map[i] = get_next_line(fd);
		if (map.width == 0)
			map.width = ft_strlen(map.map[i]);
		i++;
	}
	map.map[i] = NULL;
	close(fd);
	return (map);
}

void	ft_check_if_map_is_valid(t_map map)
{
	int	i;

	i = map_is_closed(map);
}

int	put_map(char *filename, t_data *data)
{
	t_image	tile;
	t_image	wall;
	t_map	map;

	tile.img = put_xmp(data->mlx, "assets/tile.xpm", &tile.width, &tile.height);
	wall.img = put_xmp(data->mlx, "assets/wall.xpm", &wall.width, &wall.height);
	if (map_checker(filename) == 0)
		ft_error_free_map(&tile, &wall, data);
	map = get_map(filename);
	ft_check_if_map_is_valid(map);
}
