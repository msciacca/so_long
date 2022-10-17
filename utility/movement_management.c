/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:47:28 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 19:13:29 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_collision(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x] == '0')
		return (1);
	else if (mlx_data->map[y][x] == 'E' && mlx_data->total_collectibles
			== mlx_data->collectibles)
	{
		exit (0);
	}
	else if (mlx_data->map[y][x] == 'C')
	{
		mlx_data->collectibles++;
		return (1);
	}
	else if (mlx_data->map[y][x] == 'N')
	{
		exit (0);
	}
	return (0);
}

static void	move_player2(int key, t_mlx_data *mlx_data, t_mov_vals *vals)
{
	if (key == 1)
	{
		vals->y_new++;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply;
	}
	else if (key == 2)
	{
		vals->x_new++;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_r_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_r;
	}
	if (check_collision(mlx_data, vals->x_new, vals->y_new))
	{
		mlx_data->map[vals->y][vals->x] = '0';
		mlx_data->map[vals->y_new][vals->x_new] = 'P';
		mlx_data->movements++;
		generate_new_frame(mlx_data);
	}
}

static void	move_enemy2(char dir, t_mlx_data *mlx_data, t_mov_vals *vals)
{
	if (dir == 'l')
	{
		vals->x_new--;
		mlx_data->enemy_img = *mlx_data->images.enemy_l;
	}
	if ((vals->y_new != vals->y || vals->x_new != vals->x)
		&& (mlx_data->map[vals->y_new][vals->x_new] == '0'
		|| mlx_data->map[vals->y_new][vals->x_new] == '1'))
	{
		mlx_data->map[vals->y][vals->x] = '0';
		mlx_data->map[vals->y_new][vals->x_new] = 'N';
		generate_new_frame(mlx_data);
	}
	else if ((vals->y_new != vals->y || vals->x_new != vals->x)
		&& mlx_data->map[vals->y_new][vals->x_new] == 'P')
	{
		exit (0);
	}
}

void	move_player(int key, t_mlx_data *mlx_data)
{
	t_mov_vals	vals;

	vals.x = find_x(mlx_data, 'P');
	vals.y = find_y(mlx_data, 'P');
	vals.x_new = vals.x;
	vals.y_new = vals.y;
	if (key == 13)
	{
		vals.y_new--;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_u_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_u;
	}
	else if (key == 0)
	{
		vals.x_new--;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_l_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_l;
	}
	move_player2(key, mlx_data, &vals);
}

void	move_enemy(char dir, t_mlx_data *mlx_data)
{
	t_mov_vals	vals;

	vals.x = find_x(mlx_data, 'N');
	vals.y = find_y(mlx_data, 'N');
	vals.x_new = vals.x;
	vals.y_new = vals.y;
	if (dir == 'd')
	{
		vals.y_new++;
		mlx_data->enemy_img = *mlx_data->images.enemy;
	}
	else if (dir == 'u')
	{
		vals.y_new--;
		mlx_data->enemy_img = *mlx_data->images.enemy_u;
	}
	else if (dir == 'r')
	{
		vals.x_new++;
		mlx_data->enemy_img = *mlx_data->images.enemy_r;
	}
	move_enemy2(dir, mlx_data, &vals);
}
