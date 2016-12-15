/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_toa_base_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:56:57 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 22:24:20 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_ulldtoa_base(unsigned long long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;
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

char		*ft_uldtoa_base(unsigned long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;
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

char		*ft_lldtoa_base(long long value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	long long			n;
	int					len;

	n = value;
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

char		*ft_uhhdtoa_base(unsigned char value, int base)
{
	static char			*hex = "0123456789abcdef";
	char				*result;
	long long			n;
	int					len;

	n = value;
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

char		*ft_ulldtoa_base_alt(unsigned long long value, int base)
{
	static char			*hex = "0123456789ABCDEF";
	char				*result;
	unsigned long long	n;
	int					len;

	n = value;
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
