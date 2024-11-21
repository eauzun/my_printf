/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:38 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/21 15:34:33 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (!s)
	{
		res += write(1, "(null)", 6);
		return (res);
	}
	while (*s)
		res += write(1, s++, 1);
	return (res);
}
