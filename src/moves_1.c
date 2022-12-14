/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:20:22 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 19:33:02 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_prgm *vr)
{
	if (vr->map[vr->pym - 1][vr->pxm] == '1' ||
	(vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_up_to_window(vr);
	if (vr->map[vr->pym - 1][vr->pxm] == 'C')
		collectible_handling_move_up(vr);
	if (vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb != 0)
		return ;
	if ((vr->map[vr->pym - 1][vr->pxm] == 'E' && vr->collect_nb == 0)
		|| vr->map[vr->pym - 1][vr->pxm] == 'V')
		ft_close_window(vr);
	vr->map[vr->pym - 1][vr->pxm] = 'P';
	vr->map[vr->pym][vr->pxm] = '0';
	vr->pym -= 1;
	vr->pyw -= 64;
	vr->steps += 1;
	ft_printf("Movements : %d\n", vr->steps);
}

void	move_down(t_prgm *vr)
{
	if (vr->map[vr->pym + 1][vr->pxm] == '1' ||
	(vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_down_to_window(vr);
	if (vr->map[vr->pym + 1][vr->pxm] == 'C')
		collectible_handling_move_down(vr);
	if (vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb != 0)
		return ;
	if ((vr->map[vr->pym + 1][vr->pxm] == 'E' && vr->collect_nb == 0)
		|| vr->map[vr->pym + 1][vr->pxm] == 'V')
		ft_close_window(vr);
	vr->map[vr->pym + 1][vr->pxm] = 'P';
	vr->map[vr->pym][vr->pxm] = '0';
	vr->pym += 1;
	vr->pyw += 64;
	vr->steps += 1;
	ft_printf("Movements : %d\n", vr->steps);
}

void	move_right(t_prgm *vr)
{
	if (vr->map[vr->pym][vr->pxm + 1] == '1' ||
	(vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_right_to_window(vr);
	if (vr->map[vr->pym][vr->pxm + 1] == 'C')
		collectible_handling_move_right(vr);
	if (vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb != 0)
		return ;
	if ((vr->map[vr->pym][vr->pxm + 1] == 'E' && vr->collect_nb == 0)
		|| vr->map[vr->pym][vr->pxm + 1] == 'V')
		ft_close_window(vr);
	vr->map[vr->pym][vr->pxm + 1] = 'P';
	vr->map[vr->pym][vr->pxm] = '0';
	vr->pxm += 1;
	vr->pxw += 64;
	vr->steps += 1;
	ft_printf("Movements : %d\n", vr->steps);
}

void	move_left(t_prgm *vr)
{
	if (vr->map[vr->pym][vr->pxm - 1] == '1' ||
	(vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb != 0))
		return ;
	put_move_left_to_window(vr);
	if (vr->map[vr->pym][vr->pxm - 1] == 'C')
		collectible_handling_move_left(vr);
	if (vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb != 0)
		return ;
	if ((vr->map[vr->pym][vr->pxm - 1] == 'E' && vr->collect_nb == 0)
		|| vr->map[vr->pym][vr->pxm - 1] == 'V')
		ft_close_window(vr);
	vr->map[vr->pym][vr->pxm - 1] = 'P';
	vr->map[vr->pym][vr->pxm] = '0';
	vr->pxm -= 1;
	vr->pxw -= 64;
	vr->steps += 1;
	ft_printf("Movements : %d\n", vr->steps);
}
