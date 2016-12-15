/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:53:20 by myoung            #+#    #+#             */
/*   Updated: 2016/12/13 20:53:45 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf_mix1(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	if (*(*fmt) == 'c')
		return (ft_printf_c(ftoken, fmt, ap, f));
	else if (*(*fmt) == 'C')
	{
		(*fmt)++;
		return (ft_putwchar(va_arg(ap, wchar_t)));
	}
	else if (*(*fmt) == 'd' || *(*fmt) == 'i')
		return (ft_printf_d(ftoken, fmt, ap, f));
	else if (*(*fmt) == 'D')
	{
		(*fmt)++;
		f.ld = va_arg(ap, long);
		ft_putlong(f.ld);
		return (ft_lldlen_base(f.ld, 10));
	}
	return (0);
}

int		ft_printf_mix2(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	if (*(*fmt) == 'o')
		return (ft_printf_o(ftoken, fmt, ap, f));
	if (*(*fmt) == 'O')
		return (ft_printf_lo(ftoken, fmt, ap, f));
	if (*(*fmt) == 'p')
		return (ft_printf_p(ftoken, fmt, ap, f));
	if (*(*fmt) == 's')
		return (ft_printf_s(ftoken, fmt, ap, f));
	if (*(*fmt) == 'S')
		return (ft_printf_ls(ftoken, fmt, ap, f));
	if (*(*fmt) == 'u')
		return (ft_printf_u(ftoken, fmt, ap, f));
	if (*(*fmt) == 'U')
		return (ft_printf_lu(ftoken, fmt, ap, f));
	if (*(*fmt) == 'x')
		return (ft_printf_x(ftoken, fmt, ap, f));
	if (*(*fmt) == 'X')
		return (ft_printf_lx(ftoken, fmt, ap, f));
	return (0);
}

int		ft_printf_format(t_ftoken *ftoken, char **fmt, va_list ap)
{
	union u_format	f;
	int				len;

	len = 0;
	f.s = "get ready";
	ft_printf_mfw(ftoken, fmt);	
	if (*(*fmt) == 'c' || *(*fmt) == 'C' || *(*fmt) == 'i' ||
			*(*fmt) == 'd' || *(*fmt) == 'D')
		return (ft_printf_mix1(ftoken, fmt, ap, f));
	if (*(*fmt) == 'o' || *(*fmt) == 'O' || *(*fmt) == 'p' ||
			*(*fmt) == 's' || *(*fmt) == 'S' || *(*fmt) == 'u' ||
			*(*fmt) == 'U' || *(*fmt) == 'x' || *(*fmt) == 'X' )
		return (ft_printf_mix2(ftoken, fmt, ap, f));
	if (*(*fmt) == '%')
	{	
		(*fmt)++;
		len += write(1, "%", 1);
	}	
	return (len);
}
