/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:15:33 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 19:50:40 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	console_error(char *s)
{
	ft_printf("ERROR: %s\n", s);
}
