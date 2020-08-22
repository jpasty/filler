/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:02:25 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/22 16:55:57 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct	s_x
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_cell
{
	t_xy		crd;
	int			heat;
	int			cntnt;
}				t_cell;

typedef struct	s_plateau
{
	int			hght;
	int			wdth;
	t_cell		***cells;
}				t_plateau;

typedef struct	s_token
{
	int			hght;
	int			wdth;
	t_xy		**crd;
}				t_token;

typedef struct	s_user
{
	char		sym;
	int 		num;
}				t_user;

typedef struct	s_contest
{
	t_user		plr;
	t_user		foe;
	t_plateau	plat;
}				t_contest;

int 			define_user(char *line, t_contest *cntst);
void 			define_map(t_contest *cntst, char *line);

#endif