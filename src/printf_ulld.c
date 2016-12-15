/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ulld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:09:23 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:10:06 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putulld_r(unsigned long long ulld)
{
	if (ulld)
		ft_putulld_r(ulld / 10);
	if (ulld)
		ft_putchar((ulld % 10) + '0');
}

void	ft_putulld(unsigned long long ulld)
{
	if (ulld == 0)
		ft_putchar('0');
	else
		ft_putulld_r(ulld);
}

void	ft_putuld_r(unsigned long uld)
{
	if (uld)
		ft_putuld_r(uld / 10);
	if (uld)
		ft_putchar((uld % 10) + '0');
}

void	ft_putuld(unsigned long ld)
{
	if (ld == 0)
		ft_putchar('0');
	else
		ft_putuld_r(ld);
}
