/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:59:37 by myoung            #+#    #+#             */
/*   Updated: 2016/11/25 15:42:29 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <stdio.h>

int			main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*ptr;
	wchar_t	test[4];

	test[0] = 0x00a2;
	test[1] = 0x23F0;
	test[2] = 0x2648;
	test[3] = 0;

	ptr = &argc;

	ft_printf("%s Mr.%C  and welcome,"
			" we made it a point %d put you in room %p\n"
			"Here is a wstr: %S\n",
		   	"Bonjour", 0x1F95E, 2, ptr, test);

	int i;
	i = 0;
	while (i < 12)
	{
		ft_putwchar(0x1F340 + i);
		ft_putchar(' ');
		ft_putwchar(0x2648 + i);
		ft_putchar(' ');
		i++;
	}

	//ft_putlong(9223372036854775807L);
	//ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putud(4294967295);
	//ft_putuld(4294967296UL);
	//ft_putlong(-9223372036854775807L);
	ft_putchar('\n');
	}
