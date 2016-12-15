/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:06:24 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:08:37 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlld_r(long long lld)
{
	if (lld)
		ft_putlld_r(lld / 10);
	if (lld)
		ft_putchar((lld % 10) * (lld < 0 ? -1 : 1) + '0');
}

void	ft_putlld(long long lld)
{
	if (lld < 0)
		ft_putchar('-');
	if (lld == 0)
		ft_putchar('0');
	else
		ft_putlld_r(lld);
}

void	ft_putlong_r(long n)
{
	if (n)
		ft_putlong_r(n / 10);
	if (n)
		ft_putchar((n % 10) * (n < 0 ? -1 : 1) + '0');
}

void	ft_putlong(long n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == 0)
		ft_putchar('0');
	else
		ft_putlong_r(n);
}
