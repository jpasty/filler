/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:46:35 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 23:00:56 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			user_define(t_contest *cntst)
{
	char	**split;
	char	*line;

	line = NULL;
	if (gnl(0, &line) != 1)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	split = ft_strsplit(line, ' ');
	if (!split || !ft_strequ(split[0], "$$$") ||
				!ft_strequ(split[1],"exec") || *split[2] != 'p')
	{
		ft_free_split(split);
		free(line);
		return (EXIT_FAILURE);
	}
	cntst->plr = split[2][1] - '0';
	cntst->foe = cntst->plr % 2 + 1;
	cntst->plr = cntst->plr == 1 ? 'O' : 'X';
	cntst->foe = cntst->plr == 'O' ? 'X' : 'O';
	ft_free_split(split);
	free(line);
	return (EXIT_SUCCESS);
}
