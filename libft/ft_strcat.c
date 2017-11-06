/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:09:47 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 01:32:48 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dest, const char *restrict src)
{
	size_t	death;
	int		l;

	l = 0;
	death = 0;
	while (dest[death])
		death++;
	while (src[l] != '\0')
	{
		dest[death + l] = src[l];
		l++;
	}
	dest[death + l] = '\0';
	return (dest);
}
