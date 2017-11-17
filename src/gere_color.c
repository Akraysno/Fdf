/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:18:55 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 15:18:57 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		modif_color(t_var *var, int action)
{
	t_fdf *link;

	link = var->chain;
	while (link)
	{
		if (action == 1)
			link->color = var->color;
		if (action == 2)
			link->color = link->sav_color;
		link = link->next;
	}
}

static void	rainbow(t_var *var)
{
	var->color = var->rbw->color[var->rbw->index];
	var->rbw->index++;
	if (var->rbw->index == 12)
		var->rbw->index = 0;
}

void		init_rbw(t_var *var)
{
	var->rbw = (t_rbw *)malloc(sizeof(t_rbw));
	var->rbw->color[0] = 0x00330066;
	var->rbw->color[1] = 0x00333399;
	var->rbw->color[2] = 0x003399FF;
	var->rbw->color[3] = 0x00339999;
	var->rbw->color[4] = 0x00339933;
	var->rbw->color[5] = 0x0099CC33;
	var->rbw->color[6] = 0x00FFFF33;
	var->rbw->color[7] = 0x00FFCC33;
	var->rbw->color[8] = 0x00FF9933;
	var->rbw->color[9] = 0x00FF3300;
	var->rbw->color[10] = 0x00FF3366;
	var->rbw->color[11] = 0x00990066;
	var->rbw->index = 0;
}

static void	choose_color_2(int key, t_var *var)
{
	if (key == 35)
		var->color = 0x00BC00B6;
	if (key == 17)
		var->color = 0x00643611;
	if (key == 48)
		rainbow(var);
	modif_color(var, 1);
	if (key == 51)
		modif_color(var, 2);
}

void		choose_color(int key, t_var *var)
{
	var->reload_map = 1;
	if (key == 15)
		var->color = 0x00FF0000;
	if (key == 5)
		var->color = 0x0000FF00;
	if (key == 11)
		var->color = 0x000000FF;
	if (key == 2)
		var->color = 0x00000000;
	if (key == 13)
		var->color = 0x00FFFFFF;
	if (key == 46)
		var->color = 0x00FF00FF;
	if (key == 8)
		var->color = 0x0000FFFF;
	if (key == 16)
		var->color = 0x00FFFF00;
	if (key == 31)
		var->color = 0x00CC5F00;
	if (key == 1)
		var->color = 0x007F7F7F;
	if (key == 9)
		var->color = 0x006400BC;
	choose_color_2(key, var);
}
