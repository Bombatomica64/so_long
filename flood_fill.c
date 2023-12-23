/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:25:38 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/22 15:23:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_reachable(t_datamap data)
{
	t_map	map;

	if (data.map.nb_e != 1 || data.map.nb_c < 1 || data.map.nb_p != 1)
		return (0);
	ft_copy_map(&map, data.map);
	ft_flood_fill(&map, data.player.y / 32, data.player.x / 32);
	if (map.nb_c == 0 && map.nb_e == 0 && map.nb_p == 0)
	{
		free_matrix(map.map);
		return (1);
	}
	free_matrix(map.map);
	return (0);
}

void	ft_flood_fill(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->nb_c--;
	else if (map->map[y][x] == 'E')
		map->nb_e--;
	else if (map->map[y][x] == 'P')
		map->nb_p--;
	else if (map->map[y][x] == '1' || map->map[y][x] == 'L')
		return ;
	map->map[y][x] = 'L';
	ft_flood_fill (map, y + 1, x);
	ft_flood_fill (map, y - 1, x);
	ft_flood_fill (map, y, x - 1);
	ft_flood_fill (map, y, x + 1);
}

void	ft_copy_map(t_map *map_new, t_map map_old)
{
	int	y;

	y = 0;
	map_new->map = ft_calloc(sizeof(char *), (map_old.height + 1));
	while (map_old.map[y])
	{
		map_new->map[y] = ft_strdup(map_old.map[y]);
		y++;
	}
	map_new->nb_c = map_old.nb_c;
	map_new->nb_e = map_old.nb_e;
	map_new->nb_p = map_old.nb_p;
}
