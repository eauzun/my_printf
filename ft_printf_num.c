/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:43 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/21 15:22:27 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int a)
{
	int	res;

	res = 0;
	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (a < 0)
	{
		res += ft_putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		res += ft_putnbr(a / 10);
		res += ft_putnbr(a % 10);
	}
	else
	{
		res += ft_putchar(a + '0');
	}
	return (res);
}

int	ft_puthex(unsigned int a, char c)
{
	int	res;

	res = 0;
	if (a >= 16)
		res += ft_puthex(a / 16, c);
	if (c == 'x')
		res += write(1, &"0123456789abcdef"[a % 16], 1);
	else if (c == 'X')
		res += write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (res);
}

int	ft_putptr(unsigned long a, int sign)
{
	int	res;

	res = 0;
	if (a == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (sign == 1)
	{
		res += write(1, "0x", 2);
		sign = 0;
	}
	if (a >= 16)
		res += ft_putptr(a / 16, sign);
	res += write(1, &"0123456789abcdef"[a % 16], 1);
	return (res);
}

int	ft_putunbr(unsigned int n)
{
	int	res;

	res = 0;
	if (n >= 10)
	{
		res += ft_putunbr(n / 10);
		res += ft_putunbr(n % 10);
	}
	else
	{
		res += ft_putchar(n + '0');
	}
	return (res);
}
