/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:47:33 by emuzun            #+#    #+#             */
/*   Updated: 2024/11/21 15:25:02 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int a, char c);
int	ft_putptr(unsigned long a, int sign);
int	ft_printf(const char *str, ...);

#endif
