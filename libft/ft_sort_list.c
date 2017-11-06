/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 07:11:01 by mwingrov          #+#    #+#             */
/*   Updated: 2017/09/04 15:41:28 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur1;
	t_list	*cur2;

	cur1 = lst;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cmp(cur1->data, cur2->data) != 1)
				ft_swap(&cur1->data, &cur2->data);
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (lst);
}
