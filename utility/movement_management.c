/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:47:28 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 19:30:06 by msciacca         ###   ########.fr       */
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
		y_new--;
	else if (key == 0)
		x_new--;
	else if (key == 1)
		y_new++;
	else if (key == 2)
		x_new++;
	if (check_collision(mlx_data, x_new, y_new))
	{
		mlx_data->map[y][x] = '0';
		mlx_data->map[y_new][x_new] = 'P';
		mlx_data->movements++;
		generate_new_frame(mlx_data);
	}
}
