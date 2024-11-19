/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:12:46 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/19 18:16:57 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int flag_formatter(va_list args, char c)
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


static int flag_check(int i, const char *str)
{
    if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'
            || str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == 'c'
            || str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
            || str[i + 1] == 'u'))
        return (1);
    return (0);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int res;
    int i;

    i = 0;
    res = 0;
    va_start(args, str);
    while (str[i])
    {
        if (flag_check(i, str))
            res += flag_formatter(args, str[++i]);
        else if (str[i] == '%')
            res += ft_putchar('%');
        else
            res += ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return (res);
}

int main()
{
    char a = 'a';
    char s[] = "helloworldimroot";
    int d = 2139877;

    ft_printf("%s\n", s);
    ft_printf("%c\n", a);
    ft_printf("%d\n", d);
    ft_printf("%p\n", s);
    ft_printf("%x\n", d);
    printf("%s\n", s);
    printf("%c\n", a);
    printf("%d\n", d);
    printf("%p\n", s);
    printf("%x\n", d);
    }