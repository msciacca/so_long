/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:20:36 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/10 00:02:16 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	find_x(t_mlx_data *mlx_data, char c)
{
	int	i;
	int	k;

	i = 0;
	while (mlx_data->map[i] && i < mlx_data->h)
	{
		k = 0;
		while (mlx_data->map[i][k] && k < mlx_data->w)
		{
			if (mlx_data->map[i][k] == c)
				return (k);
			k++;
		}
		i++;
	}
	return (0);
}

int	find_y(t_mlx_data *mlx_data, char c)
{
	int	i;
	int	k;

	i = 0;
	while (mlx_data->map[i] && i < mlx_data->h)
	{
		k = 0;
		while (mlx_data->map[i][k] && k < mlx_data->w)
		{
			if (mlx_data->map[i][k] == c)
				return (i);
			k++;
		}
		i++;
	}
	return (0);
}
