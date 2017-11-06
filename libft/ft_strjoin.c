/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:05:59 by dpillay           #+#    #+#             */
/*   Updated: 2017/06/09 08:03:18 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	s1_l;
	size_t	s2_l;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = ft_strnew(s1_l + s2_l);
	if (!str)
		return (NULL);
	x = -1;
	y = -1;
	while (++x < s1_l)
		*(str + x) = *(s1 + x);
	while (++y < s2_l)
		*(str + x++) = *(s2 + y);
	return (str);
}
