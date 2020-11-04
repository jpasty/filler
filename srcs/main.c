/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 22:36:31 by jpasty           ###   ########.ru       */
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
		if (put_token(&cntst, token_define(0)) != EXIT_SUCCESS)
			break ;
	}
	plateau_destroyer(cntst.plat);
	ft_printf("%i %i\n", 0, 0);
	return (0);
}