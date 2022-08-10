/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:21:27 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 14:49:42 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_prgm *vars)
{
	if (keycode == KEY_W)
		move_up(vars);
	if (keycode == KEY_A)
		move_down(vars);
	if (keycode == KEY_S)
		move_left(vars);
	if (keycode == KEY_D)
		move_right(vars);
	if (keycode == KEY_ESC)
		ft_close_window(vars);
	return (0);
}
