/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:22:24 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/17 12:22:26 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		c;
	int		l;
	char	*str;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	c = -1;
	while (s[++c] == ' ' || s[c] == '\t' || s[c] == '\n')
		l--;
	if (l <= 0)
		l = 0;
	str = (char*)malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	s += c;
	c = -1;
	while (++c < l)
		str[c] = *s++;
	str[c] = '\0';
	return (str);
}
