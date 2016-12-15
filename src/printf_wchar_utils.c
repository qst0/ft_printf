/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:03:29 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:03:43 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_wchar_len(wchar_t wc)
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

int		ft_wstr_len(wchar_t *ws)
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

int		ft_putwstr(wchar_t *ws)
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
