/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:25:37 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 11:26:15 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_on_struct(t_datamap *datamap)
{
	datamap->tile.img = put_xmp(datamap->data.mlx,
			"assets/tile.xpm", &datamap->tile.width, &datamap->tile.height);
	datamap->babbo.img = put_xmp(datamap->data.mlx,
			"assets/babbo.xpm", &datamap->babbo.width, &datamap->babbo.height);
	datamap->wall.img = put_xmp(datamap->data.mlx,
			"assets/wall.xpm", &datamap->wall.width, &datamap->wall.height);
	datamap->exit.img = put_xmp(datamap->data.mlx,
			"assets/exit.xpm", &datamap->exit.width, &datamap->exit.height);
	datamap->collectible.img = put_xmp(datamap->data.mlx,
			"assets/collectible.xpm", &datamap->collectible.width,
			&datamap->collectible.height);
	datamap->black.img = put_xmp(datamap->data.mlx,
			"assets/black.xpm", &datamap->black.width, &datamap->black.height);
	datamap->enemy.img = put_xmp(datamap->data.mlx,
			"assets/enemy.xpm", &datamap->enemy.width, &datamap->enemy.height);
	datamap->tile25.img = put_xmp(datamap->data.mlx,
			"assets/til2.xpm", &datamap->tile25.width, &datamap->tile25.height);
	datamap->tile50.img = put_xmp(datamap->data.mlx,
			"assets/til5.xpm", &datamap->tile50.width, &datamap->tile50.height);
	datamap->tile75.img = put_xmp(datamap->data.mlx,
			"assets/til7.xpm", &datamap->tile75.width, &datamap->tile75.height);
	datamap->wall_light.img = put_xmp(datamap->data.mlx,
			"assets/wall_light.xpm", &datamap->wall_light.width,
			&datamap->wall_light.height);
}
