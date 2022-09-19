/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:45:18 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/20 00:34:26 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**initialize_mem(int h, int w)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	map = (char **)malloc((h + 1) * sizeof(char *));
	while (i < h)
		map[i++] = (char *)malloc((w + 1) * sizeof(char));
	map[h + 1] = 0;
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
			map[k][i] = 0;
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