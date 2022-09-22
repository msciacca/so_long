/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:25:37 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 19:07:45 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static void	*mem_init(long nb, char *s, int i)
{
	if (nb == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		s[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	nb;

	i = num_len(n);
	nb = n;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	s[i--] = '\0';
	return (mem_init(nb, s, i));
}
