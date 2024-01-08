/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:19:31 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/04 14:09:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (keysym == XK_Escape)
		ft_error_free(datamap);
	enemy_move(datamap);
	ft_flood_light(datamap, 3);
	if (datamap->moves_happened == 1)
	{
		datamap->moves++;
		ft_printmoves(datamap);
	}
	return (0);
}

int	on_mouserelease(t_datamap *data)
{
	int	i;

	if (data->released == 0)
	{
		data->released = 1;
		i = 0;
		while (i++ < 1000)
			mlx_put_image_to_window(data->data.mlx, data->data.win,
				data->start1.img, 0, 0);
		mlx_hook(data->data.win, KeyRelease, KeyReleaseMask,
			&on_keypress, &data->data);
		mlx_hook(data->data.win, DestroyNotify, StructureNotifyMask,
			&on_destroy, data);
		ft_put_tile(data, data->map);
		ft_flood_light(data, 3);
		mlx_loop(data->data.mlx);
	}
	return (0);
}

int	on_mouseclick(t_datamap *data)
{
	if (data->clicked == 0)
	{
		data->clicked = 1;
		mlx_put_image_to_window(data->data.mlx, data->data.win,
			data->start2.img, 0, 0);
	}
	return (0);
}

int	on_esc(int keysym, t_datamap *datamap)
{
	if (keysym == XK_Escape)
		ft_error_free(datamap);
	return (0);
}

void	ft_key_input(t_datamap *data)
{
	mlx_hook(data->data.win, KeyPress, KeyPressMask,
		&on_esc, &data->data);
	mlx_hook(data->data.win, ButtonPress, ButtonPressMask,
		&on_mouseclick, &data->data);
	mlx_hook(data->data.win, ButtonRelease, ButtonReleaseMask,
		&on_mouserelease, &data->data);
	mlx_hook(data->data.win, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
	mlx_loop(data->data.mlx);
}
