/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:16:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 11:20:43 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_window(t_prgm *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exit so_long");
	exit (0);
	return (0);
}