/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:37:21 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:12:46 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtolower(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	res = ft_strnew(ft_strlen(str));
	while (str && str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	ft_strdel(&str);
	return (res);
}
