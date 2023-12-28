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

void	ft_destroy_images(t_datamap *data)
{
	t_image		*imgs[11];
	int			i;

	imgs[0] = &data->tile;
	imgs[1] = &data->tile25;
	imgs[2] = &data->tile50;
	imgs[3] = &data->tile75;
	imgs[4] = &data->babbo;
	imgs[5] = &data->wall;
	imgs[6] = &data->wall_light;
	imgs[7] = &data->enemy;
	imgs[8] = &data->exit;
	imgs[9] = &data->collectible;
	imgs[10] = &data->black;
	i = 0;
	while (i < sizeof(imgs) / sizeof(t_image *))
	{
		if (imgs[i]->img != NULL)
			mlx_destroy_image(data->data.mlx, imgs[i]->img);
		i++;
	}
}

void	ft_free_map_and_enemies(t_datamap *data)
{
	if (data->map.map != NULL)
		free_matrix(data->map.map);
	if (data->enemies != NULL)
		ft_free_enemy(data);
}

void	ft_free_moves_and_mlx(t_datamap *data)
{
	if (data->moves_str != NULL)
		free(data->moves_str);
	if (data->data.mlx != NULL)
	{
		if (data->data.win != NULL)
			mlx_destroy_window(data->data.mlx, data->data.win);
		mlx_destroy_display(data->data.mlx);
		free(data->data.mlx);
	}
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

	while (data->enemies->prev)
		data->enemies = data->enemies->prev;
	while (data->enemies)
	{
		tmp = data->enemies;
		data->enemies = data->enemies->next;
		free(tmp);
	}
}
