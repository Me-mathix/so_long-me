/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:26:29 by mathieu           #+#    #+#             */
/*   Updated: 2023/12/03 20:30:47 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_buffer(char *fd_name)
{
    int file;
    int i;
    char c;
    char *buff;
	char *tmp;

    i = 0;
    buff = ft_calloc(100, 100);
    file = open(fd_name, O_RDONLY);
    if (file < 0)
        return (0);
    while (read(file, &c, 1))
        buff[i++] = c;
    buff[i] = '\0';
	tmp = buff;
    close(file);
	free (buff);
    return(tmp);
}

char **parse_map(char *ol_map, t_data *data)
{
    int map_verlen;
	int map_horlen;
	
    ol_map = read_buffer(ol_map);
    data->map = ft_split(ol_map, '\n');
	while (data->map[map_verlen])
		map_verlen++;
	while (data->map[0][map_horlen])
		map_horlen++;
    return (data->map);
}