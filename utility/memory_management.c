/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:45:18 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 19:34:09 by msciacca         ###   ########.fr       */
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
	t_map_load_vals	vals;

	vals.i = 0;
	vals.k = 0;
	vals.fd = open(file, O_RDONLY);
	vals.line = get_next_line(vals.fd);
	while (1)
	{
		if (vals.line[vals.i] == '\n')
		{
			free(vals.line);
			vals.line = get_next_line(vals.fd);
			map[vals.k][vals.i] = 0;
			vals.i = 0;
			vals.k++;
		}
		else if (vals.line[vals.i] == '\0')
			break ;
		map[vals.k][vals.i] = vals.line[vals.i];
		vals.i++;
	}
	free(vals.line);
	close(vals.fd);
}
