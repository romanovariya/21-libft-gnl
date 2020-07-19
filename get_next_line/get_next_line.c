/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:54:07 by mbabette          #+#    #+#             */
/*   Updated: 2020/07/19 17:25:49 by mbabette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_ret(char **line, char **ret, int r_bytes)
{
	char *ptr_n;
	char *tmp;

	if ((ptr_n = ft_strchr(*ret, '\n')))
	{
		*ptr_n = '\0';
		if (!(*line = ft_strdup(*ret)))
			return (-1);
		if (!(tmp = ft_strdup(++ptr_n)))
			return (-1);
		free(*ret);
		(*ret) = tmp;
		return (1);
	}
	else if (r_bytes == 0)
	{
		if (!(*line = ft_strdup(*ret)))
			return (-1);
		free(*ret);
		*ret = NULL;
		return (0);
	}
	return (1);
}

int	ft_check_err(int fd, char **line, char **ret, int r_bytes)
{
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || r_bytes < 0)
		return (-1);
	else if (r_bytes == 0 && (*ret == NULL || ret[0] == NULL))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	return (ft_check_ret(line, ret, r_bytes));
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			r_bytes;
	static char	*ret;
	char		*tmp;

	tmp = NULL;
	while ((r_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		if (r_bytes == -1)
			return (-1);
		buf[r_bytes] = '\0';
		if (ret == NULL)
		{
			if (!(ret = ft_strnew(1)))
				return (-1);
		}
		if (!(tmp = ft_strjoin(ret, buf)))
			return (-1);
		free(ret);
		ret = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_check_err(fd, line, &ret, r_bytes));
}
