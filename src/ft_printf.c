/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:25:11 by myoung            #+#    #+#             */
/*   Updated: 2016/12/04 03:00:57 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				len;
	union u_format	f;
	t_ftoken		ftoken;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{	
			fmt++;
			// FIND THE FLAGS
			while (*fmt == '#' 
					|| *fmt == '-'
					|| *fmt == '+'
					|| *fmt == '0'
					|| *fmt == ' ')
			{
				if (*fmt == '#')
					ftoken.alt = 1;
				if (*fmt == '-')
					ftoken.left = 1;
				if (*fmt == '+')
					ftoken.sign = 1;
				if (*fmt == ' ')
					ftoken.space = 1;
				if (*fmt == '0')
					ftoken.zero = 1;
				fmt++;
			}
			// FIND THE LEN MOD
			while (*fmt == 'l' || *fmt == 'h' || *fmt == 'j' || *fmt == 'z')
			{
				if (*fmt == 'l')
				{
					if (*fmt + 1 == 'l')
					{
						fmt++;
						ftoken.ll = 1;
					}
					else
						ftoken.l = 1;
				}
				if (*fmt == 'h')
				{
					if (*fmt + 1 == 'h')
					{
						fmt++;
						ftoken.hh = 1;
					}
					else
						ftoken.h = 1;
				}
				if (*fmt == 'j')
					ftoken.j = 1;
				if (*fmt == 'z')
					ftoken.z = 1;
				fmt++;
			}
			// FIND THE ID
			if (*fmt == 'c')
			{
				fmt++;
				if (ftoken.l)
				{
					f.wc = va_arg(ap, wchar_t);
					len += ft_putwchar(f.wc);
				}
				else
				{
					f.c = va_arg(ap, int);
					write(1, &f.c, 1);
					len++;
				}
			}
			else if (*fmt == 'C')
			{
				fmt++;
				f.wc = va_arg(ap, wchar_t);
				len += ft_putwchar(f.wc);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				fmt++;
				if (ftoken.z || ftoken.l)
				{
					f.ld = va_arg(ap, long);
					len += ft_lldlen_base(f.ld, 10);
					ft_putlong(f.ld);
				}
				else
				{
					f.d = va_arg(ap, int);
					len += ft_nlen_base(f.d, 10);
					ft_putnbr(f.d);
				}
			}
			else if (*fmt == 'D')
			{
				fmt++;
				f.ld = va_arg(ap, long);
				len += ft_lldlen_base(f.ld, 10);
				ft_putlong(f.ld);
			}
			else if (*fmt == 'o')
			{
				fmt++;
				if (ftoken.l || ftoken.z)
				{
					f.ul = va_arg(ap, unsigned long);
					len += ft_uld_len_base(f.ul, 8);
					ft_putstr(ft_uldtoa_base(f.ul, 8));
				}
				else
				{
					f.ud = va_arg(ap, unsigned int);
					len += ft_ud_len_base(f.ud, 8);
					ft_putstr(ft_udtoa_base(f.ud, 8));
				}
			}
			else if (*fmt == 'O')
			{
				fmt++;
				f.ul = va_arg(ap, unsigned long);
				len += ft_uld_len_base(f.ul, 8);
				ft_putstr(ft_uldtoa_base(f.ul, 8));
			}
			else if (*fmt == 'p')
			{	
				fmt++;
				f.ld = va_arg(ap, long);
				ft_putstr("0x");
				len += ft_lldlen_base(f.ld, 16) + 2;
				ft_putstr(ft_itoa_base(f.ld, 16));
			}
			else if (*fmt == '%')
			{	
				fmt++;
				write(1, "%", 1);
				len++;
			}
			else if (*fmt == 's')
			{
				fmt++;
				if (ftoken.l)
				{
					f.ws = va_arg(ap, wchar_t*);
					if (f.ws)
						len += ft_putwstr(f.ws);
					else
						len += ft_printf("(null)");
				}
				else
				{
					f.s = va_arg(ap, char*);
					if (f.s)
					{
						write(1, f.s, ft_strlen(f.s));
						len = len + ft_strlen(f.s);
					}
					else
						len += printf("(null)");
				}
			}
			else if (*fmt == 'S')
			{
				fmt++;
				f.ws = va_arg(ap, wchar_t*);
				if (f.ws)
					len += ft_putwstr(f.ws);
				else
					len += ft_printf("(null)");
			}
			else if (*fmt == 'u')
			{
				fmt++;
				if (ftoken.l || ftoken.z)
				{
					f.ul = va_arg(ap, unsigned long);
					len += ft_uld_len_base(f.ul, 10);
					ft_putuld(f.ul);
				}
				else
				{
					f.ud = va_arg(ap, unsigned int);
					len += ft_ud_len_base(f.ul, 10);
					ft_putud(f.ud);
				}
			}
			else if (*fmt == 'U')
			{
				fmt++;
				f.ul = va_arg(ap, unsigned long);
				len += ft_uld_len_base(f.ul, 10);
				ft_putuld(f.ul);
			}
			else if (*fmt == 'x')
			{
				fmt++;
				f.ull = va_arg(ap, unsigned long long);
				len += ft_ulld_len_base(f.ull, 16);
				ft_putstr(ft_ulldtoa_base(f.ull, 16));
			}
			else if (*fmt == 'X')
			{
				fmt++;
				f.ull = va_arg(ap, unsigned long long);
				len += ft_ulld_len_base(f.ull, 16);
				ft_putstr(ft_ulldtoa_base_alt(f.ull, 16));
			}
		}
		else
		{
			write(1, fmt, 1);
			len++;
			fmt++;
		}
	}
	return(len);
}
