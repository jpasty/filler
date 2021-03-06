/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 09:41:31 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 22:36:31 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int 	manhattan_distance(t_xy end, t_xy start)
{
	int		dx = end.x - start.x;
	int 	dy = end.y - start.y;

	return ft_abs(dx) + ft_abs(dy);
}

static void	heat_cell_calc(t_contest *cntst, t_cell *cell)
{
	int		heat;
	int 	h;
	int 	w;

	h = 0;
	while (h < cntst->plat.hght)
	{
		w = 0;
		while (w < cntst->plat.wdth)
		{
			if (cntst->plat.cells[h][w]->cntnt == cntst->foe)
			{
				heat = manhattan_distance(cell->crd, (t_xy){w, h});
				cell->heat = heat < cell->heat ? heat : cell->heat;
			}
			w++;
		}
		h++;
	}
}

void 		heat_define(t_contest *cntst)
{
	int		h;
	int 	w;

	h = 0;
	while (h < cntst->plat.hght)
	{
		w = 0;
		while (w < cntst->plat.wdth)
		{
			cntst->plat.cells[h][w]->heat =
					cntst->plat.cells[h][w]->cntnt == '.' ?
					cntst->plat.hght + cntst->plat.wdth : 0;
			if (cntst->plat.cells[h][w]->cntnt == '.')
				heat_cell_calc(cntst, cntst->plat.cells[h][w]);
			w++;
		}
		h++;
	}
}