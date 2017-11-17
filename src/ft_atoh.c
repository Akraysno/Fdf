/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:00:48 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/13 10:00:50 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_pow(int nb, int pow)
{
	long int	res;

	res = nb;
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		res *= nb;
		pow--;
	}
	return (res);
}

static int	convert_hexa(int num, char *str)
{
	int			i;
	int			pow;
	long int	nb;

	i = 0;
	pow = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			nb = str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			nb = str[i] - 'A' + 10;
		if (str[i] >= '0' && str[i] <= '9')
			nb = str[i] - '0';
		num += nb * ft_pow(16, pow);
		i--;
		pow++;
	}
	return (num);
}

int			ft_atoh(const char *nptr)
{
	int			i;
	long int	num;
	char		*str;
	char		*tmp;

	str = NULL;
	i = 0;
	num = 0;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '0' && nptr[i + 1] == 'x')
		i += 2;
	while (((nptr[i] >= '0') && (nptr[i] <= '9')) || ((nptr[i] >= 'a') && \
			(nptr[i] <= 'f')) || ((nptr[i] >= 'A') && (nptr[i] <= 'F')))
	{
		tmp = ft_strsub(nptr, i, 1);
		str = ft_concat(str, tmp);
		ft_strdel(&tmp);
		i++;
	}
	num = convert_hexa(num, str);
	ft_strdel(&str);
	return (num);
}
