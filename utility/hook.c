/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:06:53 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/20 18:54:48 by msciacca         ###   ########.fr       */
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
		exit(0);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		move_player(key, mlx_data);
	return (0);
}
