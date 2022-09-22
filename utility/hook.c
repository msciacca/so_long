/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:06:53 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 23:47:20 by matteofilib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	ft_input(int key, t_mlx_data *mlx_data)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		move_player(key, mlx_data);
	return (0);
}

int	enemy_movement(t_mlx_data *mlx_data)
{
	if (mlx_data->time_future < current_timestamp())
	{
		if ((find_y(mlx_data, 'P') - find_y(mlx_data, 'N') > 0))
			move_enemy('d', mlx_data);
		else if ((find_y(mlx_data, 'P') - find_y(mlx_data, 'N') < 0))
			move_enemy('u', mlx_data);
		else if ((find_x(mlx_data, 'P') - find_x(mlx_data, 'N')) > 0)
			move_enemy('r', mlx_data);
		else if ((find_x(mlx_data, 'P') - find_x(mlx_data, 'N')) < 0)
			move_enemy('l', mlx_data);
		mlx_data->time_future = current_timestamp() + 200;
	}
	return (0);
}