/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:59:42 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 12:06:49 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*read_file(t_fdf *chain, char *file, t_var *var)
{
	char	*line;
	int		fd;
	t_fdf	*save;
	int		ret;

	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		perror(file);
		printf_error(var, 5);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
			printf_error(var, 5);
		if (!line)
			printf_error(var, 3);
		chain = create_lst(line, chain, &save, var);
		ft_strdel(&line);
	}
	return (save);
}

void	verif_nb_point(t_var *var)
{
	t_fdf	*link;
	int		i;

	link = var->chain;
	if (!link)
		printf_error(var, 3);
	i = 0;
	while (link && link->next)
	{
		i++;
		link = link->next;
	}
	if (link)
		i++;
	if (i == 1 || link->x < 1 || link->y < 1)
		printf_error(var, 4);
}

int		verif_color_arg(char *color)
{
	int		int_color;
	int		i;

	i = 2;
	int_color = COLOR;
	if (ft_strlen(color) == 10 && color[0] == '0' && color[1] == 'x')
	{
		while (color && color[i] && ft_ishex(color[i]))
			i++;
		if (i == 10)
			int_color = ft_atoh(color);
		else
			ft_putendl_fd("./fdf : Wrong argument color", 2);
	}
	else
		ft_putendl_fd("./fdf : Wrong argument color", 2);
	return (int_color);
}

t_var	*init_var(int ac, char **av, t_var *var, t_fdf *chain)
{
	var = (t_var *)malloc(sizeof(t_var));
	var->sav = (t_sav *)malloc(sizeof(t_sav));
	var->rbw = NULL;
	var->chain = NULL;
	var->color = COLOR;
	if (ac == 3)
		var->color = verif_color_arg(av[2]);
	var->add_z = 0;
	var->width = X_MAX;
	var->sav->width = X_MAX;
	var->height = Y_MAX;
	var->sav->height = Y_MAX;
	var->len_line = -1;
	var->reload_map = 1;
	var->sav->zoom = -1;
	var->zoom = 1;
	var->modif_zoom = 1;
	var->modif_dec = 1;
	var->pos_img_x = 0;
	var->pos_img_y = 0;
	var->chain = read_file(chain, av[1], var);
	return (var);
}

int		main(int ac, char **av)
{
	t_var	*var;

	if (ac == 1)
		printf_error(NULL, 2);
	var = NULL;
	var = init_var(ac, av, var, NULL);
	verif_nb_point(var);
	init_rbw(var);
	calc_zoom(var);
	if (!var)
		return (0);
	if (var->chain)
	{
		var->mlx = mlx_init();
		var->win = mlx_new_window(var->mlx, var->width, var->height, "fdf");
		run_put_map(var);
		mlx_key_hook(var->win, gere_key, var);
		mlx_mouse_hook(var->win, gere_mouse, var);
		mlx_loop(var->mlx);
		mlx_window(0, var);
	}
	return (0);
}
