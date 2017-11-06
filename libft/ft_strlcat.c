/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:03:08 by mwingrov          #+#    #+#             */
/*   Updated: 2017/08/31 11:19:27 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t_dst;
	size_t	t_src;

	t_dst = ft_strlen(dst);
	t_src = ft_strlen((char *)src);
	if (!(size > t_dst))
		return (size + t_src);
	ft_strncat(dst, src, size - t_dst - 1);
	return (t_dst + t_src);
}
