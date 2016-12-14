/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:25:11 by myoung            #+#    #+#             */
/*   Updated: 2016/12/13 17:42:33 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_ftoken_reset(t_ftoken *ftoken)
{
	ftoken->alt = 0;
	ftoken->left = 0;
	ftoken->sign = 0;
	ftoken->space = 0;
	ftoken->zero = 0;
	ftoken->h = 0;
	ftoken->hh = 0;
	ftoken->l = 0;
	ftoken->ll = 0;
	ftoken->j = 0;
	ftoken->z = 0;
	ftoken->cur_len = 0;
	ftoken->mfw = 0;
	ftoken->precision = 0;
}

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				len;
	union u_format	f;
	t_ftoken		ftoken;

	va_start(ap, fmt);
	ft_ftoken_reset(&ftoken);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_printf_mfw(&ftoken, &fmt);
			// FIND THE ID
			if (*fmt == 'c')
			{
				fmt++;
				if (ftoken.l)
				{
					f.wc = va_arg(ap, wchar_t);
					ftoken.cur_len = ft_putwchar(f.wc);
					while (ftoken.cur_len < ftoken.mfw)
					{
						ft_putchar(' ');
						ftoken.cur_len++;
					}
					len += ftoken.cur_len;
				}
				else
				{
					f.c = va_arg(ap, int);
					ftoken.cur_len = 1; 
					while (ftoken.cur_len < ftoken.mfw)
					{
						if (ftoken.zero)
							ft_putchar('0');
						else
							ft_putchar(' ');
						ftoken.cur_len++;
					}
					write(1, &f.c, 1);
					len += ftoken.cur_len;
				}
			}
			else if (*fmt == 'C')
			{
				fmt++;
				f.wc = va_arg(ap, wchar_t);
				len += ft_putwchar(f.wc);
			}
			else if (*fmt == 'd' || *fmt == 'i')
				len += ft_printf_d(&ftoken, &fmt, ap, f);
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
				if (ftoken.l || ftoken.z || ftoken.ll || ftoken.j)
				{
					f.ul = va_arg(ap, unsigned long);
					len += ft_uld_len_base(f.ul, 8);
					ft_putstr(ft_uldtoa_base(f.ul, 8));
				}
				else if (ftoken.hh)
				{
					f.uc = va_arg(ap, unsigned int);
					len += ft_nlen_base(f.uc, 8);
					ft_putstr(ft_uhhdtoa_base(f.uc, 8));
				}
				else
				{
					f.ud = va_arg(ap, unsigned int);
					len += ft_ud_len_base(f.ud, 8);
					if (ftoken.alt && f.ud != 0)
					{
						len++;
						write(1, "0", 1);
					}
					ft_putstr(ft_udtoa_base(f.ud, 8));
				}
			}
			else if (*fmt == 'O')
			{
				fmt++;
				f.ul = va_arg(ap, unsigned long);
				len += ft_uld_len_base(f.ul, 8);
				if (ftoken.alt && f.ud != 0)
				{
					len++;
					write(1, "0", 1);
				}
				ft_putstr(ft_uldtoa_base(f.ul, 8));
			}
			else if (*fmt == 'p')
				len += ft_printf_p(&ftoken, &fmt, ap, f);
			else if (*fmt == 's')
			{
				fmt++;
				if (ftoken.l)
				{
					f.ws = va_arg(ap, wchar_t*);
					ftoken.cur_len = ft_putwstr(f.ws);
				}
				else
				{
					f.s = va_arg(ap, char*);
					if (f.s)
					{
						ftoken.cur_len = ft_strlen(f.s);
						if (ftoken.mfw)
						ftoken.cur_len +=
						ft_putchar_times(ftoken.zero ? '0' : ' ',
							   	ftoken.mfw - ftoken.cur_len);
						write(1, f.s, ftoken.precision ? ftoken.precision
								: ft_strlen(f.s));
						if (ftoken.precision)
							ftoken.cur_len =
							   	ftoken.precision + ftoken.mfw - ftoken.cur_len;
					}
					else
					{
						ftoken.cur_len = ft_printf("(null)");
					}
				}
				len += ftoken.cur_len;
			}
			else if (*fmt == 'S')
			{
				fmt++;
				f.ws = va_arg(ap, wchar_t*);
				ftoken.cur_len = ft_wstr_len(f.ws);
				if (ftoken.left)
					ft_putwstr(f.ws);
				while (ftoken.cur_len < ftoken.mfw)
				{
					if (ftoken.zero)
						ft_putchar('0');
					else
						ft_putchar(' ');
					ftoken.cur_len++;
				}
				if (!ftoken.left)
					ft_putwstr(f.ws);
				len += ftoken.cur_len;
			}
			else if (*fmt == 'u')
				len += ft_printf_u(&ftoken, &fmt, ap, f);
			else if (*fmt == 'U')
				len += ft_printf_lu(&ftoken, &fmt, ap, f);
			else if (*fmt == 'x')
			{
				fmt++;
				if (ftoken.hh)
				{
					f.uc = va_arg(ap, unsigned int);
					ftoken.cur_len = ft_nlen_base(f.uc, 16);
					if (ftoken.mfw)
						ftoken.cur_len +=
						ft_putchar_times(ftoken.zero ? '0' : ' ',
							   	ftoken.mfw - ftoken.cur_len);
					if (ftoken.alt && f.uc)
						ftoken.cur_len += ft_printf("0x");
					ft_putstr(ft_uhhdtoa_base(f.uc, 16));
				}
				else
				{
					f.ull = va_arg(ap, unsigned long long);
					ftoken.cur_len = ft_ulld_len_base(f.ull, 16);
					if (ftoken.mfw)
						ftoken.cur_len +=
						ft_putchar_times(ftoken.zero ? '0' : ' ',
							   	ftoken.mfw - ftoken.cur_len);
					if (ftoken.alt && f.ull)
						ftoken.cur_len += ft_printf("0x");
					ft_putstr(ft_ulldtoa_base(f.ull, 16));
				}
				len += ftoken.cur_len;
			}
			else if (*fmt == 'X')
			{
				fmt++;
				if (ftoken.hh)
				{
					f.uc = va_arg(ap, unsigned int);
					ftoken.cur_len = ft_nlen_base(f.uc, 16);
					ft_putstr(ft_uhhdtoa_base_alt(f.uc, 16));
				} else
				{
					f.ull = va_arg(ap, unsigned long long);
					ftoken.cur_len = ft_ulld_len_base(f.ull, 16);
					while ((ftoken.cur_len < ftoken.mfw)
							|| ftoken.cur_len < ftoken.precision)
					{
						if ((ftoken.cur_len < ftoken.precision) ||
									(ftoken.zero && !ftoken.left))
							ft_putchar('0');
						else
							ft_putchar(' ');
						ftoken.cur_len++;
					}
					if (ftoken.alt && f.ull)
						ftoken.cur_len += ft_printf("0X");
					ft_putstr(ft_ulldtoa_base_alt(f.ull, 16));
				}
				len += ftoken.cur_len;
			}
			else if (*fmt == '%')
			{	
				fmt++;
				write(1, "%", 1);
				len++;
			}
			while (!ftoken.left && ftoken.mfw > len)
			{
				ft_putchar(' ');
				len++;
			}
		}
			else
		{
			write(1, fmt, 1);
			len++;
			fmt++;
			while (ftoken.left && len <= ftoken.mfw)
			{
				ft_putchar(' ');
				len++;
			}
		}
	}
	return(len);
}
