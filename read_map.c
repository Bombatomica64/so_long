/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:41:23 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 16:57:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_map(char *filename, t_data *data)
{
	t_image	tile;
	t_image	wall;

	tile.img = put_xmp(data->mlx, "assets/tile.xpm", &tile.width, &tile.height);
	wall.img = put_xmp(data->mlx, "assets/wall.xpm", &wall.width, &wall.height);
	if (map_checker(filename) == 0)
		ft_error_free_map(tile, wall, data);
}
