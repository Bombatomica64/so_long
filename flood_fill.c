/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:25:38 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/19 15:39:21 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_reachable(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'E')
				map.nb_e++;
			if (map.map[y][x] == 'C')
				map.nb_c++;
			if (map.map[y][x] == 'P')
				map.nb_p++;
			x++;
		}
		y++;
	}
	if (map.nb_e != 1 || map.nb_c < 1 || map.nb_p != 1)
		return (0);
	ft_flood_fill(&map, 0, 0);
	if (map.nb_c == 0 && map.nb_e == 0 && map.nb_p == 0)
		return (1);
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
	else
	{
		map->map[y][x] = 'L';
		ft_flood_fill (map, y + 1, x);
		ft_flood_fill (map, y - 1, x);
		ft_flood_fill (map, y, x - 1);
		ft_flood_fill (map, y, x + 1);
	}
}
