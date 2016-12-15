/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:02:48 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:03:05 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_put1byte(wchar_t wc)
{
	ft_putchar((unsigned int)wc);
	return (1);
}

int		ft_put2bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(192 | (ud >> 6 & 63));
	ft_putchar(128 | (ud & 63));
	return (2);
}

int		ft_put3bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(224 | (ud >> 12 & 63));
	ft_putchar(128 | (ud >> 6 & 63));
	ft_putchar(128 | (ud & 63));
	return (3);
}

int		ft_put4bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(240 | ((ud >> 18) & 63));
	ft_putchar(128 | ((ud >> 12) & 63));
	ft_putchar(128 | ((ud >> 6) & 63));
	ft_putchar(128 | (ud & 63));
	return (4);
}

int		ft_putwchar(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	if (ud <= 127)
		return (ft_put1byte(wc));
	else if (ud <= 2047)
		return (ft_put2bytes(wc));
	else if (ud <= 65535)
		return (ft_put3bytes(wc));
	else
		return (ft_put4bytes(wc));
}
