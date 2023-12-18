/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by tfalchi           #+#    #+#             */
/*   Updated: 2023/12/18 17:29:31 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free_map(t_data **tile, t_data **wall, void (*del)(void*))
{
	if (tile)
	{
		tile->mlx = NULL;
		tile->win = NULL;
		free(tile);
	}
	if (wall)
	{
		wall->mlx = NULL;
		wall->win = NULL;
		free(wall);
	}
	if (data)
	{
		if (data->mlx)
			free(data->mlx);
		if (data->win)
			free(data->win);
		free(data);
	}
	write(2, "Errore di mappa\n", 6);
}
