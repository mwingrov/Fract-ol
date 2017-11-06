/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:18:01 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/24 17:24:33 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		a;

	a = 0;
	i = num(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		a = 1;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	while (i > 0)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	str[0] = (a) ? '-' : (n % 10) + 48;
	return (str);
}
