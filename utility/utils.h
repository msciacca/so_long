/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:17:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/19 23:39:05 by msciacca         ###   ########.fr       */
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

typedef struct s_img_struct
{
	void	*addr;
	int		w;
	int		h;
}	t_img_struct;

typedef struct s_img_cache
{
	t_img_struct	*bck;
	t_img_struct	*wall;
	t_img_struct	*ply;
	t_img_struct	*coll;
	t_img_struct	*enemy;
	t_img_struct	*exit;
}	t_img_cache;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
	int		w;
	int		h;
	char	**map;
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
void	generate_new_frame(t_mlx_data mlx_data, t_img_cache images);
void	load_images(void *mlx, t_img_cache *images);

#endif