/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:10:10 by jpasty            #+#    #+#             */
/*   Updated: 2020/06/21 19:10:10 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*res;
	const unsigned char *str;
	size_t				i;

	i = 0;
	if (dst == src)
		return (dst);
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			res[len] = str[len];
	}
	else
	{
		while (len--)
		{
			res[i] = str[i];
			i++;
		}
	}
	return (res);
}
