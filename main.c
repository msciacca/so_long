/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:14:05 by msciacca          #+#    #+#             */
/*   Updated: 2022/04/06 12:51:31 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utility/utils.h"

int	main(int argc, char **argv)
{
	int	fd;

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
}
