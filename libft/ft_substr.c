/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 01:47:55 by mbabette          #+#    #+#             */
/*   Updated: 2020/05/20 21:38:27 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	length;
	int		sublen;
	size_t	i;

	length = ft_strlen(s);
	if (start > length)
		return (NULL);
	if (start + len > length)
		len = (length - start);
	sublen = length - start + 1;
	substr = malloc(sizeof(char) * sublen);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
