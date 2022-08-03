/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/03 15:47:20 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_window(t_prgm *prgm)
{
	mlx_destroy_window(prgm->mlx, prgm->win);
	printf("exit so_long");
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_prgm *prgm)
{
	if(prgm)
		printf("keycode is : %d\n", keycode);
	if(keycode == 13)
		printf("Player go up\n");
	if(keycode == 0)
		printf("Player go down\n");
	if(keycode == 1)
		printf("Player go left\n");
	if(keycode == 2)
		printf("Player go right\n");
	if(keycode == 53)
		ft_close_window(prgm);
	return (0);
}

int	main()
{	
	t_prgm	prgm;
	
	prgm.mlx = mlx_init();
	prgm.win = mlx_new_window(prgm.mlx, 640, 480, "Hello world!");
	mlx_key_hook(prgm.win, key_hook, &prgm);
	mlx_hook(prgm.win, 17, 0, ft_close_window, &prgm);
	mlx_loop(prgm.mlx);
}

