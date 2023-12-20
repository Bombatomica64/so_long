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
		if (line.read_bytes == 0)
		{
			free(line.line);
			break ;
		}
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
	map.width = 0;
	fd = open(filename, O_RDONLY);
	i = 0;
	map.map = malloc(sizeof(char *) * (map.height + 1));
	while (i < map.height)
	{
		map.map[i] = bad_next_line(fd);
		if (map.width == 0)
			map.width = ft_strlen(map.map[i]);
		i++;
	}
	map.map[i] = NULL;
	close(fd);
	map.nb_c = 0;
	map.nb_e = 0;
	map.nb_p = 0;
	return (map);
}

int	ft_check_if_map_is_valid(t_datamap *data)
{
	if (map_is_closed(data->map) == 0)
	{
		ft_printf("Error Map is not closed\n");
		return (1);
	}
	if (ft_is_reachable(*data) == 0)
	{
		ft_printf("Error Map is not valid\n");
		return (1);
	}
	return (0);
}

void	ft_put_tile(t_datamap *data, t_map map)
{
	int			x;
	int			y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
				mlx_put_image_to_window(data->data.mlx, data->data.win,
					data->wall.img, x * 32, y * 32);
			else if (map.map[y][x] == '0')
				mlx_put_image_to_window(data->data.mlx, data->data.win,
					data->tile.img, x * 32, y * 32);
			else if (map.map[y][x] == 'P')
				mlx_put_image_to_window(data->data.mlx, data->data.win,
					data->babbo.img, x * 32, y * 32);
			else if (map.map[y][x] == 'C')
				mlx_put_image_to_window(data->data.mlx, data->data.win,
					data->tile.img, x * 32, y * 32);
			else if (map.map[y][x] == 'E')
				mlx_put_image_to_window(data->data.mlx, data->data.win,
					data->tile.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	put_map(char *filename, t_datamap *data)
{
	if (map_checker(filename) == 0)
		ft_error_free(data);
	data->map = get_map(filename);
	data->player = get_player(data->map);
	if (ft_check_if_map_is_valid(data) == 1)
		ft_error_free(data);
	data->data.win = mlx_new_window(data->data.mlx, data->map.width * 32,
			data->map.height * 32, "so_long");
	ft_put_tile(data, data->map);
	data->map.nb_c = get_collectibles(data->map);
	ft_error_free(data);
	mlx_hook(data->data.win, KeyRelease, KeyReleaseMask,
		&on_keypress, &data->data);
	mlx_hook(data->data.win, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
	mlx_loop(data->data.mlx);
	return (0);
}
/* 	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			printf("%c", map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	} */