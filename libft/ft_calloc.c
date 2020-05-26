/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:00:49 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/19 16:16:20 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char			*temps;
	unsigned int	sum;

	sum = num * size;
	temps = malloc(sum);
	if (temps == 0)
		return (temps);
	ft_bzero(temps, sum);
	return (temps);
}
