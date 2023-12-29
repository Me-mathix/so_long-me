/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:56:44 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/29 18:24:56 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_char(t_data *data, int value, char ruld)
{
	if (is_valide_move(data, ruld))
		return ;
	if (ruld == 'r' || ruld == 'l')
	{
		if (data->x_img + value < 100 || data->x_img + value >= 1800)
			print_props(data);
		else
		data->x_img += value;
	}
	if (ruld == 'u' || ruld == 'd')
	{
		if (data->y_img + value < 100 || data->y_img + value >= 900)
			print_props(data);
		else
		data->y_img += value;
	}
	put_move(data);
	put_miaou(data, data->x_img, data->y_img, ruld);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map)
		ft_free(data->map);
	if (data->bt_maap)
		ft_free(data->bt_maap);
	exit (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		on_destroy(data);
	else if (keycode == 97 || keycode == 65361)
		init_char(data, -100, 'l');
	else if (keycode == 100 || keycode == 65363)
		init_char(data, 100, 'r');
	else if (keycode == 115 || keycode == 65364)
		init_char(data, 100, 'd');
	else if (keycode == 119 || keycode == 65362)
		init_char(data, -100, 'u');
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_file_name(argv[1]))
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("arguments error", 1);
		exit (0);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1900, 1000, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	parse_map(argv[1], &data);
	print_props(&data);
	init_char(&data, 0, 0);
	mlx_hook(data.win_ptr, 02, (1L << 0), &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, (1L << 17), &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
