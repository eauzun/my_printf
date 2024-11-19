/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:38 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/19 18:12:39 by emuzun           ###   ########.fr       */
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
	int	i;
	int	str;

	i = 0;
	str = 0;
	if (!s)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	while (s[i])
	{
		str += ft_putchar(s[i]);
		i++;
	}
	return (str);
}
