/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/20 19:06:06 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_datamap *data)
{
	ft_error_free(data);
	return (0);
}

void	put_image_on_struct(t_datamap *datamap)
{
	datamap->tile.img = put_xmp(datamap->data.mlx,
			"assets/tile.xpm", &datamap->tile.width, &datamap->tile.height);
	datamap->babbo.img = put_xmp(datamap->data.mlx,
			"assets/babbo.xpm", &datamap->babbo.width, &datamap->babbo.height);
	datamap->wall.img = put_xmp(datamap->data.mlx,
			"assets/wall.xpm", &datamap->wall.width, &datamap->wall.height);
	datamap->exit.img = put_xmp(datamap->data.mlx,
			"assets/exit.xpm", &datamap->exit.width, &datamap->exit.height);
}

void	ft_move(t_datamap *datamap, int axis, int direction)
{
	if (direction < 0)
	{
		if (axis == 121)
		{
			if (ft_check_block(datamap, datamap->player.x, datamap->player.y - 32) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x, datamap->player.y - 32);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->tile.img, datamap->player.x, datamap->player.y);
				datamap->player.y -= 32;
			}
		}
		else if (axis == 120)
		{
			if (ft_check_block(datamap, datamap->player.x - 32, datamap->player.y) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x - 32, datamap->player.y);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->tile.img, datamap->player.x, datamap->player.y);
				datamap->player.x -= 32;
			}
		}
	}
	else if (direction > 0)
	{
		if (axis == 121)
		{
			if (ft_check_block(datamap, datamap->player.x, datamap->player.y + 32) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x, datamap->player.y + 32);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->tile.img, datamap->player.x, datamap->player.y);
				datamap->player.y += 32;
			}
		}
		else if (axis == 120)
		{
			if (ft_check_block(datamap, datamap->player.x + 32, datamap->player.y) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x + 32, datamap->player.y);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->tile.img, datamap->player.x, datamap->player.y);
				datamap->player.x += 32;
			}
			ft_printf("x: %d\n", datamap->player.x);
		}
	}
}

int	on_keypress(int keysym, t_datamap *datamap)
{
	if (keysym == 119)
		ft_move(datamap, 'y', -32);
	else if (keysym == 97)
		ft_move(datamap, 'x', -32);
	else if (keysym == 115)
		ft_move(datamap, 'y', 32);
	else if (keysym == 100)
		ft_move(datamap, 'x', 32);
	// else if (keysym == 65307)
	// 	ft_error_free(datamap);
	return (0);
}

int	main(int argc, char **argv)
{
	t_datamap	data;

	if (argc != 2)
		return (write(2, "Error: wrong number of arguments\n", 33));
	data.data.mlx = mlx_init();
	if (!data.data.mlx)
		return (-1);
	data.data.win = mlx_new_window(data.data.mlx, 600, 600, "hi :)");
	if (!data.data.win)
		return (free(data.data.mlx), 1);
	mlx_hook(data.data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	put_image_on_struct(&data);
	put_map(argv[1], &data);
	mlx_loop(data.data.mlx);
	return (0);
}
