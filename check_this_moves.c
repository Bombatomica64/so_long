/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_this_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:42:02 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 17:12:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_block(t_datamap *datamap, int x, int y)
{
	if (datamap->map.map[y / 32][x / 32] == '1'
		|| datamap->map.map[y / 32][x / 32] == 'W')
	{
		datamap->moves_happened = 0;
		return (1);
	}
	else if (datamap->map.map[y / 32][x / 32] == 'C')
		got_a_collectable(datamap, x, y);
	else if (datamap->map.map[y / 32][x / 32] == 'N')
		got_a_enemy(datamap, x, y);
	else if (datamap->map.map[y / 32][x / 32] == '0')
		return (0);
	else if (datamap->map.map[y / 32][x / 32] == 'E')
	{
		got_a_exit(datamap, x, y);
		datamap->moves_happened = 0;
		return (1);
	}
	ft_print_map(datamap->map);
	return (0);
}

void	got_a_exit(t_datamap *datamap, int x, int y)
{
	if (datamap->map.nb_c == 0)
	{
		ft_error_free(datamap);
		ft_printf("You win\n");
	}
}

void	got_a_enemy(t_datamap *datamap, int x, int y)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
		datamap->enemy.img, x, y);
	while (i++ < 3200)
	{
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->end.img, 0, 0);
	}
	ft_printf("You lose\n");
	ft_error_free(datamap);
}

void	got_a_collectable(t_datamap *datamap, int x, int y)
{
	datamap->map.map[y / 32][x / 32] = '0';
	datamap->map.nb_c--;
	if (datamap->map.nb_c == 0)
	{
		coordinates_exit(datamap);
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->exit.img, datamap->map.x, datamap->map.y);
	}
	ft_1_to_w(datamap, x, y);
}

int	ft_check_block_e(t_datamap *datamap, int x, int y)
{
	if (datamap->map.map[y / 32][x / 32] == '1'
		|| datamap->map.map[y / 32][x / 32] == 'W'
		|| datamap->map.map[y / 32][x / 32] == 'N')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'C')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'E')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'P')
		got_a_enemy(datamap, x, y);
	else if (datamap->map.map[y / 32][x / 32] == '0')
		return (0);
	return (0);
}
