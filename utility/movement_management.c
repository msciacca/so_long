/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:47:28 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/08 17:59:52 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_collision(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x] == '0')
		return (1);
	else if (mlx_data->map[y][x] == 'E' && mlx_data->total_collectibles
			== mlx_data->collectibles)
		exit (0);
	else if (mlx_data->map[y][x] == 'C')
	{
		mlx_data->collectibles++;
		return (1);
	}
	else if (mlx_data->map[y][x] == 'N')
		exit (0);
	return (0);
}

void	move_player(int key, t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	x_new;
	int	y_new;

	x = find_x(mlx_data, 'P');
	y = find_y(mlx_data, 'P');
	x_new = x;
	y_new = y;
	if (key == 13)
	{
		y_new--;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_u_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_u;
	}
	else if (key == 0)
	{
		x_new--;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_l_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_l;
	}
	else if (key == 1)
	{
		y_new++;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply;
	}
	else if (key == 2)
	{
		x_new++;
		if (mlx_data->collectibles > 0)
			mlx_data->ply_img = *mlx_data->images.ply_r_bsk;
		else
			mlx_data->ply_img = *mlx_data->images.ply_r;
	}
	if (check_collision(mlx_data, x_new, y_new))
	{
		mlx_data->map[y][x] = '0';
		mlx_data->map[y_new][x_new] = 'P';
		mlx_data->movements++;
		generate_new_frame(mlx_data);
	}
}

void	move_enemy(char dir, t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	x_new;
	int	y_new;

	x = find_x(mlx_data, 'N');
	y = find_y(mlx_data, 'N');
	x_new = x;
	y_new = y;
	if (dir == 'd')
	{
		y_new++;
		mlx_data->enemy_img = *mlx_data->images.enemy;
	}
	else if (dir == 'u')
	{
		y_new--;
		mlx_data->enemy_img = *mlx_data->images.enemy_u;
	}
	else if (dir == 'r')
	{
		x_new++;
		mlx_data->enemy_img = *mlx_data->images.enemy_r;
	}
	else if (dir == 'l')
	{
		x_new--;
		mlx_data->enemy_img = *mlx_data->images.enemy_l;
	}
	if ((y_new != y || x_new != x) && (mlx_data->map[y_new][x_new] == '0' || mlx_data->map[y_new][x_new] == '1'))
	{
		mlx_data->map[y][x] = '0';
		mlx_data->map[y_new][x_new] = 'N';
		generate_new_frame(mlx_data);
	}
	else if ((y_new != y || x_new != x) && mlx_data->map[y_new][x_new] == 'P')
		exit (0);
}