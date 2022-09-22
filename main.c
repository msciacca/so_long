/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 23:47:07 by matteofilib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"
#include "./mlx/mlx.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_mlx_data	mlx_data;

	if (argc < 2)
		console_error("No map file provided");
	else if (argc > 2)
		console_error("Too many arguments");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			if (validate_map(fd, &mlx_data))
			{
				console_error("Invalid map file");
				return (0);
			}
			else
				ft_putstr("OK!\n");
		}
		else
		{
			console_error("Could not read map file");
			return (0);
		}
	}
	close(fd);
	mlx_data.w = ft_strlen_gmap(argv[1]) * 64;
	mlx_data.h = ft_hlen_map(argv[1]) * 64;
	mlx_data.map = initialize_mem(mlx_data.h, mlx_data.w);
	mlx_data.movements = 0;
	mlx_data.collectibles = 0;
	mlx_data.time_future = current_timestamp() + 500;
	load_map(argv[1], mlx_data.map);
	mlx_data.mlx = mlx_init();
	load_images(&mlx_data);
	mlx_data.window = mlx_new_window(mlx_data.mlx, mlx_data.w,
			mlx_data.h, "so_long");
	generate_new_frame(&mlx_data);
	mlx_hook(mlx_data.window, 2, 1L<<0, ft_input, &mlx_data);
	mlx_loop_hook(mlx_data.mlx, enemy_movement, &mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}
