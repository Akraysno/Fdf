/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:27:28 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 15:27:30 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_case_1(t_var *var, int *x, int *y, int color)
{
	int xtmp;
	int tmp;
	int line;
	int column;

	xtmp = x[0];
	tmp = (((x[1] - x[0]) == 0) ? (1) : ((x[1] - x[0])));
	while (xtmp <= x[1])
	{
		line = ((y[0] + ((y[1] - y[0]) * (xtmp - x[0]) / tmp)) * \
				(var->width * 4));
		column = (xtmp * 4);
		if (line / (var->width * 4) < var->height && line / \
			(var->width * 4) >= 0)
			if (column / 4 < var->width && column / 4 >= 0)
				*(unsigned *)(var->img_data + line + column) = color;
		xtmp++;
	}
}

void		draw_case_2(t_var *var, int *x, int *y, int color)
{
	int xtmp;
	int tmp;
	int line;
	int column;

	xtmp = x[1];
	tmp = (((x[0] - x[1]) == 0) ? (1) : ((x[0] - x[1])));
	while (xtmp <= x[0])
	{
		line = ((y[1] + ((y[0] - y[1]) * (xtmp - x[1]) / tmp)) * \
				var->width * 4);
		column = (xtmp * 4);
		if (line / (var->width * 4) < var->height && line / \
			(var->width * 4) >= 0)
			if (column / 4 < var->width && column / 4 >= 0)
				*(unsigned *)(var->img_data + line + column) = color;
		xtmp++;
	}
}

void		draw_case_3(t_var *var, int *x, int *y, int color)
{
	int ytmp;
	int tmp;
	int line;
	int column;

	ytmp = y[0];
	tmp = (((y[1] - y[0]) == 0) ? (1) : ((y[1] - y[0])));
	while (ytmp <= y[1])
	{
		column = ((x[0] + ((x[1] - x[0]) * (ytmp - y[0]) / tmp)) * 4);
		line = (ytmp * var->width * 4);
		if (column / 4 < var->width && column / 4 >= 0)
			if (line / (var->width * 4) < var->height && line / 4 >= 0)
				*(unsigned *)(var->img_data + line + column) = color;
		ytmp++;
	}
}

void		draw_case_4(t_var *var, int *x, int *y, int color)
{
	int ytmp;
	int tmp;
	int line;
	int column;

	ytmp = y[1];
	tmp = (((y[0] - y[1]) == 0) ? (1) : ((y[0] - y[1])));
	while (ytmp <= y[0])
	{
		column = ((x[1] + ((x[0] - x[1]) * (ytmp - y[1]) / tmp)) * 4);
		line = (ytmp * var->width * 4);
		if (column / 4 < var->width && column / 4 >= 0)
			if (line / (var->width * 4) < var->height && line / 4 >= 0)
				*(unsigned *)(var->img_data + line + column) = color;
		ytmp++;
	}
}
