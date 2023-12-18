/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_props.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:37:03 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/18 13:43:28 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_rprops(t_data *data, int x, int y)
{
	int i;
	int j;

	i = 1;
	j = data->y_inmap + 1;
	while (i <= data->map_verlen - 2)
	{
		while (j <= data->map_horlen - 2)
		{
			if ((data->map[i][j] == 'C') || (data->map[i][j] == 'E'))
				put_props(data, (x - ((data->y_inmap - j) * 32))
				,(y - ((data->x_inmap - i) * 32)));
			if ((data->map[i][j] == '1'))
				put_wall(data, (x - ((data->y_inmap - j) * 32))
				,(y - ((data->x_inmap - i) * 32)));
			j++;
		}
		j = data->y_inmap + 1;
		i++;
	}
}

void print_lprops(t_data *data, int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= data->map_verlen - 2)
	{
		while (j <= data->y_inmap)
		{
			if ((data->map[i][j] == 'C') || (data->map[i][j] == 'E'))
				put_props(data, (x - ((data->y_inmap - j) * 32))
				,(y - ((data->x_inmap - i) * 32)));
			if ((data->map[i][j] == '1'))
				put_wall(data, (x - ((data->y_inmap - j) * 32))
				,(y - ((data->x_inmap - i) * 32)));
			j++;
		}
		j = 1;
		i++;
	}
}

void print_props(t_data *data)
{
	int i;
	int j;

	i = data->x_img;
	j = data->y_img;
	print_lprops(data, i, j);
	print_rprops(data, i, j);
}
