/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:10:58 by msciacca          #+#    #+#             */
/*   Updated: 2022/01/22 16:31:22 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*string;

	string = ((char *)s);
	while (*string)
	{
		if (*string == ((char)c))
			return (string);
		string++;
	}
	if (*string == ((char)c))
		return (string);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			string[i] = s1[i];
	while (s2[j])
		string[i++] = s2[j++];
	string[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (string);
}

size_t	ft_strlen(const char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
		count++;
	return (count);
}
