/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:25:11 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 21:56:19 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				len;
	t_ftoken		ftoken;

	va_start(ap, fmt);
	ft_ftoken_reset(&ftoken);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			len += ft_printf_format(&ftoken, &fmt, ap);
		else
		{
			len += write(1, fmt, 1);
			fmt++;
			while (ftoken.left && len <= ftoken.mfw)
				len += write(1, " ", 1);
		}
	}
	return (len);
}
