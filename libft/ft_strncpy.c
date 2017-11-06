/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:11:15 by mwingrov          #+#    #+#             */
/*   Updated: 2017/06/11 01:40:59 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((size_t)ft_strlen((char *)s2) < n)
	{
		while (s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		while (i < n)
		{
			s1[i] = '\0';
			i++;
		}
		return (s1);
	}
	while (j < n)
	{
		s1[j] = s2[j];
		j++;
	}
	return (s1);
}
