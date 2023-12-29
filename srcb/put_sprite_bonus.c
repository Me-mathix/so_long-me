/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:38:10 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/29 15:55:58 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_wall(t_data *data, int x, int y, char c)
{
	void	*sprite;
	int		i;

	if (c == '1')
		sprite = mlx_xpm_file_to_image(data->mlx_ptr,
				"./sprites/treee.xpm", &i, &i);
	if (c == 'M')
		sprite = mlx_xpm_file_to_image(data->mlx_ptr,
				"./sprites/devil.xpm", &i, &i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y);
	mlx_destroy_image(data->mlx_ptr, sprite);
}

void	put_props(t_data *data, int x, int y)
{
	void	*wall;
	int		i;

	wall = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/colec.xpm", &i, &i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, x, y);
	mlx_destroy_image(data->mlx_ptr, wall);
}

void	put_bg(t_data *data, int x, int y)
{
	void	*snow;
	int		i;

	snow = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/wood.xpm", &i, &i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, snow, x, y);
	mlx_destroy_image(data->mlx_ptr, snow);
}

void	put_miaou(t_data *data, int x, int y, char c)
{
	void	*miaou;
	int		i;

	if (c == 'r')
		right_anmim(data, x - 100, y);
	else if (c == 'u')
		up_anmim(data, x, y + 100);
	else if (c == 'l')
		left_anmim(data, x + 100, y);
	else if (c == 'd')
		down_anmim(data, x, y - 100);
	else
	{
		miaou = mlx_xpm_file_to_image(data->mlx_ptr,
				"./sprites/r1.xpm", &i, &i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, miaou, x, y);
		mlx_destroy_image(data->mlx_ptr, miaou);
	}
}

void	put_move(t_data *data)
{
	static int	count;
	char		*tmp;
	void		*hud;
	int			i;

	hud = mlx_xpm_file_to_image(data->mlx_ptr,
			"./sprites/dial.xpm", &i, &i);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, hud, 1600, 900);
	mlx_destroy_image(data->mlx_ptr, hud);
	tmp = ft_itoa(count++);
	if (!tmp)
		on_destroy(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1700, 940, 0, tmp);
	free(tmp);
}
