/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/06/13 07:12:24 by matteofilib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"
#include "./mlx/mlx.h"

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;

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
				console_error("Invalid map file");
			else
				ft_putstr("OK!\n");
		}
		else
			console_error("Could not read map file");
	}

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
