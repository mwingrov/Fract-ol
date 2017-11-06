/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:07:55 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 00:45:44 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t p)
{
	char	*psycho;

	psycho = dest;
	while (*psycho != '\0')
	{
		psycho++;
	}
	while (*src != '\0' && p > 0)
	{
		*psycho = *src;
		psycho++;
		src++;
		p--;
	}
	*psycho = '\0';
	return (dest);
}
