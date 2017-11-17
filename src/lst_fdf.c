/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:20:18 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 16:20:20 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		recup_nb_line(t_fdf *chain)
{
	t_fdf	*link;
	int		y;

	y = 0;
	if (!chain)
		return (y);
	link = chain;
	while (link && link->down)
		link = link->down;
	y = (link->y) + 1;
	return (y);
}

static int		verif_color_map(char *str, int i)
{
	char	*color;
	int		int_color;

	color = ft_strsub(str, 0, 10);
	int_color = COLOR;
	if (color && color[0] == '0' && color[1] == 'x')
		while (color && color[i])
		{
			if (!ft_ishex(color[i]) && color[i] != ' ')
				if (i == 3 || i == 2)
					color[i] = '0';
			if (!ft_ishex(color[i]) && color[i] != ' ')
				color[i] = 'f';
			if (color && color[i] && color[i + 1] && color[i] == ' ' && i == 2)
				color[i + 1] = '\0';
			if (color && color[i] && color[i] == ' ' && i == 2)
				color[i] = '0';
			if (color && color[i] && color[i] == ' ')
				color[i] = '\0';
			i++;
		}
	if (color && color[0] == '0' && color[1] == 'x')
		int_color = ft_atoh(color);
	ft_strdel(&color);
	return (int_color);
}

static int		incr_tmp_2(char *tmp, t_fdf *lst)
{
	int i;

	i = 0;
	if (tmp && tmp[i] && tmp[i] == '-' && ft_isdigit(tmp[i + 1]))
		i++;
	while (tmp && tmp[i] && ft_isdigit(tmp[i]) == 1)
		i++;
	if (tmp[i] == ',')
	{
		i++;
		lst->color = verif_color_map(tmp + i, 2);
		lst->sav_color = lst->color;
		if (tmp[i] == '0' && tmp[i + 1] == 'x')
			i += 2;
		while (tmp && tmp[i] && tmp[i] != ' ')
			i++;
	}
	return (i);
}

static int		incr_tmp(char *tmp, t_var *var)
{
	int i;

	i = 0;
	(void)var;
	while (tmp && tmp[i] && !ft_isdigit(tmp[i]))
	{
		if (tmp && tmp[i] && tmp[i] == '-' && tmp[i + 1] && \
													ft_isdigit(tmp[i + 1]))
			break ;
		i++;
	}
	return (i);
}

/*
** p[0] = x
** p[1] = y
*/

t_fdf			*create_lst(char *line, t_fdf *lst, t_fdf **sav, t_var *var)
{
	char	*tmp;
	int		p[2];

	p[0] = 0;
	p[1] = recup_nb_line(lst);
	tmp = line;
	while (*tmp)
	{
		tmp += incr_tmp(tmp, var);
		if (!lst)
		{
			if ((lst = create_first_link(lst, mlx_get_color_value(var->mlx, \
												var->color), p, ft_atoi(tmp))))
				p[0]++;
			*sav = lst;
		}
		else if (*tmp && (lst = add_link(lst, mlx_get_color_value(var->mlx, \
												var->color), p, ft_atoi(tmp))))
			p[0] += 1;
		tmp += incr_tmp_2(tmp, lst);
	}
	var->len_line = ((var->len_line == -1) ? (p[0]) : (var->len_line));
	if (var->len_line != -1 && var->len_line != p[0])
		printf_error(var, 1);
	return (lst);
}
