/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:15:06 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/21 10:35:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_light(t_datamap *data, t_enemy *enemy, int direction)
{
	if (direction == 1)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->enemy->img, enemy->x, 
			enemy->y - 32);
		data->map.map[enemy->y / 32][enemy->x / 32] = 'L' ;
	}
	else if (direction == 2)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->enemy->img, enemy->x - 32, enemy->y);
		data->map.map[enemy->y / 32][enemy->x / 32] = 'L' ;
	}
	else if (direction == 3)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->enemy->img, enemy->x, enemy->y + 32);
		data->map.map[enemy->y / 32][enemy->x / 32] = 'L' ;
	}
	else if (direction == 4)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->enemy->img, enemy->x + 32, enemy->y);
		data->map.map[enemy->y / 32][enemy->x / 32] = 'L' ;
	}
	//ft_flood_light(enemy, rand)
}

void	ft_remove_light(t_datamap *data, t_enemy *enemy)
{
	int	x;
	int	y;

	x = enemy->x / 32;
	y = enemy->y / 32;
	if (data->map.map[y + 1][x] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->black.img, enemy->x, enemy->y);
		data->map.map[y + 1][x] = '0';
	}
	else if (data->map.map[y - 1][x] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->black.img, enemy->x, enemy->y);
		data->map.map[y - 1][x] = '0';
	}
	else if (data->map.map[y][x + 1] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->black.img, enemy->x, enemy->y);
		data->map.map[y][x + 1] = '0';
	}
	else if (data->map.map[y][x - 1] == 'L')
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win, data->black.img, enemy->x, enemy->y);
		data->map.map[y][x - 1] = '0';
	}
}
