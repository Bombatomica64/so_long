/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_this_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:42:02 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 16:40:34 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_block(t_datamap *datamap, int x, int y)
{
	if (datamap->map.map[y / 32][x / 32] == '1'
		|| datamap->map.map[y / 32][x / 32] == 'W')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'C')
	{
		datamap->map.map[y / 32][x / 32] = '0';
		datamap->map.nb_c--;
		ft_1_to_w(datamap, x, y);
	}
	else if (datamap->map.map[y / 32][x / 32] == 'E')
		if (datamap->map.nb_c == 0)
			ft_error_free(datamap);
	datamap->moves_happened = 1;
	return (0);
}

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
