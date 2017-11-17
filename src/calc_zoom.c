/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:12:00 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 16:12:01 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** size[0] = width
** size[1] = height
** size[2], size[3], size[4] = y min
** size[5], size[6], size[7] = y max
*/

static void	calc_zoom2(t_var *var, int *size)
{
	int tmp_zoom;

	var->zoom = ((var->modif_zoom) ? (var->height / size[1]) : (var->zoom));
	tmp_zoom = ((var->modif_zoom) ? (var->width / size[0]) : (var->zoom));
	var->zoom = ((var->zoom < tmp_zoom) ? (var->zoom) : (tmp_zoom));
	var->sav->zoom = var->zoom;
	var->x_dec = ((var->modif_dec) ? (calc_x_space(var, size[0])) : \
																(var->x_dec));
	var->y_dec = ((var->modif_dec) ? (calc_y_space(var, size)) : (var->y_dec));
	var->sav->x_dec = var->x_dec;
	var->sav->y_dec = var->y_dec;
}

void		calc_zoom(t_var *var)
{
	int		*size;

	var->zoom = ((var->sav->zoom == -1) ? (1) : (var->zoom));
	size = NULL;
	size = calc_height(var->chain, calc_widht(var->chain), size, var);
	if (var->modif_zoom && (size[1] >= var->height || size[0] >= var->width))
	{
		while (size[0] >= var->width)
			var->width += 100;
		while (size[1] >= var->height)
			var->height += 100;
		calc_zoom(var);
	}
	else
		calc_zoom2(var, size);
}
