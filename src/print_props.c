/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_props.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:37:03 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/29 15:40:29 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_rprops(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = data->x_inmap - (data->y_img / 100) - 1;
	j = data->y_inmap;
	while (++i < (data->x_inmap + ((1000 - data->y_img) / 100))
		&& i <= data->map_verlen)
	{
		while (++j < (data->y_inmap + ((1900 - data->x_img) / 100))
			&& j < data->map_horlen)
		{
			if ((data->map[i][j] == 'C') || (data->map[i][j] == 'E'))
				put_props(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
			else if (data->map[i][j] == '1')
				put_wall(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
			else if ((data->map[i][j] == '0') || (data->map[i][j] == 'P'))
				put_bg(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
		}
		j = data->y_inmap;
	}
}

void	print_lprops(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = data->x_inmap - (data->y_img / 100) - 1;
	j = data->y_inmap - (data->x_img / 100) - 1;
	while (++i <= (data->x_inmap + ((1000 - data->y_img) / 100))
		&& i <= data->map_verlen)
	{
		while (++j <= data->y_inmap)
		{
			if (data->x_inmap == i && data->y_inmap == j)
				;
			else if ((data->map[i][j] == 'C') || (data->map[i][j] == 'E'))
				put_props(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
			else if (data->map[i][j] == '1')
				put_wall(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
			else if ((data->map[i][j] == '0') || (data->map[i][j] == 'P'))
				put_bg(data, (x - ((data->y_inmap - j) * 100)),
					(y - ((data->x_inmap - i) * 100)));
		}
		j = data->y_inmap - (data->x_img / 100) - 1;
	}
}

void	print_props(t_data *data)
{
	int	i;
	int	j;

	i = data->x_img;
	j = data->y_img;
	print_lprops(data, i, j);
	print_rprops(data, i, j);
}
