/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:46:35 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/22 14:23:44 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					define_user(char *line, t_contest *cntst)
{
	char			**split;

	split = ft_strsplit(line, ' ');
	if (!split || !ft_strequ(split[0], "$$$") ||
				!ft_strequ(split[1],"exec") || *split[2] != 'p')
	{
		ft_free_split(split);
		return (EXIT_FAILURE);
	}
	cntst->plr.num = split[2][1] - '0';
	cntst->foe.num = cntst->plr.num % 2 + 1;
	cntst->plr.sym = cntst->plr.num == 1 ? 'o' : 'x';
	cntst->foe.sym = cntst->plr.sym == 'o' ? 'x' : 'y';
	return (EXIT_SUCCESS);
}
