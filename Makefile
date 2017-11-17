# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 12:05:11 by gauffret          #+#    #+#              #
#    Updated: 2017/01/03 12:05:14 by gauffret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRC_PATH	=	src

OBJ_PATH	=	obj

SRC_NAME	=	fdf.c \
				lst_fdf.c \
				create_link.c \
				ft_atoh.c \
				calc_zoom.c \
				calc_dec.c \
				put_map.c \
				draw_lines.c \
				gere_keyboard.c \
				gere_mouse.c \
				gere_color.c \
				print_help.c \
				run_quit.c \
				reset_param.c


OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH	=	include

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

CPPFLAGS	=	-I$(INC_PATH)

LDFLAGS		=	-Llibft -L/usr/local/lib/

LDLIBS		=	-lft

FDFFLAGS	=	-I/usr/local/include

.PHONY : all, clean, fclean, re, norme

all :	$(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< $(FDFFLAGS)

$(NAME) : $(OBJ)
	make -C libft/
	make -C minilibx/
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ -lm -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	make -C minilibx/ clean
	rm -fv $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -fv $(NAME)

re :	fclean all

norme:
	make -C libft/ norme
	norminette $(SRC)
	norminette $(INC_PATH)/*.h
