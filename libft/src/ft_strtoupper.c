/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:37:30 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 11:37:31 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtoupper(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	res = ft_strnew(ft_strlen(str));
	while (str && str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	ft_strdel(&str);
	return (res);
}
