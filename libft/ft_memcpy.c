/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 11:39:08 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 14:35:01 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str_dst, const void *str_src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	dst = (char *)str_dst;
	src = (char *)str_src;
	i = -1;
	while (++i < n)
		*(dst + i) = *(src + i);
	return (str_dst);
}
