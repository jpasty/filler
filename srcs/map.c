/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:30:54 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/29 21:55:26 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_content(t_plateau *plat)
{
	int 		y;
	int 		x;
	char 		*line;
	char 		*entry;
	//TOO MANY STRINGS!!!!
	y = 0;
	while (y < plat->hght)
	{
		if (gnl(STDIN_FILENO, &line) <= 0)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		entry = ft_strrchr(line, ' ');
		x = 0;
		while (x < plat->wdth)
		{
			plat->cells[y][x]->crd.x = x;
			plat->cells[y][x]->crd.y = y;
			if (entry[x] != '.' && entry[x] != 'O' && entry[x] != 'X')
				return (EXIT_FAILURE);
			plat->cells[y][x]->cntnt = ft_toupper(entry[x]);
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static int		get_plateau_size(t_plateau *plt)
{
	char 		**split;
	char		*line;

	line = NULL;
	if (gnl(STDIN_FILENO, &line) != 1 || !(split = ft_strsplit(line, ' ')))
	{
		free(line);
		return (EXIT_FAILURE);
	}
	free(line);
	if (split[1] && split[2])
	{
		if ((plt->hght = ft_atoi(split[1])) == 0 ||
				(plt->wdth = ft_atoi(split[2])) == 0)
			return (EXIT_FAILURE);
	}
	ft_free_split(split);
	if (gnl(STDIN_FILENO, &line) <= 0)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int 			define_map(t_contest *cntst)
{
	int			h;
	int 		w;

	h = 0;
	if (get_plateau_size(&(cntst->plat)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cntst->plat.cells = malloc(sizeof(t_cell *) * (cntst->plat.hght));
	while (h < cntst->plat.hght)
	{
		cntst->plat.cells[h] =
				malloc(sizeof(t_cell **) * (cntst->plat.wdth));
		w = 0;
		while (w < cntst->plat.wdth)
			if (!(cntst->plat.cells[h][w++] = ft_memalloc(sizeof(t_cell))))
				return (EXIT_FAILURE);
		h++;
	}
//	while (gnl(STDIN_FILENO, &line) == 1 && !ft_strnequ(line, "Piece", 5))
//	{
	if (get_content(&(cntst->plat)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
//	}
}