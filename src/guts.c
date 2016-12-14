/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 08:13:38 by myoung            #+#    #+#             */
/*   Updated: 2016/12/13 17:40:57 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_flags(t_ftoken *ftoken, char **fmt)
{
	while (*(*fmt) == '#' || *(*fmt) == '-' || *(*fmt) == '+'
			|| *(*fmt) == '0' || *(*fmt) == ' ')
	{
		if (*(*fmt) == '#')
			ftoken->alt = 1;
		else if (*(*fmt) == '-')
			ftoken->left = 1;
		else if (*(*fmt) == '+')
			ftoken->sign = 1;
		else if (*(*fmt) == ' ')
			ftoken->space = 1;
		else if (*(*fmt) == '0')
			ftoken->zero = 1;
		(*fmt)++;
	}
}

void	ft_printf_lenmod(t_ftoken *ftoken, char **fmt)
{
	while (*(*fmt) == 'l' || *(*fmt) == 'h' || *(*fmt) == 'j' || *(*fmt) == 'z')
	{
		if (*(*fmt) == 'l' && *((*fmt) + 1) == 'l')
		{
			ftoken->ll = 1;
			(*fmt)++;
		}
		else if (*(*fmt) == 'l')
			ftoken->l = 1;
		if (*(*fmt) == 'h' && *((*fmt) + 1) == 'h')
		{
			(*fmt)++;
			ftoken->hh = 1;
		}
		else if (*(*fmt) == 'h')
			ftoken->h = 1;
		if (*(*fmt) == 'j')
			ftoken->j = 1;
		if (*(*fmt) == 'z')
			ftoken->z = 1;
		(*fmt)++;
	}
}

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v' ||
			str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	sign = (str[0] == '-' ? -1 : 1);
	str = (str[0] == '-' || str[0] == '+') ? str + 1 : str;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	if (i > 19 || result >= 9223372036854775808ULL)
		return (sign == 1 ? -1 : 0);
	return (result * sign);
}

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

char 	*ft_uldtoa_base_alt(unsigned long value, int base)
{
	char		hex[17] = "0123456789ABCDEF";
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

char 	*ft_uhhdtoa_base_alt(unsigned char value, int base)
{
	char		hex[17] = "0123456789ABCDEF";
	char		*result;
	long long	n = value;
	int			len;

	if (value == 0)
		return ("0");
	len = ft_nlen_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

char 	*ft_uhhdtoa_base(unsigned char value, int base)
{
	char		hex[17] = "0123456789abcdef";
	char		*result;
	long long	n = value;
	int			len;

	if (value == 0)
		return ("0");
	len = ft_nlen_base(n, base);
	result = (char*)malloc(len + 1);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
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

char 	*ft_udtoa_base_alt(long value, int base)
{
	char	hex[17] = "0123456789ABCDEF";
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

int		ft_putchar_times(int c, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		write(1, &c, 1);
		i++;
	}
	return (times);
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

int			ft_wchar_len(wchar_t wc)
{
	unsigned int ud;

	ud = (unsigned int)wc;
	if (ud <= 127)
		return (1);
	else if (ud <= 2047)
		return (2);
	else if (ud <= 65535)
		return (3);
	else
		return (4);
}

int			ft_wstr_len(wchar_t *ws)
{
	int len;

	len = 0;
	if (!ws)
		return (ft_strlen("(null)"));
	while (*ws)
	{
		len += ft_wchar_len(*ws);
		ws++;
	}
	return (len);
}

int			ft_putwstr(wchar_t *ws)
{
	int len;
	if(!ws)
		return (ft_printf("(null)"));
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

void	ft_puthhd_r(signed char n)
{
	if (n)
		ft_puthhd_r(n / 10);
	if (n)
		ft_putchar((n % 10) * (n < 0 ? -1 : 1) + '0');
}

void	ft_puthhd(signed char n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == 0)
		ft_putchar('0');
	else
		ft_puthhd_r(n);
}

void	ft_putuhhd_r(unsigned char n)
{
	if (n)
		ft_putuhhd_r(n / 10);
	if (n)
		ft_putchar((n % 10) + '0');
}

void	ft_putuhhd(unsigned char n)
{
	if (n == 0)
		ft_putchar('0');
	else
		ft_putuhhd_r(n);
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

int		ft_printf_u(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	(*fmt)++;
	if (ftoken->l || ftoken->z || ftoken->ll || ftoken->j)
	{
		f.ul = va_arg(ap, unsigned long);
		ftoken->cur_len = ft_uld_len_base(f.ul, 10);
		ft_putuld(f.ul);
	}
	else if (ftoken->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_ud_len_base(f.uc, 10);
		ft_putuhhd(f.uc);
	}
	else
	{
		f.ud = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_ud_len_base(f.ul, 10);
		ft_putud(f.ud);
	}
	return (ftoken->cur_len);
}

void		ft_printf_mfw(t_ftoken *ftoken, char **fmt)
{
	(*fmt)++;
	ft_printf_flags(ftoken, fmt);
	if (*(*fmt) >= '1' && *(*fmt) <= '9')
	{
		ftoken->mfw = ft_atoi(*fmt);
		*fmt += ft_nlen_base(ftoken->mfw, 10);
	}
	if (*(*fmt) == '.')
	{
		(*fmt)++;
		if (*(*fmt) >= '1' && *(*fmt) <= '9')
		{
			ftoken->precision = ft_atoi(*fmt);
			*fmt += ft_nlen_base(ftoken->precision, 10);
		}
		else if (*(*fmt) == '0')
			(*fmt)++;
	}
	ft_printf_lenmod(ftoken, fmt);
}	

/*
int		ft_guts(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	if (*(*fmt) == '%')
	{	
		(*fmt)++;
		ft_printf_flags(ftoken, fmt);
		if (*(*fmt) >= '1' && *(*fmt) <= '9')
		{
			ftoken->mfw = ft_atoi(*fmt);
			*fmt += ft_nlen_base(ftoken->mfw, 10);
		}
		if (*(*fmt) == '.')
		{
			(*fmt)++;
			if (*(*fmt) >= '1' && *(*fmt) <= '9')
			{
				ftoken->precision = ft_atoi(*fmt);
				*fmt += ft_nlen_base(ftoken->precision, 10);
			}
			else if (*(*fmt) == '0')
				(*fmt)++;
		}
		ft_printf_lenmod(ftoken, fmt);
		if (*(*fmt) == 'c')
		{
			(*fmt)++;
			if (ftoken->l)
			{
				f.wc = va_arg(ap, wchar_t);
				ftoken->cur_len = ft_putwchar(f.wc);
				while (ftoken->cur_len < ftoken->mfw)
				{
					ft_putchar(' ');
					ftoken->cur_len++;
				}
				len += ftoken->cur_len;
			}
			else
			{
				f.c = va_arg(ap, int);
				ftoken->cur_len = 1; 
				while (ftoken->cur_len < ftoken->mfw)
				{
					if (ftoken->zero)
						ft_putchar('0');
					else
						ft_putchar(' ');
					ftoken->cur_len++;
				}
				write(1, &f.c, 1);
				len += ftoken->cur_len;
			}
		}
		else if (*(*fmt) == 'C')
		{
			(*fmt)++;
			f.wc = va_arg(ap, wchar_t);
			len += ft_putwchar(f.wc);
		}
		else if (*(*fmt) == 'd' || *(*fmt) == 'i')
			len += ft_printf_d(ftoken, fmt, ap, f);
		else if (*(*fmt) == 'D')
		{
			(*fmt)++;
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
*/


int		ft_printf_lu(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	(*fmt)++;
	f.ul = va_arg(ap, unsigned long);
	ftoken->cur_len = ft_uld_len_base(f.ul, 10);
	ft_putuld(f.ul);
	return (ftoken->cur_len);
}

int		ft_printf_p(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	(*fmt)++;
	f.ld = va_arg(ap, long);
	ftoken->cur_len = ft_lldlen_base(f.ld, 16) + 2;
	if (ftoken->zero)
		ft_putstr("0x");
	if (ftoken->left && !ftoken->zero)
		ft_printf("0x%s",ft_itoa_base(f.ld, 16));
	while (ftoken->cur_len < ftoken->mfw)
	{
		if(ftoken->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ftoken->cur_len++;
	}
	if (ftoken->zero)
		ft_putstr(ft_itoa_base(f.ld, 16));
	if (!ftoken->left && !ftoken->zero)
		ft_printf("0x%s",ft_itoa_base(f.ld, 16));
	return (ftoken->cur_len);
}

int		ft_printf_d(t_ftoken *ftoken, char **fmt, va_list ap, union u_format f)
{
	(*fmt)++;
	if (ftoken->z || ftoken->l || ftoken->ll || ftoken->j)
	{
		f.ld = va_arg(ap, long);
		ftoken->cur_len = ft_lldlen_base(f.ld, 10);
		ft_putlong(f.ld);
	}
	else if (ftoken->hh)
	{
		f.sc = va_arg(ap, int);
		ftoken->cur_len = ft_nlen_base(f.sc, 10);
		ft_puthhd(f.sc);
	}
	else
	{
		f.d = va_arg(ap, int);
		ftoken->cur_len = ft_nlen_base(f.d, 10);
		ftoken->precision = ftoken->precision > ftoken->cur_len ?
			ftoken->precision - ftoken->cur_len : 0;
		ftoken->cur_len += ftoken->precision;
		if (ftoken->left)
		{
			ft_putchar_times('0', ftoken->precision);
			ft_putnbr(f.d);
		}
		if (ftoken->sign && f.d > -1)
			ftoken->cur_len += write(1, "+", 1);
		else if (ftoken->space && f.d > -1)
			ftoken->cur_len += write(1, " ", 1);	
		if (!ftoken->left && ftoken->zero && f.d < 0)
		{
			ft_putchar('-');
			f.d = -f.d;
		}
		ftoken->cur_len = (ftoken->precision && (f.d < 0)) ?
		   	ftoken->cur_len + 1 : ftoken->cur_len;
		while (ftoken->cur_len < ftoken->mfw)
		{
			if (ftoken->zero && !ftoken->left && !ftoken->precision)
				ftoken->cur_len += write(1, "0", 1);
			else
				ftoken->cur_len += write(1, " ", 1);
		}
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
	return (ftoken->cur_len);
}
