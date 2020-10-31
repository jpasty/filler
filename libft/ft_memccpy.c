/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:14:15 by jpasty            #+#    #+#             */
/*   Updated: 2020/06/21 19:14:15 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	unsigned char		*str;

	if (dst == src)
		return (dst);
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (n--)
	{
		if ((*res++ = *str++) == (unsigned char)c)
			return (res);
	}
	return (NULL);
}
