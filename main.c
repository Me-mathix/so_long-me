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
	// void *sprite;
 	// int i;
 	// int j;	
	// int	img_width;
	// int	img_height;

	// i = 0;
	// j = 0;
	// sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./snow.xpm", &img_width, &img_height);
	// while (j < 1080)
	// {
	// 	while (i < 1920)
	// 	{
	// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, i, j);
	// 		i += 32;
	// 	}
	// 	j += 32;
	// 	i = 0;
	// }
	print_wall(data);
	print_props(data);
	// mlx_destroy_image(data->mlx_ptr, sprite);
}

void init_char(t_data *data, int value, char ruld)
{
	void *sprite;	
	int	img_width;
	int	img_height;

	if (is_valide_move(data, ruld))
		return ;
	sprite = mlx_xpm_file_to_image(data->mlx_ptr, "./test.xpm",
									 &img_width, &img_height);
	if (ruld == 'r' || ruld == 'l')
	{
		if(data->x_img + value < 0 || data->x_img + value >= 1920 - 32)
			;
		else
		data->x_img += value;
	}
	if (ruld == 'u' || ruld == 'd')
	{
		if(data->y_img + value < 0 || data->y_img + value >= 1080 - 32)
			;
		else
		data->y_img += value;
	}
	init_board(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, data->x_img, data->y_img);
	mlx_destroy_image(data->mlx_ptr, sprite);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free(data->map);
	ft_printf("BONK BONK BONK !!!\n");
	exit(0);
	return (0);
}
 
int on_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)
        on_destroy(data);
    else if (keycode == 97 || keycode == 65361)
        init_char(data, -32, 'l');
    else if (keycode == 100 || keycode == 65363)
        init_char(data, 32, 'r');
    else if (keycode == 115 || keycode == 65364)
        init_char(data, 32, 'd');
    else if (keycode == 119 || keycode == 65362)
        init_char(data, -32, 'u');
    return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


 
int main(int argc ,char **argv)
{
	t_data data;
	// t_img pxl;
	(void) argc;
 
 	// int i = 0;
 	// int j = 0;
	parse_map(argv[1], &data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	init_board(&data);
	// pxl.img = mlx_new_image(data.mlx_ptr, 600, 400);
	// pxl.addr = mlx_get_data_addr(pxl.img, &pxl.bits_per_pixel, &pxl.line_length,
	// 							&pxl.endian);
	// while (++j < 200)
	// {
	// 	while (++i < 600)
	// 		my_mlx_pixel_put(&pxl, i, j, 0x00FFAAEE);
	// 	i = -1;
	// }
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, pxl.img, 0, 0);


	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
	// //
	// mlx_hook(data.win_ptr, EnterNotify, EnterWindowMask, &ft_exit, &data);
	// //
	// mlx_hook(data.win_ptr, LeaveNotify, LeaveWindowMask, &ft_enter, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}