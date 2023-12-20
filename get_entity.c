/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:40 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/20 16:35:09 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	get_player(t_map map)
{
	t_player	player;
	int			x;
	int			y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}
