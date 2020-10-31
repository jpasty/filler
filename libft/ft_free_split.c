/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:03:06 by jpasty            #+#    #+#             */
/*   Updated: 2020/06/21 19:03:06 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_split(char **split)
{
	size_t i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}
