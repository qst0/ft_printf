/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:39:49 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 21:57:24 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_d2_edge(t_ftoken *ftoken, union u_format f)
{
	if (ftoken->sign && f.d > -1)
		ftoken->cur_len += write(1, "+", 1);
	else if (ftoken->space && f.d > -1)
		ftoken->cur_len += write(1, " ", 1);
}

void	ft_printf_d2(t_ftoken *ftoken, union u_format f)
{
	ft_printf_d2_edge(ftoken, f);
	if (!ftoken->left && ftoken->zero && f.d < 0)
	{
		ft_putchar('-');
		f.d = -f.d;
	}
	ftoken->cur_len += (ftoken->precision && (f.d < 0)) ? 1 : 0;
	while (ftoken->cur_len < ftoken->mfw)
		if (ftoken->zero && !ftoken->left && !ftoken->precision)
			ftoken->cur_len += write(1, "0", 1);
		else
			ftoken->cur_len += write(1, " ", 1);
	if (!ftoken->left)
	{
		if (f.d < 0 && ftoken->precision)
		{
			ft_putchar('-');
			f.d = -f.d;
			ftoken->precision++;
		}
		ft_putchar_times('0', ftoken->precision);
		ft_putnbr(f.d);
	}
}

void	ft_printf_d_default(t_ftoken *ft, va_list ap, union u_format f)
{
	f.d = va_arg(ap, int);
	ft->cur_len = ft_nlen_base(f.d, 10);
	ft->precision = ft->precision > ft->cur_len
		? ft->precision - ft->cur_len : 0;
	ft->cur_len += ft->precision;
	if (ft->left)
	{
		ft_putchar_times('0', ft->precision);
		ft_putnbr(f.d);
	}
	ft_printf_d2(ft, f);
}

int		ft_printf_d(t_ftoken *ft, char **fmt, va_list ap, union u_format f)
{
	(*fmt)++;
	if (ft->z || ft->l || ft->ll || ft->j)
	{
		f.ld = va_arg(ap, long);
		ft->cur_len = ft_lldlen_base(f.ld, 10);
		ft_putlong(f.ld);
	}
	else if (ft->hh)
	{
		f.sc = va_arg(ap, int);
		ft->cur_len = ft_nlen_base(f.sc, 10);
		ft_puthhd(f.sc);
	}
	else
		ft_printf_d_default(ft, ap, f);
	return (ft->cur_len);
}
