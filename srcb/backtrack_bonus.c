/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:28:06 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/02/16 19:13:24 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	can_reach_end(char **bt_map, int row, int col, t_data *data)
{
	static int	i;
	static int	e;

	if (row <= 0 || row >= (data->map_verlen - 1) || col <= 0
		|| col >= (data->map_horlen - 1) || bt_map[row][col] == '1'
		|| bt_map[row][col] == 'V' || bt_map[row][col] == 'M')
		return (0);
	if (bt_map[row][col] == 'C')
		i++;
	if (bt_map[row][col] == 'E')
		return (e++, 0);
	bt_map[row][col] = 'V';
	if (can_reach_end(bt_map, (row + 1), col, data)
		|| can_reach_end(bt_map, (row - 1), col, data)
		|| can_reach_end(bt_map, row, (col + 1), data)
		|| can_reach_end(bt_map, row, (col - 1), data))
		;
	if (i == data->props_list.colec && e == data->props_list.exit)
		return (1);
	return (0);
}
