/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:45:36 by gauffret          #+#    #+#             */
/*   Updated: 2017/04/11 15:45:38 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** action 1 = y min
** action 2 = y max
*/

int		*save_pos_point(t_fdf *link, int *size, t_var *var)
{
	size[2] = link->x;
	size[3] = link->y;
	size[4] = link->z + ((link->z) ? (var->add_z) : (0));
	return (size);
}

int		*calc_height(t_fdf *chain, int width, int *size, t_var *var)
{
	t_fdf	*link;
	int		result;
	int		tmp;
	int		result2;

	link = chain;
	size = (int *)malloc(sizeof(int) * 5);
	if (!link || !size)
		return (0);
	size[0] = width;
	result = (link->x + link->y - (link->z + (link->z ? var->add_z : 0))) / 2;
	result2 = result;
	while (link)
	{
		tmp = (link->x + link->y - (link->z + (link->z ? var->add_z : 0))) / 2;
		if (result <= tmp)
			result = tmp;
		if (result <= tmp)
			size = save_pos_point(link, size, var);
		if (result2 >= tmp)
			result2 = tmp;
		link = link->next;
	}
	size[1] = ft_abs(result - result2);
	return (size);
}

int		calc_widht(t_fdf *chain)
{
	int		width;
	int		tmp;
	t_fdf	*link;

	link = chain;
	width = 0;
	tmp = 0;
	if (!link)
		return (width);
	while (link && link->next && (link->y == link->next->y))
		link = link->next;
	width = link->x - link->y;
	link = chain;
	while (link && link->down)
		link = link->down;
	tmp = link->x - link->y;
	width = ft_abs(width - tmp);
	return (width);
}

int		calc_y_space(t_var *var, int *size)
{
	t_fdf	*link;
	int		result;
	int		h;

	link = var->chain;
	h = (((link->x + link->y - (link->z + ((link->z) ? (var->add_z) : (0)))) \
		* var->zoom / 2) - ((size[2] + size[3] - size[4]) * var->zoom / 2));
	result = var->height - ((var->height - (size[1] * var->zoom)) / 2) - \
		ft_abs(h);
	return (result);
}

int		calc_x_space(t_var *var, int x_size)
{
	t_fdf	*link;
	int		y_tmp;
	int		x_tmp;
	int		result;
	int		widht_f;

	link = var->chain;
	while (link && link->next && link->y == link->next->y)
		link = link->next;
	x_tmp = link->x;
	y_tmp = link->y;
	link = var->chain;
	widht_f = (((x_tmp - y_tmp) * var->zoom) - ((link->x - link->y) * \
												var->zoom));
	result = var->width - ((var->width - (x_size * var->zoom)) / 2) - widht_f;
	return (result);
}
