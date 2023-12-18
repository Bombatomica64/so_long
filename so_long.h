/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:15:22 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 16:54:33 by lmicheli         ###   ########.fr       */
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

void	*put_xmp(void *mlx, char *filename, int *width, int *height);
int		put_map(char *filename, t_data *data);
int		map_checker(char *filename);


#endif