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

void	put_image_on_struct(t_datamap *data)
{
	data->tile.img = put_xmp(data->data.mlx,
			"assets/tile.xpm", &data->tile.width, &data->tile.height);
	data->babbo.img = put_xmp(data->data.mlx,
			"assets/babbo.xpm", &data->babbo.width, &data->babbo.height);
	data->wall.img = put_xmp(data->data.mlx,
			"assets/wall.xpm", &data->wall.width, &data->wall.height);
	data->exit.img = put_xmp(data->data.mlx,
			"assets/exit.xpm", &data->exit.width, &data->exit.height);
	data->collectible.img = put_xmp(data->data.mlx,
			"assets/collectible.xpm", &data->collectible.width,
			&data->collectible.height);
	data->black.img = put_xmp(data->data.mlx,
			"assets/black.xpm", &data->black.width, &data->black.height);
	data->enemy.img = put_xmp(data->data.mlx,
			"assets/enemy.xpm", &data->enemy.width, &data->enemy.height);
	data->tile25.img = put_xmp(data->data.mlx,
			"assets/til2.xpm", &data->tile25.width, &data->tile25.height);
	data->tile50.img = put_xmp(data->data.mlx,
			"assets/til5.xpm", &data->tile50.width, &data->tile50.height);
	data->tile75.img = put_xmp(data->data.mlx,
			"assets/til7.xpm", &data->tile75.width, &data->tile75.height);
	data->wall_light.img = put_xmp(data->data.mlx,
			"assets/wall_light.xpm", &data->wall_light.width,
			&data->wall_light.height);
	ft_more_images(data);
}

void	ft_more_images(t_datamap *data)
{
	data->babbo1.img = put_xmp(data->data.mlx,
			"assets/babbo1.xpm", &data->babbo1.width, &data->babbo1.height);
	data->babbo2.img = put_xmp(data->data.mlx,
			"assets/babbo2.xpm", &data->babbo2.width, &data->babbo2.height);
	data->start1.img = put_xmp(data->data.mlx,
			"assets/start1.xpm", &data->start1.width, &data->start1.height);
	data->start2.img = put_xmp(data->data.mlx,
			"assets/start2.xpm", &data->start2.width, &data->start2.height);
	data->end.img = put_xmp(data->data.mlx,
			"assets/end.xpm", &data->end.width, &data->end.height);
}
