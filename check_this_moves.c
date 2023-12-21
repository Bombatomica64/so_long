/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_this_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:42:02 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/21 11:10:36 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_block(t_datamap *datamap, int x, int y)
{
	if (datamap->map.map[y / 32][x / 32] == '1' || datamap->map.map[y / 32][x / 32] == 'W')
		return (1);
	else if (datamap->map.map[y / 32][x / 32] == 'C')
	{
		datamap->map.map[y / 32][x / 32] = '0';
		datamap->map.nb_c--;
	}
	else if (datamap->map.map[y / 32][x / 32] == 'E')
		if (datamap->map.nb_c == 0)
			ft_error_free(datamap);
	return (0);
}
