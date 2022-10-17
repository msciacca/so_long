/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 19:35:40 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"
#include "./mlx/mlx.h"
#include <stdio.h>

static void	initialization(char **argv, t_mlx_data *mlx_data)
{
	mlx_data->w = ft_strlen_gmap(argv[1]) * 64;
	mlx_data->h = ft_hlen_map(argv[1]) * 64;
	mlx_data->map = initialize_mem(mlx_data->h / 64, mlx_data->w / 64);
	mlx_data->movements = 0;
	mlx_data->collectibles = 0;
	mlx_data->time_future = current_timestamp() + 5000;
	load_map(argv[1], mlx_data->map);
	mlx_data->mlx = mlx_init();
	load_images(mlx_data);
	mlx_data->window = mlx_new_window(mlx_data->mlx, mlx_data->w,
			mlx_data->h, "so_long");
	generate_new_frame(mlx_data);
	mlx_hook(mlx_data->window, 2, 1L << 0, ft_input, mlx_data);
	mlx_hook(mlx_data->window, 17, 0, ft_close, mlx_data);
	mlx_loop_hook(mlx_data->mlx, enemy_movement, mlx_data);
	mlx_loop(mlx_data->mlx);
}

static int	initiate_validation(int *fd, char **argv, t_mlx_data *mlx_data)
{
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		if (validate_map(fd, mlx_data))
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

int	main(int argc, char **argv)
{
	int			fd;
	t_mlx_data	mlx_data;

	if (argc < 2)
		console_error("No map file provided");
	else if (argc > 2)
		console_error("Too many arguments");
	else
		initiate_validation(&fd, argv, &mlx_data);
	initialization(argv, &mlx_data);
	close(fd);
	return (0);
}
