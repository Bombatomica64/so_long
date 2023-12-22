/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:22 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 17:42:54 by lmicheli         ###   ########.fr       */
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
# include <time.h>

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
	int		nb_n;
}	t_map;
typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
	struct s_enemy	*next;
	struct s_enemy	*prev;
}	t_enemy;

typedef struct s_datamap
{
	t_data		data;
	t_map		map;
	t_image		tile;
	t_image		tile25;
	t_image		tile50;
	t_image		tile75;
	t_image		babbo;
	t_image		wall;
	t_image		wall_light;
	t_image		enemy;
	t_image		exit;
	t_image		collectible;
	t_image		black;
	t_enemy		*enemies;
	t_player	player;
	int			moves;
	int			moves_happened;
	char		*moves_str;
}	t_datamap;

t_map		get_map(char *filename);
void		ft_error_free(t_datamap *data);
void		ft_flood_fill(t_map *map, int y, int x);
void		*put_xmp(void *mlx, char *filename, int *width, int *height);
void		free_matrix(char **matrix);
int			put_map(char *filename, t_datamap *data);
int			wrong_letters_in_map(int fd);
int			map_checker(char *filename);
int			map_is_rectangular(int fd, int retval);
int			ft_count_lines(char *filename);
int			ft_check_if_map_is_valid(t_datamap *data);
int			map_is_closed(t_map map);
int			ft_is_reachable(t_datamap data);
char		*bad_next_line(int fd);
void		ft_put_tile(t_datamap *data, t_map map);
int			on_keypress(int keysym, t_datamap *datamap);
int			on_destroy(t_datamap *data);
t_player	get_player(t_map map);
void		ft_copy_map(t_map *map_new, t_map map_old);
int			ft_check_block(t_datamap *datamap, int x, int y);
int			get_collectibles(t_map map);
void		ft_move(t_datamap *datamap, int axis, int direction);
void		ft_first_enemy(t_datamap *data);
void		ft_move_enemy(t_datamap *datamap, t_enemy *enemy, int direction, void *enemy_img);
void		ft_put_light(t_datamap *data, t_enemy *enemy, int direction);
void		ft_remove_light(t_datamap *data, t_enemy *enemy);
t_enemy		*get_enemies(t_map map);
int			ft_check_block_e(t_datamap *datamap, int x, int y);
int			ft_random_number(void);
void		enemy_move(t_datamap *data);
void		ft_flood_light(t_datamap *data, int x, int y, int radius);
void		ft_rem_lights(t_datamap *data, int x, int y, int offset);
void		ft_flooding_light(t_datamap *data, int x, int y, int radius);
void		put_image_on_struct(t_datamap *datamap);
void		ft_1_to_w(t_datamap *datamap, int x, int y);
void		ft_printmoves(t_datamap *datamap);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
void		ft_flooding_light_w(t_datamap *data, int x, int y, int radius);
char		*ft_strjoin2(char *old_str, char *buf);
void		movement_player(t_datamap *data, void *img, int dr_x, int dr_y);
void		ft_free_enemy(t_datamap *data);
void		ft_print_map(t_map map);
int			get_exits(t_map map);
int			get_player_nbr(t_map map);
void		ft_add_enemy(t_enemy **enemy, int x, int y);

#endif