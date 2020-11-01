/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:46:35 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/01 10:00:45 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h> //don't forget to delete

int			user_define(t_contest *cntst)
{
	char	**split;
	char	*line;

	freopen("../111","r",stdin); // for debugging opportunity. Delete in future.
	line = NULL;
	if (gnl(STDIN_FILENO, &line) != 1)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	split = ft_strsplit(line, ' ');
	if (!split || !ft_strequ(split[0], "$$$") ||
				!ft_strequ(split[1],"exec") || *split[2] != 'p')
	{
		ft_free_split(split);
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
