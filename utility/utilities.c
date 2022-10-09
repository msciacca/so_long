/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:43:08 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/10 00:05:38 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	current_timestamp(void)
{
	struct timeval	te;
	long long		ms;

	gettimeofday(&te, 0);
	ms = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (ms);
}

int	ft_strlen_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_gmap(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line[i] && line[i] != '\n')
		i++;
	free(line);
	close(fd);
	return (i);
}

int	ft_hlen_map(char *file)
{
	char	*line;
	int		i;
	int		count;
	int		fd;

	i = 0;
	count = 0;
	line = "0";
	fd = open(file, O_RDONLY);
	while (1)
	{
		if (line[i] == '\n' || count == 0)
		{
			line = get_next_line(fd);
			i = 0;
			count++;
		}
		else if (line[i] == '\0')
			break ;
		i++;
	}
	free(line);
	close(fd);
	return (count);
}
