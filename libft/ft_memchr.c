/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:12:27 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 01:38:00 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const char	*sc;
	size_t		x;

	sc = (const char *)src;
	x = -1;
	while (++x < n)
		if (*(sc + x) == (char)c)
			return ((void *)sc + x);
	return (NULL);
}
