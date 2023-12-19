/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:22 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/19 18:33:40 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft.h"
# include "ft_printf/get_next_line_bonus.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
}	t_image;

typedef struct s_line
{
	char	*line;
	int		read_bytes;
	int		i;
}	t_line;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		nb_c;
	int		nb_e;
	int		nb_p;
}	t_map;

t_map	get_map(char *filename);
void	ft_error_free(t_image *tile, t_image *wall, t_data *data);
void	ft_err_free_map(t_image *tile, t_image *wall, t_data *data, t_map *map);
void	ft_flood_fill(t_map *map, int y, int x);
void	*put_xmp(void *mlx, char *filename, int *width, int *height);
void	free_matrix(char **matrix);
int		put_map(char *filename, t_data *data);
int		wrong_letters_in_map(int fd);
int		map_checker(char *filename);
int		map_is_rectangular(int fd, int retval);
int		ft_count_lines(char *filename);
int		ft_check_if_map_is_valid(t_map map);
int		map_is_closed(t_map map);
int		ft_is_reachable(t_map map);
char	*bad_next_line(int fd);

#endif