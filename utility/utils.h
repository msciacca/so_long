/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:17:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 19:34:03 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <sys/time.h>

typedef struct s_val_components
{
	int		c;
	int		e;
	int		p;
	int		n;
	int		i;
	int		count;
	char	*line;
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
	t_img_struct	*ply_r;
	t_img_struct	*ply_l;
	t_img_struct	*ply_u;
	t_img_struct	*ply_bsk;
	t_img_struct	*ply_r_bsk;
	t_img_struct	*ply_l_bsk;
	t_img_struct	*ply_u_bsk;
	t_img_struct	*coll;
	t_img_struct	*enemy;
	t_img_struct	*enemy_r;
	t_img_struct	*enemy_l;
	t_img_struct	*enemy_u;
	t_img_struct	*exit;
}	t_img_cache;

typedef struct s_mlx_data
{
	void				*mlx;
	void				*window;
	int					w;
	int					h;
	char				**map;
	int					movements;
	int					collectibles;
	int					total_collectibles;
	long long			time_future;
	int					enemy_presence;
	t_img_struct		enemy_img;
	t_img_struct		ply_img;
	t_img_cache			images;
}				t_mlx_data;

typedef struct s_map_load_vals
{
	char	*line;
	int		i;
	int		k;
	int		fd;
}				t_map_load_vals;

typedef struct s_mov_vals
{
	int	x;
	int	y;
	int	x_new;
	int	y_new;
}				t_mov_vals;

typedef struct s_util_lenvals
{
	char	*line;
	int		i;
	int		count;
	int		fd;
}				t_utils_lenvals;

void		ft_putchar(char c);
void		ft_putstr(char *s);
void		console_error(char *s);
int			validate_map(int fd, t_mlx_data *mlx_data);
int			ft_input(int key, t_mlx_data *mlx_data);
int			ft_strlen_map(char *s);
int			ft_hlen_map(char *file);
int			ft_strlen_gmap(char *file);
char		**initialize_mem(int h, int w);
void		load_map(char *file, char **map);
void		generate_new_frame(t_mlx_data *mlx_data);
void		load_images(t_mlx_data *mlx_data);
void		load_images2(t_mlx_data *mlx_data);
void		load_images3(t_mlx_data *mlx_data);
int			find_x(t_mlx_data *mlx_data, char c);
int			find_y(t_mlx_data *mlx_data, char c);
void		move_player(int key, t_mlx_data *mlx_data);
int			enemy_movement(t_mlx_data *mlx_data);
void		move_enemy(char dir, t_mlx_data *mlx_data);
long long	current_timestamp(void);
void		screen_points(t_mlx_data *mlx_data);
void		ft_close(int key, t_mlx_data *mlx_data);

#endif