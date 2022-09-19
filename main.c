/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/19 01:37:06 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"
#include "./mlx/mlx.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			fd;
	char		**map;
	t_mlx_data	mlx_data;
	int			aiaiai;
	int			oioioi;

	if (argc < 2)
		console_error("No map file provided");
	else if (argc > 2)
		console_error("Too many arguments");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			if (validate_map(fd))
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
	map = initialize_mem(ft_hlen_map(argv[1]), ft_strlen_gmap(argv[1]));
	load_map(argv[1], map);
	aiaiai = 0;
	while (aiaiai < 6)
	{
		oioioi = 0;
		while (oioioi < 34)
		{
			printf("%c", map[aiaiai][oioioi]);
			oioioi++;
		}
		printf("\n");
		aiaiai++;
	}
	mlx_data.mlx = mlx_init();
	mlx_data.window = mlx_new_window(mlx_data.mlx,
			(ft_strlen_gmap(argv[1]) * 64),
			(ft_hlen_map(argv[1]) * 64), "so_long");
	mlx_loop(mlx_data.mlx);
}
