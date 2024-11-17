#include "libftprintf.h"
#include <stdbool.h>

static int	formatter(va_list arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	// if (c == 'p')
	// 	return (, 1));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 'x' )
		return (ft_puthex(va_arg(arg, unsigned int), c));
    if (c == 'X')
        return (ft_putheX(va_arg(arg, unsigned int), c));
	if (c == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	return (ft_putchar('%'));
}

static bool	flag_picker(int i, const char *str)
{
	return (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == 'c'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'u'));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = -1;
	res = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (flag_picker(i, str))
			res += formatter(ap, str[++i]);
		else
		{
			if (str[i] == '%')
				return (0);
			res += ft_putchar(str[i]);
		}
	}
	va_end(ap);
	return (res);
}