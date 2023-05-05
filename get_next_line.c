/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:32:18 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/30 17:00:00 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *str);

static char	*trim_end(char *str);

static char	*read_line(int fd, char *ret);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	ret = trim_end(str);
	str = next_line(str);
	free(str);
	return (ret);
}

static char	*read_line(int fd, char *ret)
{
	int		chars_read;
	char	*str;
	char	*swap;

	str = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, str, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(str);
			free(ret); 
			return (NULL);
		}
		if (ret && str)
		{
			swap = ft_strjoin(ret, str);
			free(ret);
			ret = swap;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(str);
	return (ret);
}

static char	*trim_end(char *str)
{
	char	*ret;
	size_t	i;

	if (*str == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ret = ft_calloc(i + 2, sizeof (char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		ret[i] = '\n';
	return (ret);
}

static char	*next_line(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	ret = ft_calloc(ft_strlen(str) - i + 1, sizeof (char));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	free(str);
	return (ret);
}
