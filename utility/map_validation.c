/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:13:26 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/17 21:00:07 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	validate_line_len(t_val_components *c)
{
	static int	max_line_len = 0;

	if (c->count == 1)
		max_line_len = ft_strlen_map(c->line);
	else if (c->count > 1 && max_line_len != ft_strlen_map(c->line))
		return (1);
	return (0);
}

static void	validate_components(t_val_components *c)
{
	int	i;

	i = 0;
	if (c->count == 1)
	{
		c->c = 0;
		c->e = 0;
		c->p = 0;
		c->n = 0;
	}
	while (c->line[i] && c->line[i] != '\n')
	{
		if (c->line[i] == 'C')
			c->c++;
		else if (c->line[i] == 'E')
			c->e++;
		else if (c->line[i] == 'P')
			c->p++;
		else if (c->line[i] == 'N')
			c->n++;
		i++;
	}
}

static int	validate_borders(t_val_components *c)
{
	int	i;

	if (c->count == 1)
	{
		i = -1;
		while (c->line[++i])
			if (c->line[i] != '1' && c->line[i] != '\n')
				return (1);
	}
	else if (c->line[ft_strlen_map(c->line)] == '\n')
	{
		if (c->line[0] != '1' || c->line[ft_strlen_map(c->line) - 1] != '1')
			return (1);
	}
	else if (c->count > 1 && c->line[ft_strlen_map(c->line) + 1] == '\0')
	{
		i = -1;
		while (c->line[++i])
			if (c->line[i] != '1')
				return (1);
	}
	return (0);
}

static int	validate_map2(int fd, t_val_components *c)
{
	while (1)
	{
		c->i++;
		if (c->line[c->i] == '\n' || c->count == 0)
		{
			if (c->line[0] != 'h' && c->line)
				free(c->line);
			c->line = get_next_line(fd);
			c->i = -1;
			c->count++;
			if (validate_line_len(c) || validate_borders(c))
			{
				free(c->line);
				return (1);
			}
			validate_components(c);
		}
		else if (c->line[c->i] == '\0')
			break ;
		if (c->line[c->i] == 'N')
			continue ;
	}
	free(c->line);
	return (0);
}

int	validate_map(int fd, t_mlx_data *mlx_data)
{
	t_val_components	c;

	c.i = -1;
	c.count = 0;
	c.line = "h";
	if (validate_map2(fd, &c))
		return (1);
	if (c.c <= 0 || c.p != 1 || c.e != 1 || c.n > 1)
		return (1);
	if (c.n == 1)
		mlx_data->enemy_presence = 1;
	else
		mlx_data->enemy_presence = 0;
	mlx_data->total_collectibles = c.c;
	return (0);
}
