/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:26:29 by mathieu           #+#    #+#             */
/*   Updated: 2024/02/16 19:12:21 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*read_buffer(char *fd_name, t_data *data)
{
	int		file;
	int		i;
	char	c;
	char	*buff;

	i = 1;
	file = open(fd_name, O_RDONLY);
	if (file < 0)
		ft_printerr(data, 10);
	if (read(file, &c, 1) == -1)
		ft_printerr(data, 10);
	while (read(file, &c, 1))
		i++;
	close(file);
	buff = ft_calloc((sizeof (char)), i + 1);
	i = 0;
	file = open(fd_name, O_RDONLY);
	while (read(file, &c, 1))
		buff[i++] = c;
	buff[i] = '\0';
	close(file);
	return (buff);
}

char	**parse_map(char *ol_map, t_data *data)
{
	data->map = NULL;
	data->bt_maap = NULL;
	ol_map = read_buffer(ol_map, data);
	if (ft_strlen(ol_map) == 0)
	{
		free(ol_map);
		on_destroy(data);
	}
	data->map = ft_split(ol_map, '\n');
	data->bt_maap = ft_split(ol_map, '\n');
	free(ol_map);
	if (!data->map || !data->bt_maap)
		on_destroy(data);
	data->map_verlen = 0;
	data->map_horlen = 0;
	while (data->map[data->map_verlen][0] != '\0')
		data->map_verlen++;
	while (data->map[0][data->map_horlen] != '\0')
		data->map_horlen++;
	parse_error(data);
	start_char(data);
	if (!can_reach_end(data->bt_maap, data->x_inmap, data->y_inmap, data))
		ft_printerr(data, 9);
	return (data->map);
}

void	start_char(t_data *data)
{
	int	i;
	int	j;

	data->x_img = 100;
	data->y_img = 100;
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
