/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:43:08 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/16 20:15:39 by matteofilib      ###   ########.fr       */
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
	t_utils_lenvals	vals;

	vals.i = 0;
	vals.count = 0;
	vals.line = "h";
	vals.fd = open(file, O_RDONLY);
	while (1)
	{
		if (vals.line[vals.i] == '\n' || vals.count == 0)
		{
			if (vals.line[0] != 'h' && vals.line)
				free(vals.line);
			vals.line = get_next_line(vals.fd);
			vals.i = 0;
			vals.count++;
		}
		else if (vals.line[vals.i] == '\0')
			break ;
		vals.i++;
	}
	free(vals.line);
	close(vals.fd);
	return (vals.count);
}
