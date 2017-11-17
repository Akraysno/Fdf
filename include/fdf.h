/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:59:53 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/03 11:59:55 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <openGL/gl.h>
# include <stdio.h>

# define X_MAX 500
# define Y_MAX 500
# define COLOR 0x00CBA321
# define ADD_ZOOM 1
# define MUL_ZOOM 2
# define ANGLE 10

typedef struct		s_rbw
{
	int				color[12];
	int				index;
}					t_rbw;

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				sav_x;
	int				sav_y;
	int				sav_z;
	int				color;
	int				sav_color;
	struct s_fdf	*next;
	struct s_fdf	*prev;
	struct s_fdf	*down;
	struct s_fdf	*up;
}					t_fdf;

typedef struct		s_sav
{
	int				zoom;
	int				x_dec;
	int				y_dec;
	int				width;
	int				height;
}					t_sav;

typedef struct		s_var
{
	struct s_fdf	*chain;
	struct s_rbw	*rbw;
	struct s_sav	*sav;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	int				reload_map;
	int				pos_img_x;
	int				pos_img_y;
	long int		color;
	int				len_line;
	int				zoom;
	int				modif_zoom;
	int				modif_dec;
	int				x_dec;
	int				y_dec;
	int				x_max;
	int				width;
	int				height;
	int				add_z;
	int				y_max;
}					t_var;

t_fdf				*create_lst(char *ln, t_fdf *lst, t_fdf **sav, t_var *var);
void				calc_zoom(t_var *var);
void				put_lines(t_var *var);
void				run_put_map(t_var *var);
void				draw_case_1(t_var *var, int *x, int *y, int color);
void				draw_case_2(t_var *var, int *x, int *y, int color);
void				draw_case_3(t_var *var, int *x, int *y, int color);
void				draw_case_4(t_var *var, int *x, int *y, int color);
void				modif_color(t_var *var, int action);
int					gere_key(int key, t_var *var);
int					gere_mouse(int code, int x, int y, t_var *var);
void				choose_color(int key, t_var *var);
void				init_rbw(t_var *var);
void				mlx_window(int key, t_var *var);
int					ft_atoh(const char *nptr);
void				print_help(void);
void				run_put_map(t_var *var);
void				quit(t_var *var);
void				reset_var(t_var *var);
t_fdf				*create_first_link(t_fdf *chain, int color, int *p, int z);
t_fdf				*add_link(t_fdf *chain, int color, int *p, int z);
void				reset_z(t_var *var);
void				center_map(t_var *var);
void				reset_zoom(t_var *var);
int					*save_pos_point(t_fdf *link, int *size, t_var *var);
int					*calc_height(t_fdf *chain, int width, int *size, t_var \
																		*var);
int					calc_widht(t_fdf *chain);
int					calc_y_space(t_var *var, int *size);
int					calc_x_space(t_var *var, int x_size);
void				printf_error(t_var *var, int action);

#endif
