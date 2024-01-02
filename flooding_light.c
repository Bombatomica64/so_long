/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:44:25 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/30 20:00:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_datamap *data, t_player pos, t_image **imgs, int radius)
{
	int	map_x;
	int	map_y;

	map_x = pos.x / 32;
	map_y = pos.y / 32;
	if (data->map.map[map_y][map_x] == 'C')
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->collectible.img, pos.x, pos.y);
	else if (data->map.map[map_y][map_x] == 'E')
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->exit.img, pos.x, pos.y);
	else if (data->map.map[map_y][map_x] == '1')
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->wall.img, pos.x, pos.y);
	else if (data->map.map[map_y][map_x] == 'N')
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->enemy.img, pos.x, pos.y);
	else if (data->player.x == pos.x && data->player.y == pos.y)
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->babbo.img, pos.x, pos.y);
	else if (radius >= 1 && radius <= 3)
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			imgs[radius - 1]->img, pos.x, pos.y);
}

void	ft_recursive_light(t_datamap *data, t_player pos,
							t_image **imgs, int radius)
{
	t_player	new_pos;

	new_pos.x = pos.x + 32;
	new_pos.y = pos.y;
	ft_flooding_light(data, new_pos, imgs, radius - 1);
	new_pos.x = pos.x - 32;
	new_pos.y = pos.y;
	ft_flooding_light(data, new_pos, imgs, radius - 1);
	new_pos.x = pos.x;
	new_pos.y = pos.y + 32;
	ft_flooding_light(data, new_pos, imgs, radius - 1);
	new_pos.x = pos.x;
	new_pos.y = pos.y - 32;
	ft_flooding_light(data, new_pos, imgs, radius - 1);
}

void	ft_flooding_light(t_datamap *data, t_player pos,
							t_image **imgs, int radius)
{
	int	map_x;
	int	map_y;

	map_x = pos.x / 32;
	map_y = pos.y / 32;
	if (radius < 0 || pos.x < 0 || pos.y < 0 || pos.x >= data->map.width * 32
		|| pos.y >= data->map.height * 32 || data->map.map[map_y][map_x] == 'W')
	{
		return ;
	}
	ft_put_image(data, pos, imgs, radius);
	ft_recursive_light(data, pos, imgs, radius);
}

void	ft_flood_light(t_datamap *data, int x, int y, int radius)
{
	t_image		**imgs;
	t_player	player;

	imgs = malloc(sizeof(t_image *) * 3);
	imgs[0] = &data->tile25;
	imgs[1] = &data->tile50;
	imgs[2] = &data->tile75;
	player.x = data->player.x;
	player.y = data->player.y;
	ft_flooding_light(data, player, imgs, radius);
	free(imgs);
}

void	ft_flood_light_e(t_datamap *data, int x, int y, int radius)
{
	t_image		**imgs;
	t_player	enemy;

	imgs = malloc(sizeof(t_image *) * 3);
	imgs[0] = &data->tile25;
	imgs[1] = &data->tile50;
	imgs[2] = &data->tile75;
	enemy.x = x;
	enemy.y = y;
	ft_flooding_light(data, enemy, imgs, radius);
	free(imgs);
}
