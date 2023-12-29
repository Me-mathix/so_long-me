/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:00:42 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/29 08:52:49 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int is_from_set(char c)
{
	char *set;
	int i;

	set = "01CPEM";
	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

int check_file_name(char *filename)
{
	int i;

	i = ft_strlen(filename) - 4;
	if (filename[i++] != '.')
		return (1);
	if (filename[i++] != 'b')
		return (1);
	if (filename[i++] != 'e')
		return (1);
	if (filename[i++] != 'r')
		return (1);
	return (0);
}
