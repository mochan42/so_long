/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 16:56:54 by mochan           ###   ########.fr       */
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
	void		*mlx;
	void		*win;
	char		*map_path;
	int			col;
	int			row;
	char		**map;
	int			*wid;
	int			*hei;
	void		*img;
	char		*path_img_1st_col;
	char		*path_img_plrr;
	char		*path_img_plrl;
	int			exit_nb;
	int			player_nb;
	int			collect_nb;
	int			invalid_char;
	int			pxm;
	int			pym;
	int			pxw;
	int			pyw;
	int			steps;
	int			mxw;
	int			myw;
	int			mcxw;
	int			b;
	int			w;
	int			b_animate_fc;
	int			fc_located;
	int			fcxm;
	int			fcym;
	int			fcxw;
	int			fcyw;
	int			counter;
	int			b_right;
	int			b_left;
	char		*path_img_vilr;
	int			vxm;
	int			vym;
	int			vxw;
	int			vyw;
	int			b_activate_vill;
	int			b_v_right;
	int			b_v_left;
	int			b_counter_vil_mot;
}				t_prgm;

/* ########################################################################## */
/* CONSTANTS */

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define SPEED 30
# define SPEED_2 15
# define SPEED_3 10
# define SPEED_4 150

/* ########################################################################## */
/* FUNCTIONS */

/* animation_1.c */
void	animate_1st_collectible(t_prgm *vr);
int		ct_to_frame(int counter, int frames);
void	find_1st_collectible(t_prgm *vr);
void	ft_image_1st_collectible_mapping(t_prgm *vars, int n);
void	ft_update_image_1st_collectible(t_prgm *vars, int n);

/* animation_2.c */
void	animate_player(t_prgm *vr);
int		ct_to_frame_2(int counter, int frames);
void	find_player(t_prgm *vr);
void	ft_image_player_mapping(t_prgm *vars, int n);
void	ft_update_image_player_rg(t_prgm *vars, int n);

/* animation_3.c */
void	ft_image_player_mapping_lf(t_prgm *vars, int n);
void	ft_update_image_player_lf(t_prgm *vars, int n);

/* hooks.c */
int		key_hook(int keycode, t_prgm *vars);

/* map.c */
char	**store_map(t_prgm vars);

/* map_checks_1.c */
void	check_collectible(t_prgm *vars);
void	check_exit(t_prgm *vars);
void	check_map(t_prgm *vars);
void	check_player(t_prgm *vars);
void	check_valid_char(t_prgm *vars);

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

/* moves_3.c */
void	put_black_patch_to_window(t_prgm *vr);
void	put_black_patch_to_window_bool_right(t_prgm *vr);
void	put_black_patch_to_window_bool_left(t_prgm *vr);

/* moves_4.c */
void	collectible_handling_move_up(t_prgm *vr);
void	collectible_handling_move_down(t_prgm *vr);
void	collectible_handling_move_right(t_prgm *vr);
void	collectible_handling_move_left(t_prgm *vr);

/* so_long.c */
char	*dupe_str(char *s, int len_str);

/* utils_1.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
int		ft_strchr_sl(char *s, char c);
int		ft_strlen_sl(char *s);
int		get_len(int n);

/* utils_2.c */
void	free_map(t_prgm *vars);
int		ft_abs(int n);
char	*i2a(int nbr);
void	init_animation(t_prgm *vr);

/* villain_1.c */
void	animate_villain(t_prgm *vr);
void	ft_image_villain_mapping_rg(t_prgm *vars, int n);
void	ft_update_image_villain_rg_down(t_prgm *vars, int n);
void	ft_update_image_villain_rg_up(t_prgm *vars, int n);
void	villain_motion(t_prgm *vr, int n);

/* villain_2.c */
int		ct_to_frame_3(int counter, int frames);
int		ct_to_frame_4(int counter, int frames);
void	init_villain_pos(t_prgm *vr);
void	find_villain(t_prgm *vr);

/* villain_3.c */
void	image_handling_after_villain_move_down(t_prgm *vr);
void	image_handling_after_villain_move_up(t_prgm *vr);

/* window.c */
char	*choose_tile_path(char c);
int		ft_close_window(t_prgm *vars);
void	display_map_window(t_prgm *vars);
void	init_moves_display(t_prgm *vr);
void	put_map_to_window(t_prgm *vars);

#endif