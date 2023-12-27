/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_till.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:14:38 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/27 10:05:27 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int replace_till(t_data *data, int value)
{
	put_bg(data, data->x_img, data->y_img);
	return(value);
}