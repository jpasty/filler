/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:30:54 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 22:38:36 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_content(t_cell **const *cells,
		char *row, int width, int height)
{
	int			w;

	w = 0;
	if (!row || (int)ft_strlen(row) > width || !cells[height])
		return (EXIT_FAILURE);
	while (w < width)
	{
		if (!cells[height][w] && !(cells[height][w] =
				(t_cell *)ft_memalloc(sizeof(t_cell))))
			return (EXIT_FAILURE);
		cells[height][w]->crd.x = w;
		cells[height][w]->crd.y = height;
		row[w] = (char)ft_toupper(row[w]);
		if (row[w] != '.' && row[w] != 'O' && row[w] != 'X')
			return (EXIT_FAILURE);
		cells[height][w]->cntnt = row[w];
		w++;
	}
	return (EXIT_SUCCESS);
}

int		get_area_size(int *height, int *width)
{
	char 		**split;
	char		*line;

	line = NULL;
	if (gnl(0, &line) != 1 || !(split = ft_strsplit(line, ' ')))
	{
		free(line);
		return (EXIT_FAILURE);
	}
	free(line);
	if (!(*split) || *split[0] != 'P')
	{
		ft_free_split(split);
		return (EXIT_FAILURE);
	}
	if (split[1] && split[2])
	{
		if ((*height = ft_atoi(split[1])) == 0 ||
				(*width = ft_atoi(split[2])) == 0)
			return (EXIT_FAILURE);
	}
	ft_free_split(split);
	return (EXIT_SUCCESS);
}

int 			map_define(t_contest *cntst)
{
	int			h;
	char		*line;

	h = 0;
	line = NULL;
	if (get_area_size(&(cntst->plat.hght), &(cntst->plat.wdth)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	gnl(0, &line);
	free(line);
	if (!cntst->plat.cells && !(cntst->plat.cells =
			ft_memalloc(sizeof(t_cell *) * (cntst->plat.hght + 1))))
		return (EXIT_FAILURE);
	while (h < cntst->plat.hght && gnl(0, &line) >= 0 && line)
	{
		!cntst->plat.cells[h] ? (cntst->plat.cells[h] =
				ft_memalloc(sizeof(t_cell *) * (cntst->plat.wdth + 1))) : 0;
		if (get_content(cntst->plat.cells, ft_strchr((line), ' ') + 1,
						cntst->plat.wdth, h++) != EXIT_SUCCESS)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}