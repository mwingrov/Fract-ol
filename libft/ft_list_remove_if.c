/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 16:37:22 by jelefebv          #+#    #+#             */
/*   Updated: 2017/09/04 14:57:46 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && cmp((*begin_list)->content, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (cmp(i->next->content, data_ref) == 0)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}
