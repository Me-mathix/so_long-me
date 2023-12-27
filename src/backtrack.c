/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:28:06 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/27 10:05:01 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int canReachEnd(char **bt_map, int row, int col, t_data *data)
{
    if (row <= 0 || row >= (data->map_verlen - 1) || col <= 0 
		|| col >= (data->map_horlen - 1) || bt_map[row][col] == '1'
		|| bt_map[row][col] == 'V')
	        return (0);
	
	if (bt_map[row][col] == 'E')
	        return (1);
			
	bt_map[row][col] = 'V';
    if (canReachEnd(bt_map, (row + 1), col, data) ||
        canReachEnd(bt_map, (row - 1), col, data) ||
       	canReachEnd(bt_map, row, (col + 1), data) ||
       	canReachEnd(bt_map, row, (col - 1), data)) 
        return (1);
    return (0);
}
