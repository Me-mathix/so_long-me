/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:38:10 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/27 09:57:29 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_wall(t_data *data, int x, int y)
{
	void *wall;
	int	img_width;
	int	img_height;

	wall =  mlx_xpm_file_to_image(data->mlx_ptr, "./treee.xpm",
									 &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, x, y);
	mlx_destroy_image(data->mlx_ptr, wall);
}

void put_props(t_data *data, int x, int y)
{
	void *wall;
	int	img_width;
	int	img_height;

	wall =  mlx_xpm_file_to_image(data->mlx_ptr, "./colec.xpm",
									 &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, x, y);
	mlx_destroy_image(data->mlx_ptr, wall);
}

void put_bg(t_data *data, int x, int y)
{
	void *snow;
	int	img_width;
	int	img_height;

	snow =  mlx_xpm_file_to_image(data->mlx_ptr, "./snow.xpm",
									 &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, snow, x, y);
	mlx_destroy_image(data->mlx_ptr, snow);
}

void put_miaou(t_data *data, int x, int y)
{
	void *miaou;
	int	i;

	miaou =  mlx_xpm_file_to_image(data->mlx_ptr, "./miaou.xpm", &i, &i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, miaou, x, y);
	mlx_destroy_image(data->mlx_ptr, miaou);
}
