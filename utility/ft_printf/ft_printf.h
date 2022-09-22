/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:46:32 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 18:52:50 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_base_p(unsigned long int n, char *base, int printstart);
int		ft_putnbr_base(long int n, char *base, int oCount);
char	*ft_itoa(int n);

#endif