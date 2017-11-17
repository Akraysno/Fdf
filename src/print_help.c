/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:07:19 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/25 16:07:20 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	print_help_head(void)
{
	ft_putendl("+----------------+-------------+");
	ft_putendl("|     Option     |     Key     |");
	ft_putendl("+----------------+-------------+");
}

static void	print_help_color(void)
{
	ft_putstr("|    ¤ MODIFICATION COLOR ¤    |\n");
	ft_putstr("+----------------+-------------+\n");
	ft_putstr("| Red            |      R      |\n+----------------+--------");
	ft_putstr("-----+\n| Green          |      G      |\n+----------------+");
	ft_putstr("-------------+\n| Blue           |      B      |\n+---------");
	ft_putstr("-------+-------------+\n| Magenta        |      M      |\n");
	ft_putstr("+----------------+-------------+\n");
	ft_putstr("| Cyan           |      C      |\n+----------------+--------");
	ft_putstr("-----+\n| Yellow         |      Y      |\n+----------------+");
	ft_putstr("-------------+\n| Orange         |      O      |\n+---------");
	ft_putstr("-------+-------------+\n| Grey           |      S      |\n");
	ft_putstr("+----------------+-------------+\n");
	ft_putstr("| Brown          |      T      |\n+----------------+--------");
	ft_putstr("-----+\n| Pink           |      P      |\n+----------------+");
	ft_putstr("-------------+\n| Purple         |      V      |\n+---------");
	ft_putstr("-------+-------------+\n| Black          |      D      |\n");
	ft_putstr("+----------------+-------------+\n");
	ft_putstr("| White          |      W      |\n+----------------+--------");
	ft_putstr("-----+\n| Specials       |     TAB     |\n");
	ft_putstr("+----------------+-------------+\n");
}

static void	print_help_window(void)
{
	ft_putendl("|    ¤ MODIFICATION WINDOW ¤   |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| -100 px height |      4      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| +100 px height |      6      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| -100 px width  |      2      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| -100 px width  |      8      |");
	ft_putendl("+----------------+-------------+");
}

static void	print_help_map(void)
{
	ft_putendl("|     ¤ MODIFICATION MAP ¤     |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Move up        |   Up arrow  |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Move down      |  Down arrow |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Move right     | Right arrow |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Move left      |  Left arrow |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Center         |      0      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Increase z     |   Page up   |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Decrease z     |  Page Down  |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Increase zoom  |      +      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Decrease zoom  |      -      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Divide zoom    |      /      |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Multiply zoom  |      *      |");
	ft_putendl("+----------------+-------------+");
}

void		print_help(void)
{
	print_help_head();
	print_help_color();
	print_help_window();
	print_help_map();
	ft_putendl("|          ¤ OTHERS ¤          |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Default color  |      DEL    |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Default z      |     home    |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Default window |       5     |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Ajust zoom     |       =     |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Default param  |     clear   |");
	ft_putendl("+----------------+-------------+");
	ft_putendl("| Quit           |      ESC    |");
	ft_putendl("+----------------+-------------+");
}
