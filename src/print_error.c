/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:25:05 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/28 12:12:12 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void error_tree_1(int errcode)
{
	if (errcode == 1)
		ft_putstr_fd("Square not allowed", 1);
	if (errcode == 2)
		ft_putstr_fd("A line as different size", 1);
	if (errcode == 3)
		ft_putstr_fd("A Column as different size", 1);
	if (errcode == 4)
		ft_putstr_fd("Map is badly closed on side", 1);
	if (errcode == 5)
		ft_putstr_fd("Map is badly closed on up or down side", 1);
	if (errcode == 6)
		ft_putstr_fd("Forbiden char detected in the map", 1);
	if (errcode == 7)
		ft_putstr_fd("EXIT error", 1);
	if (errcode == 8)
		ft_putstr_fd("SPAWN error", 1);
	if (errcode == 9)
		ft_putstr_fd("NO ESCAPE", 1);
	if (errcode == 10)
		ft_putstr_fd("file cant be read", 1);
}

void ft_printerr(t_data *data, int errcode)
{
	ft_putstr_fd("Error\n", 1);
	error_tree_1(errcode);
	on_destroy(data);
}