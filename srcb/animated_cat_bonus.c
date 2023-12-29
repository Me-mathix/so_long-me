/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_cat_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:20 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/29 09:12:54 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void ft_wait(size_t caca)
{
	size_t i;
	
	i = 0;
	while (i < caca)
		i++;
}
void left_anmim(t_data *data, int x, int y)
{
	void *sprite;
	int i;
	
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/l4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x - 25, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/l3.xpm", &i, &i);
	put_bg(data, data->x_img + 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x - 50, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/l4.xpm", &i, &i);
	put_bg(data, data->x_img + 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x - 75, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/l2.xpm", &i, &i);
	put_bg(data, data->x_img + 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x - 100, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
}
void right_anmim(t_data *data, int x, int y)
{
	void *sprite;
	int i;
	
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/r4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x + 25, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/r3.xpm", &i, &i);
	put_bg(data, data->x_img - 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x + 50, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);	
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/r4.xpm", &i, &i);
	put_bg(data, data->x_img - 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x + 75, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/r2.xpm", &i, &i);
	put_bg(data, data->x_img - 100, data->y_img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x + 100, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
}

void down_anmim(t_data *data, int x, int y)
{
	void *sprite;
	int i;
	
	put_bg(data, data->x_img, data->y_img);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/d4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img - 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y + 25);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/d3.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img - 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y + 50);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/d4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img - 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y + 75);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/d2.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img - 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y + 100);
	mlx_destroy_image(data->mlx_ptr, sprite);
}
void up_anmim(t_data *data, int x, int y)
{
	void *sprite;
	int i;
	
	put_bg(data, data->x_img, data->y_img);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/u4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img + 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y - 25);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/u3.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img + 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y - 50);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/u4.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img + 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y - 75);
	mlx_destroy_image(data->mlx_ptr, sprite);
	ft_wait(8000000);
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/u2.xpm", &i, &i);
	put_bg(data, data->x_img, data->y_img + 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y - 100);
	mlx_destroy_image(data->mlx_ptr, sprite);
}
