/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:17:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/19 00:16:38 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_val_components
{
	int	c;
	int	e;
	int	p;
}	t_val_components;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
}				t_mlx_data;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	console_error(char *s);
int		validate_map(int fd);
int		ft_input(int key, void *param);
int		ft_strlen_map(char *s);
int		ft_hlen_map(char *file);
int		ft_strlen_gmap(char *file);
char	**initialize_mem(int h, int w);
void	load_map(char *file, char **map);

#endif