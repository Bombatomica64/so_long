/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 16:34:37 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_datamap *data)
{
	ft_error_free(data);
	return (0);
}

void	ft_move(t_datamap *datamap, int axis, int direction)
{
	if (direction < 0)
	{
		if (axis == 121)
			movement_player(datamap, datamap->babbo.img, 0, -32);
		else if (axis == 120)
			movement_player(datamap, datamap->babbo.img, -32, 0);
	}
	else if (direction > 0)
	{
		if (axis == 121)
			movement_player(datamap, datamap->babbo.img, 0, 32);
		else if (axis == 120)
			movement_player(datamap, datamap->babbo.img, 32, 0);
	}
}

int	on_keypress(int keysym, t_datamap *datamap)
{
	enemy_move(datamap);
	if (keysym == 119)
		ft_move(datamap, 'y', -32);
	else if (keysym == 97)
		ft_move(datamap, 'x', -32);
	else if (keysym == 115)
		ft_move(datamap, 'y', 32);
	else if (keysym == 100)
		ft_move(datamap, 'x', 32);
	else if (keysym == 65307)
		ft_error_free(datamap);
	if (datamap->moves_happened == 1)
	{
		datamap->moves++;
		ft_printmoves(datamap);
		datamap->moves_happened = 0;
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
	data.moves = 0;
	data.moves_happened = 0;
	data.moves_str = ft_itoa(data.moves);
	data.data.win = NULL;
	srand(time(0));
	put_image_on_struct(&data);
	put_map(argv[1], &data);
	return (0);
}
