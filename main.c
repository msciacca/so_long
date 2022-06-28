/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/06/28 11:43:00 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"
#include "./mlx/mlx.h"

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

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
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
