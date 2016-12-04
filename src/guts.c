/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 08:13:38 by myoung            #+#    #+#             */
/*   Updated: 2016/12/04 02:54:47 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_lldlen_base(long long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
	while(value)
	{
		value /= base;
		len++;
	}
	return (len);
}

//Fix this? not sure it works with the other bases
//// mins right? what about ulld octal or someshit?
//THESE NOW?
//

char 	*ft_ulldtoa_base_alt(unsigned long long value, int base)
{
	char		hex[17] = "0123456789ABCDEF";
	char		*result;
	unsigned long long	n = value;
	int			len;

	if (value == 0)
		return ("0");
	len = ft_ulld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char 	*ft_ulldtoa_base(unsigned long long value, int base)
{
	char		hex[17] = "0123456789abcdef";
	char		*result;
	unsigned long long	n = value;
	int			len;

	if (value == 0)
		return ("0");
	len = ft_ulld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char 	*ft_uldtoa_base(unsigned long value, int base)
{
	char		hex[17] = "0123456789abcdef";
	char		*result;
	unsigned long long	n = value;
	int			len;

	if (value == 0)
		return ("0");
	len = ft_uld_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char 	*ft_lldtoa_base_alt(long long value, int base)
{
	char		hex[17] = "0123456789ABCDEF";
	char		*result;
	long long	n = value;
	int			len;

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

char 	*ft_lldtoa_base(long long value, int base)
{
	char		hex[17] = "0123456789abcdef";
	char		*result;
	long long	n = value;
	int			len;

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

int		ft_ulld_len_base(unsigned long long value, int base)
{
	int len;

	len = 0;
	if(!value)
		return (1);
	while(value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_uld_len_base(unsigned long value, int base)
{
	int len;

	len = 0;
	if(!value)
		return (1);
	while(value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_ud_len_base(unsigned int value, int base)
{
	int len;

	len = 0;
	if(!value)
		return (1);
	while(value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char 	*ft_udtoa_base(long value, int base)
{
	char	hex[17] = "0123456789abcdef";
	char	*result;
	long	n = value;
	int 	len;

	if (value == 0)
		return ("0");
	len = ft_ud_len_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

int		ft_nlen_base(long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
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
