/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 22:51:48 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ########################################################################## */
/* INCLUDES */

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

/* ########################################################################## */
/* STRUCTURES */

typedef struct s_prgm {
	void	*mlx;
	void	*win;
	char	*map_path;
	int		col;
	int		row;
	char	**map;
	int		*wid;
	int		*hei;
	void	*img;
	int		exit_nb;
	int		player_nb;
	int		collect_nb;
	int		invalid_char;
	int		pxm;
	int		pym;
	int		pxw;
	int		pyw;
	int		steps;
	int		mxw;
	int		myw;
	int		mcxw;
	int		b;
	int		w;
}				t_prgm;

/* ########################################################################## */
/* CONSTANTS */

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* ########################################################################## */
/* FUNCTIONS */

/* hooks.c */
int		key_hook(int keycode, t_prgm *vars);

/* map.c */
char	**store_map(t_prgm vars);

/* map_checks_1.c */
void	check_valid_char(t_prgm *vars);
void	check_collectible(t_prgm *vars);
void	check_exit(t_prgm *vars);
void	check_map(t_prgm *vars);
void	check_player(t_prgm *vars);

/* map_checks_2.c */
void	check_empty_map(t_prgm *vars);
void	check_ew_wall(t_prgm *vars);
void	check_map_file_extension(t_prgm *vars);
void	check_ns_wall(t_prgm *vars);
void	check_rectangle(t_prgm *vars);

/* moves_1.c */
void	move_down(t_prgm *vr);
void	move_left(t_prgm *vr);
void	move_right(t_prgm *vr);
void	move_up(t_prgm *vr);

/* moves_2.c */
void	put_move_down_to_window(t_prgm *vr);
void	put_move_left_to_window(t_prgm *vr);
void	put_move_right_to_window(t_prgm *vr);
void	put_move_up_to_window(t_prgm *vr);
void	put_black_patch_to_window(t_prgm *vr);

/* so_long.c */
char	*dupe_str(char *s, int len_str);

/* utils_1.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
int		ft_strchr_sl(char *s, char c);
int		ft_strlen_sl(char *s);

/* utils_2.c */
void	free_map(t_prgm *vars);
int		ft_abs(int n);
char	*i2a(int nbr);
int		get_len(int n);

/* window.c */
int		ft_close_window(t_prgm *vars);
char	*choose_tile_path(char c);
void	display_map_window(t_prgm *vars);
void	init_moves_display(t_prgm *vr);
void	put_map_to_window(t_prgm *vars);

#endif