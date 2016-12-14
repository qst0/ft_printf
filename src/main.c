/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:59:37 by myoung            #+#    #+#             */
/*   Updated: 2016/12/13 04:09:16 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <stdio.h>
#include <limits.h>
#include <locale.h>

int			main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*ptr;
	wchar_t	test[4];

	test[0] = 0x00a2;
	test[1] = 0x23F0;
	test[2] = 0x28DB6;
	test[3] = 0;

	ptr = &argc;

	setlocale(LC_ALL, "");

	printf("Lib:\n");
	printf("%d\n", printf("%.4s", "42 is the answer"));
	printf("%.4s", "42 is the answer");
	printf("\n");
	ft_printf("You:\n");
	ft_printf("%d\n", ft_printf("%.4s", "42 is the answer"));
	ft_printf("%.4s", "42 is the answer");
	ft_printf("\n");

	/* ZERO PRECSISION MAKES NO PRINT WTF HOW TO FIX
	printf("Lib:\n");
	printf("%.d, %.0d", 0, 0);
	printf("\n");
	ft_printf("You:\n");
	ft_printf("%.d, %.0d", 0, 0);
	ft_printf("\n");
	*/

/*
	printf("Lib:\n");
	printf("%15.4d", -42);
	printf("\n");
	ft_printf("You:\n");
	ft_printf("%15.4d", -42);
	ft_printf("\n");
*/

/*
	printf("%#x", 42);
	printf("\n");
	ft_printf("%#x", 42);
ft_printf("\n");
*/
/*	
	printf("{%050p}", ptr);
	printf("\n");
	ft_printf("{%050p}", ptr);
	ft_printf("\n");
*/	
	/*
	printf("Lib:\n");
	printf("%03.2d", 0);
	printf("\n");
	ft_printf("You:\n");
	ft_printf("%03.2d", 0);
	ft_printf("\n");
	*/
	
	//printf("%d\n", ft_printf("{%10R}", 42));
	//	ft_printf("{%10R}");

	/*
	printf("%d\n", printf("{%-15d}", 0));
	printf("{%-15d}", 0);
	*/
	
	//printf("%d\n", ft_printf("{%-15p}", 0));
	//ft_printf("{%-15p}", 0);

	/*
	printf("%d\n", printf("{%-10d}", 42));
	printf("{%-10d}", 42);
	*/
	/*
	printf("%d\n", ft_printf("{%-10d}", 42));
	ft_printf("{%-10d}", 42);
	*/
	
	/*
	printf("%d\n", ft_printf("%jd", LLONG_MAX));
	ft_printf("%jd", LLONG_MAX);
	*/
	
	//printf("%d\n", printf("%hhu, %hhu", 0, UCHAR_MAX));
	//printf("%hhu, %hhu", 0, UCHAR_MAX);
	//printf("%d\n", ft_printf("%hhu, %hhu", 0, UCHAR_MAX));
	//ft_printf("%hhu, %hhu", 0, UCHAR_MAX);
	
	//printf("%d\n", printf("%hhd", CHAR_MAX + 42));
	//printf("%hhd", CHAR_MAX + 42);
	//printf("%d\n", ft_printf("%hhd", CHAR_MAX + 42));
	//ft_printf("%hhd", CHAR_MAX + 42);

	//printf("%d\n", printf("%x, %x", 0, UINT_MAX));
	//printf("%x, %x", 0, UINT_MAX);
	//printf("%d\n", ft_printf("%x, %x", 0, UINT_MAX));
	//ft_printf("%x, %x", 0, UINT_MAX);

/*	
	printf("%d\n", printf("%zd", LLONG_MAX));
	printf("%zd", LLONG_MAX);
*/

	/*
	printf("%d\n", 42);
	ft_printf("%d\n", 42);
	printf("%u\n", 2147777777U);
	ft_printf("%u\n", 2147777777U);
	printf("%-42u\n", 2147777777U);
	ft_printf("%-42u\n", 2147777777U);

	ft_printf("%s Mr.%C  and welcome,"
			" we made it a point %d put you in room %p\n"
			"Here is a wstr: %S\n",
		   	"Bonjour", 0x1F95E, 2, ptr, test);

	ft_putwchar(0x28DB6);
	
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
	*/
	}
