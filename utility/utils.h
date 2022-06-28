/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:17:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/06/28 11:41:30 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_val_components
{
	int	c;
	int	e;
	int	p;
}	t_val_components;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	console_error(char *s);
int		validate_map(int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif