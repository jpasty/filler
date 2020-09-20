/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:02:25 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/12 09:45:59 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_token
{
	int			hght;
	int			wdth;
	t_xy		**crd;
}				t_token;

typedef struct	s_cell
{
	t_xy		crd;
	int			heat;
	int 		cntnt;
}				t_cell;

typedef struct	s_plateau
{
	int			hght;
	int			wdth;
	t_cell		***cells;
}				t_plateau;

typedef struct	s_contest
{
	int			plr;
	int			foe;
	t_plateau	plat;
}				t_contest;

int 			user_define(t_contest *cntst, char *line);
int 			map_define(t_contest *cntst);
void 			heat_define(t_contest *cntst);

#endif