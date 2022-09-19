/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:06:53 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/20 01:06:59 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	ft_input(int key, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	x = find_x(mlx_data, 'P');
	y = find_y(mlx_data, 'P');
	if (key == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->window);
		exit(0);
	}
	else if (key == 13)
	{
		mlx_data->map[y - 1][x] = 'P';
		mlx_data->map[y][x] = '0';
		generate_new_frame(mlx_data);
	}
	else if (key == 0)
	{
		mlx_data->map[y][x - 1] = 'P';
		mlx_data->map[y][x] = '0';
		generate_new_frame(mlx_data);
	}
	else if (key == 1)
	{
		mlx_data->map[y + 1][x] = 'P';
		mlx_data->map[y][x] = '0';
		generate_new_frame(mlx_data);
	}
	else if (key == 2)
	{
		mlx_data->map[y][x + 1] = 'P';
		mlx_data->map[y][x] = '0';
		generate_new_frame(mlx_data);
	}
	//printf("Key pressed: %d\n", key);
	return (0);
}