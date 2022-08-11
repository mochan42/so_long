/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:20:22 by mochan            #+#    #+#             */
/*   Updated: 2022/08/11 15:45:00 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_prgm *vr)
{
	char	*str;

	if (vr->map[vr->pym - 1][vr->pxm] == '1' ||
	(vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_up_to_window(vr);
	if (vr->map[vr->pym - 1][vr->pxm] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pym - 1][vr->pxm] = '0';
		vr->b_animate = 0;
	}
	if (vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pym -= 1;
	vr->pyw -= 64;
	put_black_patch_to_window(vr);
	vr->steps += 1;
	str = i2a(vr->steps);
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, str);
	free(str);
}

void	move_down(t_prgm *vr)
{
	char	*str;

	if (vr->map[vr->pym + 1][vr->pxm] == '1' ||
	(vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_down_to_window(vr);
	if (vr->map[vr->pym + 1][vr->pxm] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pym + 1][vr->pxm] = '0';
		vr->b_animate = 0;
	}
	if (vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pym += 1;
	vr->pyw += 64;
	put_black_patch_to_window(vr);
	vr->steps += 1;
	str = i2a(vr->steps);
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, str);
	free(str);
}

void	move_right(t_prgm *vr)
{
	char	*str;

	if (vr->map[vr->pym][vr->pxm + 1] == '1' ||
	(vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_right_to_window(vr);
	if (vr->map[vr->pym][vr->pxm + 1] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pym][vr->pxm + 1] = '0';
		vr->b_animate = 0;
	}
	if (vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pxm += 1;
	vr->pxw += 64;
	put_black_patch_to_window(vr);
	vr->steps += 1;
	str = i2a(vr->steps);
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, str);
	free(str);
}

void	move_left(t_prgm *vr)
{
	char	*str;

	if (vr->map[vr->pym][vr->pxm - 1] == '1' ||
	(vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_left_to_window(vr);
	if (vr->map[vr->pym][vr->pxm - 1] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pym][vr->pxm - 1] = '0';
		vr->b_animate = 0;
	}
	if (vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pxm -= 1;
	vr->pxw -= 64;
	put_black_patch_to_window(vr);
	vr->steps += 1;
	str = i2a(vr->steps);
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, str);
	free(str);
}
