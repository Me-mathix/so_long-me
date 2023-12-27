/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_till_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:14:38 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/27 16:46:25 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int replace_till(t_data *data, int value)
{
	put_bg(data, data->x_img, data->y_img);
	return(value);
}