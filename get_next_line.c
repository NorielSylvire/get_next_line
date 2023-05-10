/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:32:18 by fhongu            #+#    #+#             */
/*   Updated: 2023/05/10 22:11:23 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

static char	*next_line(char *str);

static char	*trim_end(char *str);

static char	*read_line(int fd, char *ret);

static void	joinfree(char **ret, char *str, int chars_read);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!str)
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
		if (!str)
			return (NULL);
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	ret = trim_end(str);
	str = next_line(str);
	//free(str);
	return (ret);
}

static char	*read_line(int fd, char *ret)
{
	int		chars_read;
	char	*str;

	str = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, str, BUFFER_SIZE);
		if (!chars_read)
			break ;
		if (chars_read == -1)
		{
			free(str);
			free(ret);
			return (NULL);
		}
		if (ret && str)
		{
			joinfree(&ret, str, chars_read);
		}
		if (ft_strchr(str, '\n') + 1 != 0)
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
	i = ft_strchr(str, '\n') + 2;
	if (i == 1)
		i = ft_strlen(str, 2147483647) + 1;
	ret = ft_calloc(i, sizeof (char));
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
	ret = ft_calloc(ft_strlen(str, 2147483647) - i + 1, sizeof (char));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	free(str);
	return (ret);
}

static void	joinfree(char **ret, char *str, int chars_read)
{
	char	*swap;

	//printf("str: %s\nret: %s\n", str, *ret);
	swap = ft_strnjoin(*ret, str, chars_read);
	free(*ret);
	*ret = swap;
	//printf("swap: %s\n", swap);
}
/*
int main()
{
	int fd = open("only_nl.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return 0;
}*/
