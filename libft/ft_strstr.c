/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:50:16 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 01:37:30 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen((char *)s2);
	if (*s2 == 0)
		return ((char *)s1);
	while (*s1)
		if (!ft_memcmp(s1++, s2, len))
			return ((char *)s1 - 1);
	return (0);
}
