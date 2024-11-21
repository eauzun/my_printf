/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:20:22 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/21 16:01:02 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_formatter(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long), 1));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	return (0);
}

static int	flag_check(int i, const char *str)
{
	if (str[i] == '%')
	{
		if (str[i + 1] == 'd' || str[i + 1] == 'i'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == 'c'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'u')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (flag_check(i, str))
		{
			if (str[i + 1] == '%')
				res += ft_putchar('%');
			else
				res += flag_formatter(args, str[i + 1]);
			i++;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (res);
}
