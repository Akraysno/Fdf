/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:56:07 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 14:56:10 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		printf_error(t_var *var, int action)
{
	strerror(3);
	if (action == 1)
		ft_putendl_fd("./fdf : Different line lenght", 2);
	if (action == 2)
	{
		ft_putendl("usage: ./fdf map_file [color : 0x00rrggbb]");
		exit(0);
	}
	if (action == 3)
		ft_putendl_fd("./fdf : Missing data", 2);
	if (action == 4)
		ft_putendl_fd("./fdf : Not enough data", 2);
	if (action == 5)
		ft_putendl_fd("./fdf : No such map", 2);
	if (action == 1 || action == 3 || action == 4 || action == 5)
		quit(var);
}

static void	remove_memory_lst(t_fdf *chain)
{
	t_fdf *link;
	t_fdf *rm;

	link = chain;
	while (link)
	{
		rm = link;
		link = link->next;
		ft_memdel((void **)&rm);
	}
}

static void	create_image(t_var *var)
{
	int nb_bits;
	int len_line;
	int endian;
	int i;

	i = 0;
	nb_bits = 24;
	len_line = var->width;
	endian = 1;
	var->img = mlx_new_image(var->mlx, var->width, var->height);
	var->img_data = mlx_get_data_addr(var->img, &nb_bits, &len_line, &endian);
}

void		run_put_map(t_var *var)
{
	mlx_clear_window(var->mlx, var->win);
	if (var->zoom != 0)
	{
		create_image(var);
		put_lines(var);
		mlx_put_image_to_window(var->mlx, var->win, \
								var->img, var->pos_img_x, var->pos_img_y);
		mlx_destroy_image(var->mlx, var->img);
	}
	var->reload_map = 0;
}

void		quit(t_var *var)
{
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	if (var->sav)
		ft_memdel((void **)&var->sav);
	if (var->rbw)
		ft_memdel((void **)&var->rbw);
	remove_memory_lst(var->chain);
	if (var)
		ft_memdel((void **)&var);
	exit(1);
}
