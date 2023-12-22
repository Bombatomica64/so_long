/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_this_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:42:02 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 12:27:03 by lmicheli         ###   ########.fr       */
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

void	ft_1_to_w_recursive(t_datamap *datamap, int x, int y, int i, int j)
{
	if (j < 0)
		j = 0;
	if (i < 0)
		i = 0;
	if (j > y + 96 || j / 32 >= datamap->map.height)
		return ;
	if (i > x + 96 || i / 32 >= datamap->map.width)
	{
		ft_1_to_w_recursive(datamap, x, y, x - 96, j + 32);
		return ;
	}
	if (datamap->map.map[j / 32][i / 32] == '1')
	{
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->wall_light.img, j, i);
		datamap->map.map[j / 32][i / 32] = 'W';
	}
	ft_1_to_w_recursive(datamap, x, y, i + 32, j);
}

void	ft_1_to_w(t_datamap *datamap, int x, int y)
{
	ft_1_to_w_recursive(datamap, x, y, x - 96, y - 96);
}
