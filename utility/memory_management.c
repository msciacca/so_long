/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:45:18 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/19 01:18:45 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

char	**initialize_mem(int h, int w)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	map = (char **)malloc(h * sizeof(char *));
	while (i < h)
		map[i++] = (char *)malloc(w * sizeof(char));
	return (map);
}

void	load_map(char *file, char **map)
{
	char	*line;
	int		i;
	int		k;
	int		fd;

	i = 0;
	k = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (1)
	{
		if (line[i] == '\n')
		{
			line = get_next_line(fd);
			i = 0;
			k++;
		}
		else if (line[i] == '\0')
			break ;
		map[k][i] = line[i];
		i++;
	}
	free(line);
	close(fd);
}