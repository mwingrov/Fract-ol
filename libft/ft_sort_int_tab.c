/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:26:23 by mwingrov          #+#    #+#             */
/*   Updated: 2017/09/04 15:58:03 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int a, b;

	a = 0;
	while (a < size)
	{
		b = a;
		while (b < size)
		{
			if (tab[a] > tab[b])
				ft_swap(&tab[a], &tab[b]);
			b++;
		}
		a++;
	}
	return tab;
}
