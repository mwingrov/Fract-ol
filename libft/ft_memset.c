/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 19:44:46 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/01 17:48:43 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*s1;

	count = 0;
	s1 = (char *)str;
	while (count < n)
	{
		s1[count] = c;
		count++;
	}
	return (s1);
}
