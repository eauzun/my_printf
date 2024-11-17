#include "libftprintf.h"

void	ft_putnbr(int i)
{
	if (n == -2147483648)
	{
		ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr / (10);
		ft_putnbr % (10);
	}
	else
		ft_putchar + (48);
}


void	ft_putstr(char *s)
{
	int	i;

	if(!s)
	write(1, (NULL), sizeof(char) * 6);
	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_putchar(char c)
	write(1, &c, 1);
