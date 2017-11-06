/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:21:41 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/19 15:55:47 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	word(char const *str, char c)
{
	int	a;
	int	l;

	a = 0;
	l = 0;
	while (str[a] == c)
		a++;
	while (str[a] != c && str[a] != '\0')
	{
		a++;
		l++;
	}
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	x = -1;
	y = 0;
	while (++x < ft_countwords(s, c))
	{
		z = 0;
		if (!(str2[x] = ft_strnew(word(&s[y], c) + 1)))
			str2[x] = NULL;
		while (s[y] == c)
			y++;
		while (s[y] != c && s[y])
			str2[x][z++] = s[y++];
		str2[x][z] = '\0';
	}
	str2[x] = 0;
	return (str2);
}
