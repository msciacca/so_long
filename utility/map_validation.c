/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:13:26 by msciacca          #+#    #+#             */
/*   Updated: 2022/06/13 06:56:07 by matteofilib      ###   ########.fr       */
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

static void	validate_components(int count, t_val_components *comps, char *s)
{
	int	i;

	i = 0;
	if (count == 1)
	{
		comps->c = 0;
		comps->e = 0;
		comps->p = 0;
	}
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == 'C')
			comps->c++;
		else if (s[i] == 'E')
			comps->e++;
		else if (s[i] == 'P')
			comps->p++;
		i++;
	}
}

static int	validate_borders(int count, char *line)
{
	int	i;

	if (count == 1)
	{
		i = -1;
		while (line[++i])
			if (line[i] != '1' && line[i] != '\n')
				return (1);
	}
	else if (line[ft_strlen_map(line)] == '\n')
	{
		if (line[0] != '1' || line[ft_strlen_map(line) - 1] != '1')
			return (1);
	}
	else if (count > 1 && line[ft_strlen_map(line) + 1] == '\0')
	{
		i = -1;
		while (line[++i])
			if (line[i] != '1')
				return (1);
	}
	return (0);
}

int	validate_map(int fd)
{
	char				*line;
	int					i;
	int					count;
	t_val_components	comps;

	i = 0;
	count = 0;
	line = "0";
	while (1)
	{
		if (line[i] == '\n' || count == 0)
		{
			line = get_next_line(fd);
			i = 0;
			count++;
			if (validate_line_len(count, line))
				return (1);
			if (validate_borders(count, line))
				return (1);
			validate_components(count, &comps, line);
		}
		else if (line[i] == '\0')
			break ;
		else if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
			return (1);
		i++;
	}
	if (!(comps.c != 0 && comps.e != 0 && comps.p != 0))
		return (1);
	free(line);
	return (0);
}
