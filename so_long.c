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
	if (datamap->map.nb_c == 0)
		mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
			datamap->exit.img, datamap->map.x, datamap->map.y);
}

void	ft_check_name(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'r' || filename[i - 2] != 'e'
		|| filename[i - 3] != 'b' || filename[i - 4] != '.')
	{
		ft_printf("Error: wrong file name\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_datamap	data;

	if (argc != 2)
		return (write(2, "Error: wrong number of arguments\n", 33));
	ft_check_name(argv[1]);
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
