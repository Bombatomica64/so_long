/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:40 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 15:46:16 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	get_player(t_map map)
{
	t_player	player;
	int			x;
	int			y;

	y = 0;
	player.x = 0;
	player.y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'P')
			{
				player.x = 32 * x;
				player.y = 32 * y;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}

int	get_collectibles(t_map map)
{
	int	x;
	int	y;
	int	collectibles;

	collectibles = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

int	get_exits(t_map map)
{
	int	x;
	int	y;
	int	exits;

	exits = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	return (exits);
}

int	get_player_nbr(t_map map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	return (player);
}

t_enemy	*get_enemies(t_map map)
{
	t_enemy	*enemy;
	int		x;
	int		y;

	enemy = NULL;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'N')
				ft_add_enemy(&enemy, x, y);
			x++;
		}
		y++;
	}
	return (enemy);
}
