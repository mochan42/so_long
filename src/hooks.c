/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:21:27 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 01:11:23 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_prgm *vars)
{
	if (keycode == KEY_W)
	{
		ft_printf("Player go up\n");
		move_up(vars);
	}
	if (keycode == KEY_A)
	{
		ft_printf("Player go down\n");
		move_down(vars);
	}
	if (keycode == KEY_S)
	{
		ft_printf("Player go left\n");
		move_left(vars);
	}
	if (keycode == KEY_D)
	{
		ft_printf("Player go right\n");
		move_right(vars);
	}
	if (keycode == KEY_ESC)
		ft_close_window(vars);
	return (0);
}
