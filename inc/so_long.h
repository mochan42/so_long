/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/03 16:58:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_prgm {
	void	*mlx;
	void	*win;
}				t_prgm;
