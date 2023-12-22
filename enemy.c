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
	new_enemy->prev = NULL;
	if (*enemy == NULL)
		*enemy = new_enemy;
	else
	{
		temp = *enemy;
		while (temp->next)
			temp = temp->next;
		temp->next = new_enemy;
		new_enemy->prev = temp;
	}
}

void	ft_first_enemy(t_datamap *data)
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

void	ft_move_enemy(t_datamap *data, t_enemy *enemy, int dir, void *img)
{
	if (dir == 1)
		ft_movement_e(data, img, 0, -32);
	else if (dir == 2)
		ft_movement_e(data, img, -32, 0);
	else if (dir == 3)
		ft_movement_e(data, img, 0, 32);
	else if (dir == 4)
		ft_movement_e(data, img, 32, 0);
}

void	enemy_move(t_datamap *data)
{
	int	direction;

	ft_first_enemy(data);
	while (data->enemies)
	{
		direction = ft_random_number();
		ft_move_enemy(data, data->enemies, direction, data->enemy.img);
		data->enemies = data->enemies->next;
	}
}