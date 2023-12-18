/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:52:58 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/18 16:01:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_xmp(void *mlx, char *filename, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, filename, width, height);
	if (!img)
		return (NULL);
	return (img);
}
