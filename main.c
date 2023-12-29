#include "so_long.h"

// int ft_window_size()
// {
// 	ft_printf("HEP tu joue a quoi laisse la window tranquille !!!\n");
// 	return (0);
// }

// int ft_exit()
// {
// 	ft_printf("IN IN IN !!!\n");
// 	return (0);
// }

// int ft_enter()
// {
// 	ft_printf("OUT OUT OUT !!!\n");
// 	return (0);
// }

void init_board(t_data *data)
{
	print_props(data);
}

void init_char(t_data *data, int value, char ruld)
{
	if (is_valide_move(data, ruld))
		return ;
	if (ruld == 'r' || ruld == 'l')
	{
		if(data->x_img + value < 0 + 100 || data->x_img + value >= 1900 - 100)
			init_board(data);
		else
		data->x_img += replace_till(data, value);
	}
	if (ruld == 'u' || ruld == 'd')
	{
		if(data->y_img + value < + 100 || data->y_img + value >= 1000 - 100)
			init_board(data);
		else
		data->y_img += replace_till(data, value);
	}
	put_miaou(data, data->x_img, data->y_img);
}

int on_destroy(t_data *data)
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
 
int on_keypress(int keycode, t_data *data)
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

int main(int argc ,char **argv)
{
	t_data data;

	if (argc != 2 || check_file_name(argv[1]))
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("arguments error", 1);
		exit (0);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1900, 1000, "SO_LONG");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	parse_map(argv[1], &data);
	init_board(&data);
	init_char(&data, 0, 0);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
