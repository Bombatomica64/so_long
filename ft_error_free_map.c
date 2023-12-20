/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by tfalchi           #+#    #+#             */
/*   Updated: 2023/12/20 19:55:50 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free(t_datamap *data)
{
	if (data->tile.img != NULL)
		mlx_destroy_image(data->data.mlx, data->tile.img);
	if (data->wall.img != NULL)
		mlx_destroy_image(data->data.mlx, data->wall.img);
	if (data->babbo.img != NULL)
		mlx_destroy_image(data->data.mlx, data->babbo.img);
	if (data->exit.img != NULL)
		mlx_destroy_image(data->data.mlx, data->exit.img);
	if (data->map.map != NULL)
		free_matrix(data->map.map);
	if (data->data.mlx != NULL)
	{
		mlx_destroy_window(data->data.mlx, data->data.win);
		mlx_destroy_display(data->data.mlx);
		free(data->data.mlx);
	}
	exit(0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
