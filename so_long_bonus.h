/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:00:30 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/01/02 13:03:53 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_props
{
	int	colec;
	int	spawn;
	int	exit;
}	t_props;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**bt_maap;
	int			x_img;
	int			y_img;
	int			x_inmap;
	int			y_inmap;
	int			map_horlen;
	int			map_verlen;
	t_props		props_list;
}	t_data;

//destroy 
int		on_destroy(t_data *data);

//* PRINT
void	print_props(t_data *data);
int		replace_till(t_data *data, int value);

//PARSE
char	**parse_map(char *ol_map, t_data *data);
char	*read_buffer(char *fd_name, t_data *data);
void	start_char(t_data *data);

// player movement
int		is_valide_move(t_data *data, char ruld);

//ERROR
void	parse_error(t_data *data);
void	check_wall(t_data *data);
void	check_props(t_data *data);
void	check_value(t_data *data);

//ERROR UTILS
int		can_reach_end(char **bt_map, int row, int col, t_data *data);
void	ft_printerr(t_data *data, int errcode);
int		is_from_set(char c);
int		check_file_name(char *filename);

//PUT SPRITE
void	put_wall(t_data *data, int x, int y, char c);
void	put_props(t_data *data, int x, int y);
void	put_bg(t_data *data, int x, int y);
void	put_miaou(t_data *data, int x, int y, char c);
void	put_move(t_data *data);

//ANIMATION
void	right_anmim(t_data *data, int x, int y);
void	left_anmim(t_data *data, int x, int y);
void	up_anmim(t_data *data, int x, int y);
void	down_anmim(t_data *data, int x, int y);
void	**init_anime(t_data *data);

#endif