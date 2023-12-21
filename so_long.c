/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:11 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/21 17:25:22 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_datamap *data)
{
	ft_error_free(data);
	return (0);
}

char	*ft_strjoin2(char *old_str, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char) * (ft_strlen(old_str) + ft_strlen(buf) + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0')
			res[i] = old_str[i];
	while (buf[j] != '\0')
		res[i++] = buf[j++];
	res[ft_strlen(old_str) + ft_strlen(buf)] = '\0';
	return (res);
}

void	ft_printmoves(t_datamap *datamap)
{
	mlx_string_put(datamap->data.mlx, datamap->data.win, 64,
		datamap->map.height * 32 + 32, 0x000000, datamap->moves_str);
	//free(datamap->moves_str);
	datamap->moves_str = ft_itoa(datamap->moves);
	if (!datamap->moves_str)
		return ;
	datamap->moves_str = ft_strjoin2("Moves done : ", datamap->moves_str);
	mlx_string_put(datamap->data.mlx, datamap->data.win, 64,
		datamap->map.height * 32 + 32, 0xFFFFFF, datamap->moves_str);
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
	datamap->collectible.img = put_xmp(datamap->data.mlx,
			"assets/collectible.xpm", &datamap->collectible.width, &datamap->collectible.height);
	datamap->black.img = put_xmp(datamap->data.mlx,
			"assets/black.xpm", &datamap->black.width, &datamap->black.height);
	datamap->enemy.img = put_xmp(datamap->data.mlx,
	 		"assets/enemy.xpm", &datamap->enemy.width, &datamap->enemy.height);
	datamap->tile25.img = put_xmp(datamap->data.mlx,
			"assets/tile25.xpm", &datamap->tile25.width, &datamap->tile25.height);
	datamap->tile50.img = put_xmp(datamap->data.mlx,
			"assets/tile50.xpm", &datamap->tile50.width, &datamap->tile50.height);
	datamap->tile75.img = put_xmp(datamap->data.mlx,
			"assets/tile75.xpm", &datamap->tile75.width, &datamap->tile75.height);
	datamap->wall_light.img = put_xmp(datamap->data.mlx,
	 		"assets/wall_light.xpm", &datamap->wall_light.width, &datamap->wall_light.height);
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
					datamap->black.img, datamap->player.x, datamap->player.y);
				//datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = '0';
				datamap->player.y -= 32;
				//datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = 'P';
				ft_flood_light(datamap, datamap->player.x, datamap->player.y + 32);
			}
		}
		else if (axis == 120)
		{
			if (ft_check_block(datamap, datamap->player.x - 32, datamap->player.y) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x - 32, datamap->player.y);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->black.img, datamap->player.x, datamap->player.y);
				//datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = '0';
				datamap->player.x -= 32;
				//datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = 'P';
				ft_flood_light(datamap, datamap->player.x - 32, datamap->player.y);
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
					datamap->black.img, datamap->player.x, datamap->player.y);
			//	datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = '0';
				datamap->player.y += 32;
			//	datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = 'P';
				ft_flood_light(datamap, datamap->player.x - 32, datamap->player.y);
			}
		}
		else if (axis == 120)
		{
			if (ft_check_block(datamap, datamap->player.x + 32, datamap->player.y) == 0)
			{
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->babbo.img, datamap->player.x + 32, datamap->player.y);
				mlx_put_image_to_window(datamap->data.mlx, datamap->data.win,
					datamap->black.img, datamap->player.x, datamap->player.y);
			//	datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = '0';
				datamap->player.x += 32;
			//	datamap->map.map[datamap->player.y / 32][datamap->player.x / 32] = 'P';
				ft_flood_light(datamap, datamap->player.x - 32, datamap->player.y);
			}
		}
	}
}

int	on_keypress(int keysym, t_datamap *datamap)
{
	datamap->moves++;
	ft_printmoves(datamap);
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
//	enemy_move(datamap);
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
	srand(time(0));
	put_image_on_struct(&data);
	put_map(argv[1], &data);
	return (0);
}
