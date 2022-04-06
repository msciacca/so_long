/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:13:26 by msciacca          #+#    #+#             */
/*   Updated: 2022/04/06 13:10:46 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>

static int	ft_strlen_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int	validate_line_len(int count, char *line)
{
	static int	max_line_len = 0;

	if (count == 1)
		max_line_len = ft_strlen_map(line);
	else if (count > 1 && max_line_len != ft_strlen_map(line))
		return (1);
	return (0);
}

int	validate_map(int fd)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (1)
	{
		if (line[i] == '\n' || count == 0)
		{
			line = get_next_line(fd);
			i = 0;
			count++;
			if (validate_line_len(count, line))
				return (1);
		}
		else if (line[i] == '\0')
			return (0);
		else if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
			return (1);
		i++;
	}
}
