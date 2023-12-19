/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/19 15:52:40 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_image	wall;

	if (argc != 2)
		return (write(2, "Error: wrong number of arguments\n", 33));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (-1);
	data.win = mlx_new_window(data.mlx, 64, 64, "hi :)");
	if (!data.win)
		return (free(data.mlx), 1);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	wall.img = put_xmp(data.mlx, "assets/tile.xpm", &wall.width, &wall.height);
	mlx_put_image_to_window(data.mlx, data.win, wall.img, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, wall.img, 0, 32);
	//put_map(argv[1], &data);
	mlx_loop(data.mlx);
	return (0);
}
