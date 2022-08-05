/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 00:36:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ########################################################################## */
/* INCLUDES */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx_opengl_20191021/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"


/* ########################################################################## */
/* STRUCTURES */

typedef struct	s_prgm {
	void	*mlx;
	void	*win;
	// void	*map_path;
}				t_prgm;


/* ########################################################################## */
/* FUNCTIONS */

/* hooks.c */
int		key_hook(int keycode, t_prgm *vars);

/* map.c */
char	*choose_tile_path(char c);
void	display_map_window(t_prgm *vars, char *map_path);
void	put_map_to_window(t_prgm *vars, char **map, int nb_col, int nb_row);
char	**store_map(char *map_path, int nb_row);

/* so_long.c */
char	*dupe_str(char *s, int len_str);

/* utils.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);

/* window.c */
int		ft_close_window(t_prgm *vars);
