/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:30:54 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/22 17:59:38 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_content_from_raw(char *raw, t_cell ***cells)
{
	
}
static void	get_plateau_size(t_plateau *plt, char *line)
{
	char 	**split;

	split = ft_strsplit(line, ' ');
	if (split[1] && split[2])
	{
		plt->hght = ft_atoi(split[1]);
		plt->wdth = ft_atoi(split[2]);
	}
	free(line);
	ft_free_split(split);
}

void 		define_map(t_contest *cntst, char *line)
{
	char	*raw;

	if (gnl(STDIN_FILENO, &line) == 1)
	 	get_plateau_size(&(cntst->plat), line);
	gnl(STDIN_FILENO, line);
	free(line);
	while (gnl(STDIN_FILENO, &line) == 1 && !ft_strnequ(line, "Piece", 5))
	{
		raw = ft_strchr(line, ' ');
		get_content_from_raw(raw, cntst->plat.cells);
		free(line);
	}
}