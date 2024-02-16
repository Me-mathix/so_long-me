/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:20:52 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/01/05 13:20:22 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_error(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] && (i < data->map_verlen))
	{
		if ((int) ft_strlen(data->map[i++]) != data->map_horlen)
			ft_printerr(data, 2);
	}
	i = 0;
	check_wall(data);
	check_props(data);
}

void	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i][0])
	{
		if ((data->map[i][0] != '1')
			|| (data->map[i][data->map_horlen - 1] != '1'))
			ft_printerr(data, 4);
		i++;
	}
	i = 0;
	while (data->map[0][i])
	{
		if ((data->map[0][i] != '1')
			|| (data->map[data->map_verlen - 1][i] != '1'))
			ft_printerr(data, 5);
		i++;
	}
}

t_props	init_prop(t_props list)
{
	list.colec = 0;
	list.spawn = 0;
	list.exit = 0;
	return (list);
}

void	check_props(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	data->props_list = init_prop(data->props_list);
	while (i < (data->map_verlen - 1))
	{
		while (j < (data->map_horlen - 1))
		{
			if (data->map[i][j] == 'C')
				data->props_list.colec += 1;
			else if (data->map[i][j] == 'P')
				data->props_list.spawn += 1;
			else if (data->map[i][j] == 'E')
				data->props_list.exit += 1;
			else if (!is_from_set(data->map[i][j]))
				ft_printerr(data, 6);
			j++;
		}
		i++;
		j = 1;
	}
	check_value(data);
}

void	check_value(t_data *data)
{
	if ((data->props_list.exit > 1) || (data->props_list.exit < 1))
		ft_printerr(data, 7);
	else if ((data->props_list.spawn > 1) || (data->props_list.spawn < 1))
		ft_printerr(data, 8);
}
