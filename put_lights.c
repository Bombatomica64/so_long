/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:15:06 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 17:20:24 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* 
void	ft_remove_light(t_datamap *data, t_enemy *enemy)
{
	int	x;
	int	y;

	x = enemy->x / 32;
	y = enemy->y / 32;
	if (data->map.map[y + 1][x] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, enemy->x, enemy->y);
		data->map.map[y + 1][x] = '0';
	}
	else if (data->map.map[y - 1][x] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, enemy->x, enemy->y);
		data->map.map[y - 1][x] = '0';
	}
	else if (data->map.map[y][x + 1] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, enemy->x, enemy->y);
		data->map.map[y][x + 1] = '0';
	}
	else if (data->map.map[y][x - 1] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, enemy->x, enemy->y);
		data->map.map[y][x - 1] = '0';
	}
} */

void	ft_process_columns(t_datamap *data, int x, int y, int offset, int i)
{
	int	j;

	j = (x / 32) - offset;
	while (j <= (x / 32) + offset)
	{
		if (j < 0 || j >= data->map.width)
		{
			j++;
			continue ;
		}
		if (data->map.map[i][j] == '0')
		{
			mlx_put_image_to_window(data->data.mlx, data->data.win,
				data->black.img, j * 32, i * 32);
			data->map.map[i][j] = '0';
		}
		if (data->map.map[i][j] == '1' || data->map.map[i][j] == 'E'
			|| data->map.map[i][j] == 'C')
			mlx_put_image_to_window(data->data.mlx, data->data.win,
				data->black.img, j * 32, i * 32);
		if (data->map.map[i][j] == 'W')
			mlx_put_image_to_window(data->data.mlx, data->data.win,
				data->wall_light.img, j * 32, i * 32);
		j++;
	}
}

void	ft_rem_lights(t_datamap *data, int x, int y, int offset)
{
	int		i;

	i = (y / 32) - offset;
	while (i <= (y / 32) + offset)
	{
		if (i < 0 || i >= data->map.height)
		{
			i++;
			continue ;
		}
		ft_process_columns(data, x, y, offset, i);
		i++;
	}
}

/* void	ft_flooding_light_w(t_datamap *data, int x, int y, int radius)
{
	int	map_x;
	int	map_y;

	map_x = x / 32;
	map_y = y / 32;
	if (radius < 0 || x < 0 || y < 0 || x >= data->map.width * 32
		|| y >= data->map.height * 32 || data->map.map[map_y][map_x] == 'W')
		return ;
	if (data->map.map[map_y][map_x] == 'C')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->collectible.img, x, y);
		return ;
	}
	if (data->map.map[map_y][map_x] == 'E')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->exit.img, x, y);
		return ;
	}
	else if (data->map.map[map_y][map_x] == '1')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->wall.img, x , y);
		return ;
	}
	else if (data->player.x == x && data->player.y == y)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->babbo.img, x, y);
	}
	else if (radius == 3)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->tile75.img, x, y);
	}
	else if (radius == 2)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->tile50.img, x, y);
	}
	else if (radius == 1)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->tile25.img, x, y);
	}
	ft_flooding_light_w(data, x + 32, y, radius - 1);
	ft_flooding_light_w(data, x - 32, y, radius - 1);
	ft_flooding_light_w(data, x, y + 32, radius - 1);
	ft_flooding_light_w(data, x, y - 32, radius - 1);

 */