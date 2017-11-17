/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:17:45 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 12:17:15 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** TODO
**
** prendre en compte les degrader de couleurs
** Repeindre toutes les tuiles en noir au fur et a mesure du tracage
** Tracer dans le meme sens que rendu (voire gerer des rotations)
*/

void	horizontal_lines(t_var *var, int *x, int *y, t_fdf *link)
{
	if ((x[0] <= x[1]) && (x[1] - x[0] >= ft_abs(y[1] - y[0])))
		draw_case_1(var, x, y, link->color);
	if ((y[0] <= y[1]) && (y[1] - y[0] >= ft_abs(x[1] - x[0])))
		draw_case_3(var, x, y, link->color);
	if ((y[1] <= y[0]) && (y[0] - y[1] >= ft_abs(x[0] - x[1])))
		draw_case_4(var, x, y, link->color);
}

void	vertical_lines(t_var *var, int *x1, int *y1, t_fdf *link)
{
	int		x[2];
	int		y[2];

	(void)link;
	(void)var;
	x[0] = x1[2];
	x[1] = x1[3];
	y[0] = y1[2];
	y[1] = y1[3];
	if ((x[1] <= x[0]) && (x[0] - x[1] >= ft_abs(y[0] - y[1])))
		draw_case_2(var, x, y, link->color);
	if ((y[0] <= y[1]) && (y[1] - y[0] >= ft_abs(x[1] - x[0])))
		draw_case_3(var, x, y, link->color);
	if ((y[1] <= y[0]) && (y[0] - y[1] >= ft_abs(x[0] - x[1])))
		draw_case_4(var, x, y, link->color);
}

void	put_last_line(t_var *var, t_fdf *link)
{
	int		x[2];
	int		y[2];

	while (link && link->next)
	{
		x[0] = var->x_dec + (link->x - link->y) * var->zoom;
		x[1] = var->x_dec + (link->next->x - link->next->y) * var->zoom;
		y[0] = var->y_dec + ((link->x + link->y) - (link->z + ((link->z) ? \
										(var->add_z) : (0)))) * var->zoom / 2;
		y[1] = var->y_dec + ((link->next->x + link->next->y) - (link->next->z \
					+ ((link->next->z) ? (var->add_z) : (0)))) * var->zoom / 2;
		if ((x[0] <= x[1]) && (x[1] - x[0] >= ft_abs(y[1] - y[0])))
			draw_case_1(var, x, y, link->color);
		if ((y[0] <= y[1]) && (y[1] - y[0] >= ft_abs(x[1] - x[0])))
			draw_case_3(var, x, y, link->color);
		if ((y[1] <= y[0]) && (y[0] - y[1] >= ft_abs(x[0] - x[1])))
			draw_case_4(var, x, y, link->color);
		link = link->next;
	}
}

void	put_lines(t_var *var)
{
	int		x[4];
	int		y[4];
	t_fdf	*link;

	link = var->chain;
	while (link && link->down && link->next)
	{
		x[0] = var->x_dec + (link->x - link->y) * var->zoom;
		x[1] = var->x_dec + (link->next->x - link->next->y) * var->zoom;
		y[0] = var->y_dec + ((link->x + link->y) - (link->z + ((link->z) ? \
						(var->add_z) : (0)))) * var->zoom / 2;
		y[1] = var->y_dec + ((link->next->x + link->next->y) - (link->next->z\
					+ ((link->next->z) ? (var->add_z) : (0)))) * var->zoom / 2;
		x[2] = var->x_dec + (link->x - link->y) * var->zoom;
		x[3] = var->x_dec + (link->down->x - link->down->y) * var->zoom;
		y[2] = var->y_dec + ((link->x + link->y) - (link->z + ((link->z) ? \
						(var->add_z) : (0)))) * var->zoom / 2;
		y[3] = var->y_dec + ((link->down->x + link->down->y) - (link->down->z\
					+ ((link->down->z) ? (var->add_z) : (0)))) * var->zoom / 2;
		horizontal_lines(var, x, y, link);
		vertical_lines(var, x, y, link);
		link = link->next;
	}
	put_last_line(var, link);
}
