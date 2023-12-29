/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:17:01 by mruggier          #+#    #+#             */
/*   Updated: 2023/12/29 18:17:10 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_crash_animation(t_datamap *datamap, int x, int y)
{
	int	wait;

	wait = 0;
	while (wait++ < 10)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->babbo.img, x, y);
	wait = 0;
	while (wait++ < 500)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->babbo1.img, x, y);
	wait = 0;
	while (wait++ < 10000)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->babbo2.img, x, y);
	wait = 0;
	while (wait++ < 500)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->babbo1.img, x, y);
	wait = 0;
	while (wait++ < 10)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->babbo.img, x, y);
}
