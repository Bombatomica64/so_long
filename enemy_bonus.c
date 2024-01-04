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

void	ft_add_enemy(t_enemy **enemy, int x, int y)
{
	t_enemy	*new_enemy;
	t_enemy	*temp;

	new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!new_enemy)
		return ;
	new_enemy->x = 32 * x;
	new_enemy->y = 32 * y;
	new_enemy->next = NULL;
	if (*enemy == NULL)
	{
		new_enemy->prev = NULL;
		*enemy = new_enemy;
	}
	else
	{
		temp = *enemy;
		while (temp->next)
			temp = temp->next;
		temp->next = new_enemy;
		new_enemy->prev = temp;
	}
}
/*void	ft_first_enemy(t_datamap *data)  da cancellare

void	ft_first_enemy(t_datamap *data)

{
	while (data->enemies && data->enemies->prev)
	{
		data->enemies = data->enemies->prev;
	}

}*/

int	ft_random_number(void)
{
	return (rand() % 4 + 1);
}

void	ft_move_enemy(t_datamap *data, int dir, void *img)
{
	if (dir == 1)
		ft_movement_e(data, img, 0, -32);
	else if (dir == 2)
		ft_movement_e(data, img, -32, 0);
	else if (dir == 3)
		ft_movement_e(data, img, 0, 32);
	else if (dir == 4)
		ft_movement_e(data, img, 32, 0);
	if (data->map.nb_c == 0)
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->exit.img, data->map.x, data->map.y);
}

void	enemy_move(t_datamap *data)
{
	int			direction;
	t_enemy		*first_enemy;

	while (data->enemies->prev)
		data->enemies = data->enemies->prev;
	first_enemy = data->enemies;
	while (data->enemies)
	{
		ft_rem_lights(data, data->enemies->x, data->enemies->y, 3);
		data->enemies = data->enemies->next;
	}
	data->enemies = first_enemy;
	while (data->enemies)
	{
		direction = ft_random_number();
		ft_move_enemy(data, direction, data->enemy.img);
		data->enemies = data->enemies->next;
	}
	data->enemies = first_enemy;
}
/*
while (datamap->enemies->next)
	{
		ft_rem_lights(datamap, datamap->enemies->x, datamap->enemies->y, 2);
		datamap->enemies = datamap->enemies->next;
	}*/