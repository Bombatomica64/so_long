/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:59:16 by marvin            #+#    #+#             */
/*   Updated: 2023/12/20 22:59:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void   ft_first_enemy(t_datamap *data)
{
	while (data->enemies && data->enemies->prev)
	{
		data->enemies = data->enemies->prev;
	}
}

int	ft_random_number(void)
{
	return (rand() % 4 + 1);
}

int ft_check_block_e(t_datamap *datamap, int x, int y)
{
	if (datamap->map.map[y / 32][x / 32] == '1')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'C')
		return (2);
	else if (datamap->map.map[y / 32][x / 32] == 'E')
		return (3);
	else if (datamap->map.map[y / 32][x / 32] == 'P')
	{
		ft_printf("You lose\n");
		ft_error_free(datamap);
	}
	else if (datamap->map.map[y / 32][x / 32] == '0')
		return (0);
	return (0);
}

void	ft_move_enemy(t_datamap *datamap, t_enemy *enemy, int direction, void *enemy_img)
{
	if (direction == 1)
	{
		if (ft_check_block_e(datamap, enemy->x, enemy->y - 32) == 0)
		{
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				enemy_img, enemy->x, enemy->y - 32);
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				datamap->black.img, enemy->x, enemy->y);
			datamap->map.map[enemy->y / 32][enemy->x / 32] = '0';
			enemy->y -= 32;
			datamap->map.map[enemy->y / 32][enemy->x / 32] = 'N';
		}
	}
	else if (direction == 2)
	{
		if (ft_check_block_e(datamap, enemy->x - 32, enemy->y) == 0)
		{
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				enemy_img, enemy->x - 32, enemy->y);
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				datamap->black.img, enemy->x, enemy->y);
			datamap->map.map[enemy->y / 32][enemy->x / 32] = '0';
			enemy->x -= 32;
			datamap->map.map[enemy->y / 32][enemy->x / 32] = 'N';
		}
	}
	else if (direction == 3)
	{
		if (ft_check_block_e(datamap, enemy->x, enemy->y + 32) == 0)
		{
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				enemy_img, enemy->x, enemy->y + 32);
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				datamap->black.img, enemy->x, enemy->y);
			datamap->map.map[enemy->y / 32][enemy->x / 32] = '0';
			enemy->y += 32;
			datamap->map.map[enemy->y / 32][enemy->x / 32] = 'N';
		}
	}
	else if (direction == 4)
	{
		if (ft_check_block_e(datamap, enemy->x + 32, enemy->y) == 0)
		{
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				enemy_img, enemy->x + 32, enemy->y);
			mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
				datamap->black.img, enemy->x, enemy->y);
			datamap->map.map[enemy->y / 32][enemy->x / 32] = '0';
			enemy->x += 32;
			datamap->map.map[enemy->y / 32][enemy->x / 32] = 'N';
		}
	}
}

void	enemy_move(t_datamap *data)
{
	int	direction;

	ft_first_enemy(data);
	while (data->enemies)
	{
		direction = ft_random_number();
		ft_move_enemy(data, data->enemies, direction, data->enemy.img);
		ft_flooding_light(data, data->enemies->x, data->enemies->y, 1);
		data->enemies = data->enemies->next;
	}
}
