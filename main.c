#include "so_long.h"


int ft_window_size()
{
	ft_printf("HEP tu joue a quoi laisse la window tranquille !!!\n");
	return (0);
}

int ft_exit()
{
	ft_printf("IN IN IN !!!\n");
	return (0);
}

int ft_enter()
{
	ft_printf("OUT OUT OUT !!!\n");
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("BONK BONK BONK !!!\n");
	exit(0);
	return (0);
}
 
int on_keypress(int keycode, t_data *data)
{
	(void) data;
    if (keycode == 65307)
        on_destroy(data);
    else if (keycode == 97 || keycode == 65361)
        ft_printf("LEFT (A / ARROW_LEFT)\n");
    else if (keycode == 100 || keycode == 65363)
        ft_printf("RIGHT (D / ARROW_RIGHT)\n");
    else if (keycode == 115 || keycode == 65364)
        ft_printf("DOWN (S / ARROW_DOWN)\n");
    else if (keycode == 119 || keycode == 65362)
        ft_printf("UP (W / ARROW_UP)\n");
    else
        ft_printf("%d\n", keycode);
    return (0);
}
 
int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
 
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	//
	mlx_hook(data.win_ptr, EnterNotify, EnterWindowMask, &ft_exit, &data);
	
	//
	mlx_hook(data.win_ptr, LeaveNotify, LeaveWindowMask, &ft_enter, &data);

	//
	mlx_hook(data.win_ptr, Notify, StructureNotifyMask, &ft_window_size, &data);

 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}