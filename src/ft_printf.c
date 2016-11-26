/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:25:11 by myoung            #+#    #+#             */
/*   Updated: 2016/11/25 15:42:18 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_nlen_base(long value, int base)
{
	int len;

	len = 0;
	while(value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char 	*ft_itoa_base(long value, int base)
{
	char	hex[17] = "0123456789abcdef";
	char	*result;
	long	n = value;
	int 	len;

	if (value == 0)
		return ("0");
	if (value < 0)
		n *= -1;
	len = ft_nlen_base(n, base);
	if (value < 0 && base == 10)
		len++;
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	if (value < 0 && base == 10)
		result[0] = '-';
	return (result);
}

int			ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(++str) : 0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int			ft_put1byte(wchar_t wc)
{
	ft_putchar((unsigned int)wc);
	return (1);
}

int			ft_put2bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(192 | (ud >> 6 & 63));
	ft_putchar(128 | (ud & 63));
	return (2);
}

int			ft_put3bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(224 | (ud >> 12 & 63));
	ft_putchar(128 | (ud >> 6 & 63));
	ft_putchar(128 | (ud & 63));
	return (3);
}

int			ft_put4bytes(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	ft_putchar(240 | ((ud >> 18) & 63));
	ft_putchar(128 | ((ud >> 12) & 63));
	ft_putchar(128 | ((ud >> 6) & 63));
	ft_putchar(128 | (ud & 63));
	return (4);
}

int			ft_putwchar(wchar_t wc)
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

int			ft_putwstr(wchar_t *ws)
{
	int len;

	len = 0;
	while (*ws)
	{
		len += ft_putwchar(*ws);
		ws++;
	}
	return (len);
}

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

void	ft_putud_r(unsigned int u)
{
	if (u)
		ft_putud_r(u / 10);
	if (u)
		ft_putchar((u % 10) + '0');
}

void	ft_putud(unsigned int u)
{
	if (u == 0)
		ft_putchar('0');
	else
		ft_putud_r(u);
}

void		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				len;
	union u_format	f;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'c')
			{
				fmt++;
				f.c = va_arg(ap, int);
				write(1, &f.c, 1);
				len++;
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
				f.d = va_arg(ap, int);
				ft_putnbr(f.d);
			}
			else if (*fmt == 'D')
			{
				fmt++;
				f.ld = va_arg(ap, long);
				ft_putlong(f.ld);
			}
			else if (*fmt == 'o')
			{
				//fix itoa for unsigned
				fmt++;
				f.ud = va_arg(ap, unsigned int);
				ft_putstr(ft_itoa_base(f.ud, 8));

			}
			else if (*fmt == 'O')
			{
				//lo ? What does this mean?
			}
			else if (*fmt == 'p')
			{	
				fmt++;
				f.ld = va_arg(ap, long);
				ft_putstr("0x");
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
				f.s = va_arg(ap, char*);
				write(1, f.s, ft_strlen(f.s));
				len = len + ft_strlen(f.s);
			}
			else if (*fmt == 'S')
			{
				fmt++;
				f.ws = va_arg(ap, wchar_t*);
				len += ft_putwstr(f.ws);
			}
			else if (*fmt == 'u')
			{
				fmt++;
				f.ud = va_arg(ap, unsigned int);
				ft_putud(f.ud);
			}
			else if (*fmt == 'U')
			{
				fmt++;
				f.ul = va_arg(ap, unsigned long);
				ft_putud(f.ul);
			}
		}
		else
		{
			write(1, fmt, 1);
			len++;
			fmt++;
		}
	}
}
