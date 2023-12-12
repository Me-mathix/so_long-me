/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:11:48 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:07 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int check_r(t_data *data)
{
	if (data->map[data->x_inmap][data->y_inmap + 1] == '1')
	{
		return(1);
	}
	else
		data->y_inmap += 1;
	return (0);
}

int check_u(t_data *data)
{
	if (data->map[data->x_inmap - 1][data->y_inmap] == '1')
	{
		return(1);
	}
	else
	{
		data->x_inmap -= 1;
	}
	return (0);
}

int check_l(t_data *data)
{
	if (data->map[data->x_inmap][data->y_inmap - 1] == '1')
	{
		return(1);
	}
	else
	{
		data->y_inmap -= 1;
	}
	return (0);
}

int check_d(t_data *data)
{
		if (data->map[data->x_inmap + 1][data->y_inmap] == '1')
		{
			return(1);
		}
		else
		{
			data->x_inmap += 1;
		}
		return (0);
}

int is_valide_move(t_data *data, char ruld)
{
	int i;
	
	i = 0;
	if (ruld == 'l')
		i = check_l(data);
	if (ruld == 'r')
		i = check_r(data);
	if (ruld == 'u')
		i = check_u(data);
	if (ruld == 'd')
		i = check_d(data);	
	return(i);
}
