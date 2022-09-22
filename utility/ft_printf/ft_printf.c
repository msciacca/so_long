/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:49:03 by msciacca          #+#    #+#             */
/*   Updated: 2022/02/09 01:24:48 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	flags(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		i += ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
		i += ft_putnbr_base_p(va_arg(args, uintptr_t), "0123456789abcdef", 1);
	if (c == 'd')
		i += ft_putnbr_base(va_arg(args, int), "0123456789", 0);
	if (c == 'i')
		i += ft_putnbr_base(va_arg(args, int), "0123456789", 0);
	if (c == 'u')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 0);
	if (c == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 0);
	if (c == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 0);
	if (c == '%')
		i += ft_putchar_fd(c, 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			count += flags(args, s[i + 1]);
			i += 2;
			continue ;
		}
		if (s[i] == '%')
		{
			count += flags(args, s[++i]);
			i++;
			continue ;
		}
		count += ft_putchar_fd(s[i++], 1);
	}
	va_end(args);
	return (count);
}
