/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:00:30 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/12/12 12:41:17 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>


typedef struct s_sprites
{
	void *player;
	void *board;
} t_sprites;

typedef struct s_props
{
	int colec;
	int spawn;
	int exit; 
} t_props;
 
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			x_img;
	int			y_img;
	int 		x_inmap;
	int 		y_inmap;
	int 		map_horlen;
	int 		map_verlen;
	t_props		props_list;
} t_data;


//* PRINT
void print_wall(t_data *data);

//PARSE
char	**parse_map(char *ol_map, t_data *data);
char	*read_buffer(char *fd_name);
void	start_char(t_data *data);

// player movement
int 	is_valide_move(t_data *data, char ruld);



//ERROR
void	parse_error(t_data *data);
void	check_wall(t_data *data);
void	check_props(t_data *data);
void	check_value(t_props props);

//ERROR UTILS
void	ft_printerr(int errcode);
int		is_from_set(char c);



#endif