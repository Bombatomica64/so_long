/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/20 18:14:48 by lmicheli         ###   ########.fr       */
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

void	ft_move(t_datamap datamap, int x, int y)
{
	mlx_put_image_to_window(datamap.data.mlx, datamap.data.win,
		datamap.babbo.img, x, y);
}

int	on_keypress(int keysym, t_datamap *datamap)
{
	static int	x = 0;
	static int	y = 0;

	put_image_on_struct(datamap);
	if (keysym == 119)
	{
		//y = ft_move(datamap, x, y - 32);
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->tile.img, x, y);
		ft_move(*datamap, x, y - 32);
		y -= 32;
        //mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->babbo.img, x, y);
	}
	else if (keysym == 97)
	{
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->tile.img, x, y);
		ft_move(*datamap, x - 32, y);
		x -= 32;
        //mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->babbo.img, x, y);
	}
	else if (keysym == 115) // 's'
	{
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->tile.img, x, y);
		ft_move(*datamap, x, y + 32);
		y += 32;
        //mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->babbo.img, x, y);
	}
	else if (keysym == 100)
	{
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->tile.img, x, y);
		ft_move(*datamap, x + 32, y);
		x += 32;
		//mlx_put_image_to_window(datamap->data.mlx, datamap->data.win, datamap->babbo.img, x, y);
	}
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
