/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:16:27 by gauffret          #+#    #+#             */
/*   Updated: 2017/04/11 11:16:28 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	reset_z(t_var *var)
{
	var->reload_map = 1;
	var->add_z = 0;
}

void	center_map(t_var *var)
{
	int		*size;

	var->modif_dec = 1;
	var->reload_map = 1;
	size = NULL;
	size = calc_height(var->chain, calc_widht(var->chain), size, var);
	var->x_dec = calc_x_space(var, size[0]);
	var->y_dec = calc_y_space(var, size);
	var->sav->x_dec = var->x_dec;
	var->sav->y_dec = var->y_dec;
}

void	reset_zoom(t_var *var)
{
	int		*size;
	int		tmp_zoom;

	var->reload_map = 1;
	var->modif_zoom = 1;
	var->zoom = 1;
	size = NULL;
	size = calc_height(var->chain, calc_widht(var->chain), size, var);
	var->zoom = var->height / size[1];
	tmp_zoom = var->width / size[0];
	var->zoom = ((var->zoom < tmp_zoom) ? (var->zoom) : (tmp_zoom));
	var->sav->zoom = var->zoom;
}

void	reset_var(t_var *var)
{
	var->reload_map = 1;
	var->modif_zoom = 1;
	var->modif_dec = 1;
	var->x_dec = var->sav->x_dec;
	var->y_dec = var->sav->y_dec;
	var->zoom = var->sav->zoom;
	var->add_z = 0;
	var->pos_img_y = 0;
	var->pos_img_x = 0;
	modif_color(var, 2);
	calc_zoom(var);
}
