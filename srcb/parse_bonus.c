/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:26:29 by mathieu           #+#    #+#             */
/*   Updated: 2023/12/27 14:38:31 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char *read_buffer(char *fd_name)
{
	int file; 
	int i;
	char c;
	char *buff;

	i = 0;
	buff = ft_calloc(1, 1000000);
	file = open(fd_name, O_RDONLY);
	if (file < 0)
		return (0);
	while (read(file, &c, 1))
		buff[i++] = c;
	buff[i] = '\0';
	close(file);
	return(buff);
}

char **parse_map(char *ol_map, t_data *data)
{
	char **bt_map;
	
	ol_map = read_buffer(ol_map);
	data->map = ft_split(ol_map, '\n');
	bt_map = ft_split(ol_map, '\n');
	free(ol_map);
	data->map_verlen = 0;
	data->map_horlen = 0;
	while (data->map[data->map_verlen][0] != '\0')
		data->map_verlen++;
	while (data->map[0][data->map_horlen] != '\0')
		data->map_horlen++;
	parse_error(data);
	start_char(data);
	if (!canReachEnd(bt_map, data->x_inmap, data->y_inmap, data))
	{
		ft_free(bt_map);
		ft_printerr(data, 9);
	}
	ft_free(bt_map);
	return (data->map);
}

void start_char(t_data *data)
{
	int i;
	int j;

	data->x_img = 0;
	data->y_img = 0;
	i = 0;
	j = 0;
	while (i < (data->map_verlen - 1))
	{
		while (j < (data->map_horlen - 1))
		{
			if (data->map[i][j] == 'P')
			{
				data->x_inmap = i;
				data->y_inmap = j;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
