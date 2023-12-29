/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:13:47 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/29 18:14:26 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_1_to_w(t_datamap *datamap, int x, int y)
{
	int		i;
	int		j;

	i = x - 128;
	j = y - 128;
	if (j < 0)
		j = 0;
	if (i < 0)
		i = 0;
	while (y + 128 > j && j / 32 < datamap->map.height)
	{
		while (x + 128 > i && i / 32 < datamap->map.width)
		{
			if (datamap->map.map[j / 32][i / 32] == '1')
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->wall_light.img, i, j);
				datamap->map.map[j / 32][i / 32] = 'W';
			}
			i += 32;
		}
		i = x - 128;
		j += 32;
	}
}

void	coordinates_exit(t_datamap *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'E')
			{
				data->map.x = x * 32;
				data->map.y = y * 32;
				return ;
			}
			x++;
		}
		y++;
	}
}
