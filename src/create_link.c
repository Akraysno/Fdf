/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:20:53 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/01 10:20:55 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf			*create_first_link(t_fdf *chain, int color, int *p, int z)
{
	t_fdf	*link;

	link = (t_fdf *)malloc(sizeof(t_fdf));
	if (!link)
		return (NULL);
	link->x = p[0];
	link->sav_x = p[0];
	link->y = p[1];
	link->sav_y = p[1];
	link->z = z;
	link->sav_z = z;
	link->color = color;
	link->sav_color = color;
	link->next = NULL;
	link->down = NULL;
	link->prev = NULL;
	link->up = NULL;
	chain = link;
	return (chain);
}

static void		init_new_link(t_fdf *new_link, int *p, int z, int color)
{
	new_link->x = p[0];
	new_link->sav_x = p[0];
	new_link->y = p[1];
	new_link->sav_y = p[1];
	new_link->z = z;
	new_link->sav_z = z;
	new_link->color = color;
	new_link->sav_color = color;
}

t_fdf			*add_link(t_fdf *chain, int color, int *p, int z)
{
	t_fdf	*link;
	t_fdf	*new_link;

	link = chain;
	new_link = (t_fdf *)malloc(sizeof(t_fdf));
	if (!new_link)
		return (0);
	init_new_link(new_link, p, z, color);
	new_link->next = NULL;
	new_link->prev = link;
	new_link->down = NULL;
	link->next = new_link;
	if (p[1] == 0)
		return (new_link);
	while (link && link->prev && (link->x != p[0]))
		link = link->prev;
	link->down = new_link;
	new_link->up = link;
	chain = new_link;
	return (chain);
}
