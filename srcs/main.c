/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/10/31 20:14:47 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	static t_contest	cntst;

	if (user_define(&cntst) != EXIT_SUCCESS)
		return (-1);
	while (1)
	{
		if (map_define(&cntst) != EXIT_SUCCESS)
			break ;
		heat_define(&cntst);
		if (put_token(&cntst, token_define(STDIN_FILENO)) != EXIT_SUCCESS)
			break ;
	}
	plateau_destroyer(cntst.plat);
	ft_printf("%i %i\n", 0, 0);
	return (0);
}