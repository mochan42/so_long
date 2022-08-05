/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 23:20:11 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ########################################################################## */
/* INCLUDES */

#include <stdio.h>
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
	void	*height;
	void	*width;
}				t_prgm;


/* ########################################################################## */
/* FUNCTIONS */

/* window.c */
int	ft_close_window(t_prgm *vars);

/* hooks.c */
int	key_hook(int keycode, t_prgm *vars);

/* so_long.c */
char	*dupe_str(char *s, int len_str);

/* map.c */
int		count_nb_col(char *map_path);
int		count_nb_row(char *map_path);
char	**store_map(char *map_path, int nb_row);
int		put_map_to_window(t_prgm *vars, char **map, int nb_col, int nb_row);
int		display_map_window(t_prgm *vars, char *map_path);
