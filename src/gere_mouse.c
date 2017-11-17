/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:10:58 by gauffret          #+#    #+#             */
/*   Updated: 2017/04/10 15:10:59 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		gere_mouse(int code, int x, int y, t_var *var)
{
	(void)x;
	(void)y;
	if (code == 5 && var->zoom - 1 > 0)
	{
		var->reload_map = 1;
		var->zoom -= 1;
	}
	if (code == 6)
	{
		var->reload_map = 1;
		var->zoom += 1;
	}
	if (var->reload_map == 1)
		run_put_map(var);
	return (1);
}
