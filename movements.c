/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:26:49 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 12:28:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_player(t_datamap *data, void *img, int dr_x, int dr_y)
{
	if (ft_check_block(data, data->player.x + dr_x, data->player.y + dr_y) == 0)
	{
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
		ft_flood_light(data, data->player.x - dr_x, data->player.y - dr_y);
	}
}

void	ft_printmoves(t_datamap *datamap)
{
	mlx_string_put(datamap->data.mlx, datamap->data.win, 64,
		datamap->map.height * 32 + 32, 0x000000, datamap->moves_str);
	free(datamap->moves_str);
	datamap->moves_str = ft_itoa(datamap->moves);
	if (!datamap->moves_str)
		return ;
	datamap->moves_str = ft_strjoin2("Moves done : ", datamap->moves_str);
	mlx_string_put(datamap->data.mlx, datamap->data.win, 64,
		datamap->map.height * 32 + 32, 0xFFFFFF, datamap->moves_str);
}
