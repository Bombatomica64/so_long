/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:49 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 17:43:56 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_player(t_datamap *data, void *img, int dr_x, int dr_y)
{
	int	a;

	a = ft_check_block(data, data->player.x + dr_x, data->player.y + dr_y);
	if (a == 0)
	{
		data->moves_happened = 1;
		ft_rem_lights(data, data->player.x, data->player.y, 3);
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			img, data->player.x + dr_x, data->player.y + dr_y);
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, data->player.x, data->player.y);
		data->player.x += dr_x;
		data->player.y += dr_y;
		if (data->map.map[data->player.y / 32][data->player.x / 32] == '0')
		{
			data->map.map[data->player.y / 32][data->player.x / 32] = 'P';
			if (data->map.map[data->player.y / 32 - dr_y / 32]
				[data->player.x / 32 - dr_x / 32] != 'E')
				data->map.map[data->player.y / 32 - dr_y / 32]
				[data->player.x / 32 - dr_x / 32] = '0';
		}
		ft_flood_light(data, data->player.x - dr_x, data->player.y - dr_y, 3);
	}
	else if (a == 1)
		ft_crash_animation(data, data->player.x, data->player.y);
}

void	ft_printmoves(t_datamap *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < 14)
	{
		i = 0;
		while (i < 110)
		{
			mlx_pixel_put(data->data.mlx, data->data.win,
				15 + i, data->map.height * 32 - 15 + j, 0x000000);
			i++;
		}
		j++;
	}
	free(data->moves_str);
	data->moves_str = ft_itoa(data->moves);
	if (!data->moves_str)
		return ;
	data->moves_str = ft_strjoin2("Moves done : ", data->moves_str);
	mlx_string_put(data->data.mlx, data->data.win, 20,
		data->map.height * 32 - 4, 0xFFFFFF, data->moves_str);
}

void	ft_print_map(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			ft_printf("%c", map.map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	ft_movement_e(t_datamap *data, void *img, int dr_x, int dr_y)
{
	if (ft_check_block_e(data, data->enemies->x + dr_x,
			data->enemies->y + dr_y) == 0)
	{
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			img, data->enemies->x + dr_x, data->enemies->y + dr_y);
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->black.img, data->enemies->x, data->enemies->y);
		data->enemies->x += dr_x;
		data->enemies->y += dr_y;
		if (data->map.map[data->enemies->y / 32][data->enemies->x / 32] == '0')
		{
			data->map.map[data->enemies->y / 32][data->enemies->x / 32] = 'N';
			if (data->map.map[data->enemies->y / 32 - dr_y / 32]
				[data->enemies->x / 32 - dr_x / 32] != 'E'
				&& data->map.map[data->enemies->y / 32 - dr_y / 32]
				[data->enemies->x / 32 - dr_x / 32] != 'C')
				data->map.map[data->enemies->y / 32 - dr_y / 32]
				[data->enemies->x / 32 - dr_x / 32] = '0';
		}
	}
	ft_flood_light_e(data, data->enemies->x, data->enemies->y, 2);
}
