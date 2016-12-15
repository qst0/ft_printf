/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_hhd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:07:35 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:08:32 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putnbr_r(int n)
{
	if (n)
		ft_putnbr_r(n / 10);
	if (n)
		ft_putchar((n % 10) * (n < 0 ? -1 : 1) + '0');
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == 0)
		ft_putchar('0');
	else
		ft_putnbr_r(n);
}

void	ft_puthhd_r(signed char n)
{
	if (n)
		ft_puthhd_r(n / 10);
	if (n)
		ft_putchar((n % 10) * (n < 0 ? -1 : 1) + '0');
}

void	ft_puthhd(signed char n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == 0)
		ft_putchar('0');
	else
		ft_puthhd_r(n);
}
