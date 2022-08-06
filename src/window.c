/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:16:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 18:14:23 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_free mlx xpm file to image
int	ft_close_window(t_prgm *vars)
{
	// free_all(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exit so_long");
	exit (0);
	return (0);
}
