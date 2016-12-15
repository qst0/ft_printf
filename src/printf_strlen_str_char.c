/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlen_str_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:00:49 by myoung            #+#    #+#             */
/*   Updated: 2016/12/14 20:02:06 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_strlen(char *str)
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
