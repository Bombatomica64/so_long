/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by tfalchi           #+#    #+#             */
/*   Updated: 2023/12/19 15:46:18 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free(t_image *tile, t_image *wall, t_data *data)
{
	if (tile)
	{
		tile->img = NULL;
		free(tile);
	}
	if (wall)
	{
		wall->img = NULL;
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
	exit(0);
}

void	ft_err_free_map(t_image *tile, t_image *wall, t_data *data, t_map *map)
{
	if (tile)
	{
		tile->img = NULL;
		free(tile->img);
	}
	if (wall)
	{
		wall->img = NULL;
		free(wall->img);
	}
	if (data)
	{
	// 	if (data->mlx)
	// 		free(data->mlx);
	// 	if (data->win)
	// 		free(data->win);
	// 	free(data);
	}
	if (map)
	{
		free_matrix(map->map);
	}
	write(2, "qua\n", 5);
	exit(0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
