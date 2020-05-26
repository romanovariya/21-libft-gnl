/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:05:00 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/11 23:56:32 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	char		*lastdest;
	const char	*lastsource;

	dest = dst;
	source = src;
	if (dest < source)
		while (n)
		{
			*dest = *source;
			dest++;
			source++;
			n--;
		}
	else
	{
		lastdest = dest + (n - 1);
		lastsource = source + (n - 1);
		while (n--)
			*lastdest-- = *lastsource--;
	}
	return (dst);
}
