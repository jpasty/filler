/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:08:31 by jpasty            #+#    #+#             */
/*   Updated: 2020/06/28 19:08:31 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lstrev(t_list **lst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *lst;
	next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*lst = prev;
}
