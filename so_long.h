/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:22 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 19:13:14 by lmicheli         ###   ########.fr       */
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

void	*put_xmp(void *mlx, char *filename, int *width, int *height);
int		put_map(char *filename, t_data *data);
int		wrong_letters_in_map(int fd);
int		map_checker(char *filename);
void	ft_error_free_map(t_data **tile, t_data **wall, void (*del)(void*));
int		map_is_rectangular(int fd, int retval);
t_map	get_map(char *filename);
int		ft_count_lines(char *filename);
void	ft_check_if_map_is_valid(t_map map);
int		map_is_closed(t_map map);

#endif