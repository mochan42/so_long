/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:21:27 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 11:25:28 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_prgm *vars)
{
	if(vars)
		ft_printf("keycode is : %d\n", keycode);
	if(keycode == 13)
		ft_printf("Player go up\n");
	if(keycode == 0)
		ft_printf("Player go down\n");
	if(keycode == 1)
		ft_printf("Player go left\n");
	if(keycode == 2)
		ft_printf("Player go right\n");
	if(keycode == 53)
		ft_close_window(vars);
	return (0);
}