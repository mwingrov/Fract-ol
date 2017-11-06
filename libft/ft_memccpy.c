/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:14:06 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/17 12:09:58 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str;
	size_t	x;

	x = -1;
	str = dest;
	while (++x < n)
	{
		*(str + x) = *((unsigned char *)src + x);
		if (*((unsigned char *)src + x) == (unsigned char)c)
			return (dest + x + 1);
	}
	return (NULL);
}
