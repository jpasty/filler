/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:03:31 by jpasty            #+#    #+#             */
/*   Updated: 2020/10/31 20:21:14 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy		min_reverse_coord(t_token *tkn)
{
	t_xy	min;
	int		i;
	int		x_min;
	int		y_min;

	i = 0;
	x_min = tkn->crd[i]->x;
	y_min = tkn->crd[i]->y;
	while (i < tkn->stars)
	{
		if (tkn->crd[i]->x < x_min)
			x_min = tkn->crd[i]->x;
		if (tkn->crd[i]->y < y_min)
			 y_min = tkn->crd[i]->y;
		i++;
	}
	min.x = x_min * -1;
	min.y = y_min * -1;
	return (min);
}

t_xy		*new_token_coord(int x, int y)
{
	t_xy	*new;

	if (!(new = ft_memalloc(sizeof(t_xy))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

int			check_line(const char *line, int *stars, int wdth)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (EXIT_FAILURE);
		if (line[i] == '*')
			(*stars)++;
		i++;
	}
	if (i != wdth)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			check_area_heat(t_contest *cntst, t_token *tkn, int x, int y)
{
	int		overlap;
	int		heat;
	int		y_bias;
	int		x_bias;
	int		i;

	overlap = 0;
	heat = 0;
	i = 0;
	while (i < tkn->stars)
	{
		y = tkn->crd[i]->y + y < 0 ? cntst->plat.hght + y - tkn->crd[i]->y : y;
		x = tkn->crd[i]->x + x < 0 ? cntst->plat.wdth + x - tkn->crd[i]->x : x;
		y_bias = tkn->crd[i]->y + y;
		x_bias = tkn->crd[i++]->x + x;
		if (y_bias < 0 || x_bias < 0 || y_bias >= cntst->plat.hght ||
				x_bias >= cntst->plat.wdth || cntst->plat.
				cells[y_bias][x_bias]->cntnt == cntst->foe)
			return (0);
		if (cntst->plat.cells[y_bias][x_bias]->cntnt != cntst->foe)
			heat += cntst->plat.cells[y_bias][x_bias]->heat;
		if (cntst->plat.cells[y_bias][x_bias]->cntnt == cntst->plr)
			overlap++;
	}
	return (overlap == 1 ? heat : 0);
}

void 		plateau_destroyer(t_plateau plateau)
{
	int h;
	int w;

	h = 0;
	while (h < plateau.hght)
	{
		w = 0;
		while (w < plateau.wdth)
			free(plateau.cells[h][w++]);
		free(plateau.cells[h++]);
	}
	free(plateau.cells);
}