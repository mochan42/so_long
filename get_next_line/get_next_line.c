/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:52:17 by mochan            #+#    #+#             */
/*   Updated: 2022/06/05 17:24:48 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*output(char *string1)
{
	long int	i;
	char		*str;

	i = 0;
	if (!*(string1 + i))
		return (NULL);
	while (string1[i] && string1[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	if (*(string1 + i) == '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*fillstring(int fd, char *string1)
{
	char		*buffer;
	long int	i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(string1, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + i) = '\0';
		string1 = ft_strjoin(string1, buffer);
	}
	free(buffer);
	return (string1);
}

char	*get_next_line(int fd)
{
	static char	*string1;
	char		*string2;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	string1 = fillstring(fd, string1);
	if (!string1)
		return (NULL);
	string2 = output(string1);
	string1 = new_string(string1);
	return (string2);
}
