/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:11:48 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/27 10:05:23 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int check_r(t_data *data)
{
	if (data->map[data->x_inmap][data->y_inmap + 1] == '1')
		return(1);
	else if (data->map[data->x_inmap][data->y_inmap + 1] == 'C')
	{
		data->map[data->x_inmap][data->y_inmap + 1] = '0';
		data->props_list.colec -= 1;
		data->y_inmap += 1;
	}
	else if (data->map[data->x_inmap][data->y_inmap + 1] == 'E')
	{
		if (data->props_list.colec == 0)
			on_destroy(data);
		data->y_inmap += 1;
	}
	else
		data->y_inmap += 1;
	return (0);
}

int check_u(t_data *data)
{
	if (data->map[data->x_inmap - 1][data->y_inmap] == '1')
		return(1);
	else if (data->map[data->x_inmap - 1][data->y_inmap] == 'C')
	{
		data->map[data->x_inmap - 1][data->y_inmap] = '0';
		data->props_list.colec -= 1;
		data->x_inmap -= 1;
	}
	else if (data->map[data->x_inmap - 1][data->y_inmap] == 'E')
	{
		if (data->props_list.colec == 0)
			on_destroy(data);
		data->x_inmap -= 1;
	}
	else
		data->x_inmap -= 1;
	return (0);
}

int check_l(t_data *data)
{
	if (data->map[data->x_inmap][data->y_inmap - 1] == '1')
		return(1);
	else if (data->map[data->x_inmap][data->y_inmap - 1] == 'C')
	{
		data->map[data->x_inmap][data->y_inmap - 1] = '0';
		data->props_list.colec -= 1;
		data->y_inmap -= 1;
	}
	else if (data->map[data->x_inmap][data->y_inmap - 1] == 'E')
	{
		if (data->props_list.colec == 0)
			on_destroy(data);
		data->y_inmap -= 1;
	}
	else
		data->y_inmap -= 1;
	return (0);
}

int check_d(t_data *data)
{
		if (data->map[data->x_inmap + 1][data->y_inmap] == '1')
			return(1);
		else if (data->map[data->x_inmap + 1][data->y_inmap] == 'C')
		{
			data->map[data->x_inmap + 1][data->y_inmap] = '0';
			data->props_list.colec -= 1;
			data->x_inmap += 1;
		}
		else if (data->map[data->x_inmap + 1][data->y_inmap] == 'E')
		{
			if (data->props_list.colec == 0)
				on_destroy(data);
			data->x_inmap += 1;
		}
		else
		data->x_inmap += 1;
		return (0);
}

int is_valide_move(t_data *data, char ruld)
{
	int i;
	static int count;
	
	i = 0;
	if (ruld == 'l')
		i = check_l(data);
	if (ruld == 'r')
		i = check_r(data);
	if (ruld == 'u')
		i = check_u(data);
	if (ruld == 'd')
		i = check_d(data);
	if (!i)
		ft_printf("%u\n", count++);	
	return(i);
}
