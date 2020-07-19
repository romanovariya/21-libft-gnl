/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:59:42 by mbabette          #+#    #+#             */
/*   Updated: 2020/07/18 21:20:32 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	s[size] = '\0';
	return (s);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*src;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			src = (char *)&str[i];
			return (src);
		}
		i++;
	}
	if (str[i] == c)
	{
		src = (char *)&str[i];
		return (src);
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	while (*s1)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	*s3 = '\0';
	s3 -= (len1 + len2);
	return (s3);
}
