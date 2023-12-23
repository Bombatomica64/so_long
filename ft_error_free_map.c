/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by tfalchi           #+#    #+#             */
/*   Updated: 2023/12/22 14:52:19 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free(t_datamap *data)
{
	if (data->tile.img != NULL)
		mlx_destroy_image(data->data.mlx, data->tile.img);
	if (data->tile25.img != NULL)
		mlx_destroy_image(data->data.mlx, data->tile25.img);
	if (data->tile50.img != NULL)
		mlx_destroy_image(data->data.mlx, data->tile50.img);
	if (data->tile75.img != NULL)
		mlx_destroy_image(data->data.mlx, data->tile75.img);
	if (data->babbo.img != NULL)
		mlx_destroy_image(data->data.mlx, data->babbo.img);
	if (data->wall.img != NULL)
		mlx_destroy_image(data->data.mlx, data->wall.img);
	if (data->wall_light.img != NULL)
		mlx_destroy_image(data->data.mlx, data->wall_light.img);
	if (data->enemy.img != NULL)
		mlx_destroy_image(data->data.mlx, data->enemy.img);
	if (data->exit.img != NULL)
		mlx_destroy_image(data->data.mlx, data->exit.img);
	if (data->collectible.img != NULL)
		mlx_destroy_image(data->data.mlx, data->collectible.img);
	if (data->black.img != NULL)
		mlx_destroy_image(data->data.mlx, data->black.img);
	if (data->map.map != NULL)
		free_matrix(data->map.map);
	if (data->enemies != NULL)
		ft_free_enemy(data);
	if (data->moves_str != NULL)
		free(data->moves_str);
	if (data->data.mlx != NULL)
	{
		if (data->data.win != NULL)
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

void	ft_free_enemy(t_datamap *data)
{
	t_enemy	*tmp;

	while (data->enemies)
	{
		tmp = data->enemies;
		data->enemies = data->enemies->next;
		free(tmp);
	}
}
