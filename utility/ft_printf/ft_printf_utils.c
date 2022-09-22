/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:18:09 by msciacca          #+#    #+#             */
/*   Updated: 2022/02/09 00:44:28 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putnbr_base_p(unsigned long int n, char *base, int printstart)
{
	unsigned long int	num;
	unsigned long int	size;
	static int			count;

	count = 0;
	size = ft_strlen(base);
	num = n;
	if (printstart)
		ft_putstr_fd("0x", 1);
	if (num >= size)
	{
		ft_putnbr_base_p(num / size, base, 0);
		ft_putchar_fd(base[num % size], 1);
		count++;
	}
	else
	{
		ft_putchar_fd(base[num % size], 1);
		count++;
	}
	return (count + 2);
}

int	ft_putnbr_base(long int n, char *base, int oCount)
{
	unsigned long int	num;
	unsigned long int	size;
	static int			count;

	count = oCount;
	size = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		num = n * (-1);
		count++;
	}
	else
		num = n;
	if (num >= size)
	{
		ft_putnbr_base(num / size, base, count);
		ft_putchar_fd(base[num % size], 1);
	}
	else
		ft_putchar_fd(base[num % size], 1);
	count++;
	return (count);
}
