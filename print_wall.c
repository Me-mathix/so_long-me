/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:18:43 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/12 16:41:20 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void put_wall(t_data *data, int x, int y)
{
	void *wall;
	int	img_width;
	int	img_height;

	wall =  mlx_xpm_file_to_image(data->mlx_ptr, "./test.xpm",
									 &img_width, &img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, x, y);
	mlx_destroy_image(data->mlx_ptr, wall);
}

void print_rwall(t_data *data, int x, int y)
{
	int offset;
	int j;
	
	offset = data->y_inmap + 1;
	while (offset <= data->map_horlen - 1)
	{
		if (data->map[data->x_inmap][offset] == '1')
		{
			x += 32;
			put_wall(data, x, y);
		}
		else 
			x += 32;
		offset++;
	}
	j = 0;
	y -= data->x_inmap * 32;
	while (j++ < data->map_verlen)
	{
		put_wall(data, x, y);
		y += 32;
	}
}

void print_lwall(t_data *data, int x, int y)
{
	int offset;
	int j;
	
	offset = data->y_inmap - 1;
	while (offset >= 0)
	{
		if (data->map[data->x_inmap][offset] == '1')
		{
			x -= 32;
			put_wall(data, x, y);
		}
		else 
			x -= 32;
		offset--;
	}
	j = 0;
	y -= data->x_inmap * 32;
	while (j++ < data->map_verlen)
	{
		put_wall(data, x, y);
		y += 32;
	}
}

void print_uwall(t_data *data, int x, int y)
{
	int offset;
	int j;
	
	offset = data->x_inmap - 1;
	while (offset >= 0)
	{
		if (data->map[offset][data->y_inmap] == '1')
		{
			y -= 32;
			put_wall(data, x, y);
		}
		else 
			y -= 32;
		offset--;
	}
	j = 0;
	x -= data->y_inmap * 32;
	while (j++ < data->map_horlen)
	{
		put_wall(data, x, y);
		x += 32;
	}
}

void print_dwall(t_data *data, int x, int y)
{
	int offset;
	int j;
	
	offset = data->x_inmap + 1;
	while (offset <= data->map_verlen - 1)
	{
		if (data->map[offset][data->y_inmap] == '1')
		{
			y += 32;
			put_wall(data, x, y);
		}
		else 
			y += 32;
		offset++;
	}
	j = 0;
	x -= data->y_inmap * 32;
	while (j++ < data->map_horlen)
	{
		put_wall(data, x, y);
		x += 32;
	}
}


void print_wall(t_data *data)
{
	int i;
	int j;

	i = data->x_img;
	j = data->y_img;
	print_lwall(data, i, j);
	print_rwall(data, i, j);
	print_uwall(data, i, j);
	print_dwall(data, i, j);	
}