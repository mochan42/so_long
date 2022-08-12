/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:59:59 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 20:22:00 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_prgm *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i])
			free(vars->map[i]);
		i++;
	}
	if (vars->map)
		free(vars->map);
}

void	free_all(t_prgm *vars)
{
	if (vars)
		free_map(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	// if (vars->mlx)
	// 	free(vars->mlx);
	ft_printf("exit so_long");
}

// void	quit_prgm(t_prgm *vars)
// {
// 	if (vars)
// 		free_all(vars);
// 	exit (0);
// }
