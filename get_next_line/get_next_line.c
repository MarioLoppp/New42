/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:30:23 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/26 13:30:23 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*append;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	append = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!append)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		append[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		append[i + j] = s2[j];
		j++;
	}
	append[i + j] = '\0';
	return (append);
}

char	*extract_line(char **temp)
{
	char	*line;
	char	*new_temp;
	char	*newline_pointer;

	newline_pointer = ft_strchr(*temp, '\n');
	if (newline_pointer)
	{
		line = ft_substr(*temp, 0, newline_pointer - *temp + 1);
		if (!line)
			return (free_temp(temp), NULL);
		new_temp = ft_strdup(newline_pointer + 1);
		if (!new_temp)
			return (free(line), free_temp(temp), NULL);
		free(*temp);
		*temp = new_temp;
	}
	else
	{
		line = ft_strdup(*temp);
		free_temp(temp);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(temp), temp = NULL, NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(temp), temp = NULL, NULL);
	if (!temp)
		temp = ft_strdup("");
	bytes = 1;
	while (bytes > 0 && temp && !ft_strchr(temp, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free_temp(&temp), NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	if (!temp)
		return (free_temp(&temp), NULL);
	return (extract_line(&temp));
}
