/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:47:16 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 01:46:45 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *l;

	l = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			l = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (l);
}
