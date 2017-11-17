/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:31:24 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/12 14:31:28 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	modif_location(int key, t_var *var)
{
	var->reload_map = 1;
	if (key == 75 && var->zoom / MUL_ZOOM != 0)
		var->zoom /= MUL_ZOOM;
	if (key == 67)
		var->zoom *= MUL_ZOOM;
	if (key == 69)
		var->zoom += ADD_ZOOM;
	if (key == 78 && var->zoom - ADD_ZOOM > 0)
		var->zoom -= ADD_ZOOM;
	if (key == 123)
		var->x_dec += 50;
	if (key == 124)
		var->x_dec -= 50;
	if (key == 125)
		var->y_dec -= 50;
	if (key == 126)
		var->y_dec += 50;
	if (key == 123 || key == 124 || key == 125 || key == 126)
		var->modif_dec = 0;
	var->modif_zoom = 0;
}

static void	mlx_window_2(t_var *var)
{
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	if (var->modif_zoom || var->modif_dec)
		calc_zoom(var);
	var->win = mlx_new_window(var->mlx, var->width, var->height, "fdf");
	run_put_map(var);
	mlx_key_hook(var->win, gere_key, var);
	mlx_mouse_hook(var->win, gere_mouse, var);
	mlx_loop(var->mlx);
}

void		mlx_window(int key, t_var *var)
{
	var->reload_map = 1;
	if (key == 84 && (var->height - 100 > 0))
		var->height -= 100;
	if (key == 86 && (var->width - 100 > 0))
		var->width -= 100;
	if (key == 83 && (var->height - 100 > 0) && (var->width - 100 > 0))
	{
		var->height -= 100;
		var->width -= 100;
	}
	if (key == 92)
	{
		var->height += 100;
		var->width += 100;
	}
	if (key == 87)
	{
		var->width = var->sav->width;
		var->height = var->sav->height;
	}
	if (key == 88)
		var->width += 100;
	if (key == 91)
		var->height += 100;
	mlx_window_2(var);
}

/*
** 115 (f15)= reset z
** 82 (0) = centrage
** 81 (=) = reset zoom
** 71 (clear) = reset all
*/

static void	gere_key2(int key, t_var *var)
{
	if (key == 115)
		reset_z(var);
	if (key == 82)
		center_map(var);
	if (key == 81)
		reset_zoom(var);
}

int			gere_key(int key, t_var *var)
{
	if (key == 53)
		quit(var);
	if (key == 50)
		print_help();
	if (key == 71)
		reset_var(var);
	if (key == 84 || key == 86 || key == 87 || key == 88 || key == 91 || \
		key == 92 || key == 83)
		mlx_window(key, var);
	if (key == 15 || key == 5 || key == 11 || key == 2 || key == 13 || \
		key == 46 || key == 8 || key == 16 || key == 51 || key == 48 || \
		key == 31 || key == 1 || key == 9 || key == 35 || key == 17)
		choose_color(key, var);
	if (key == 69 || key == 78 || key == 123 || key == 124 || key == 125 || \
		key == 126 || key == 75 || key == 67)
		modif_location(key, var);
	if (key == 116 && (var->reload_map = 1))
		var->add_z += 1;
	if (key == 121 && (var->reload_map = 1))
		var->add_z -= 1;
	gere_key2(key, var);
	if (var->reload_map)
		run_put_map(var);
	return (0);
}
