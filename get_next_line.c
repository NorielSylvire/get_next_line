/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:32:18 by fhongu            #+#    #+#             */
/*   Updated: 2023/05/19 20:53:11 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** @brief Reads the first line of the file pointed to by fd.
 *
 * This function takes a file descriptor and attempts to read it in BUFFER_SIZE
 * increments until either an error, the EOF, or a '\n' character is
 * encountered.
 * If no errors were encountered, the line that was read is stored in the
 * static buffer ret. At this point, ret may contain extra chars after the '\n'
 * which need to be cleaned at a later stage.
 *
 * If an error is encountered, all buffers are free'd and set to NULL, and
 * NULL is returned.
 *
 * @param fd a file descriptor that points to the file to be read
 * @param ret the static buffer in which the line will be stored
 * @return The static line containing the line that was read
 */
static char	*read_line(int fd, char *ret);

/** @brief Creates a new string that contains only the chars before the '\n'.
 *
 * Creates a new string that contains only the characters from the static
 * buffer up to and including the '\n' character. If the static buffer
 * contains no '\n' the returned string doesn't contain it either.
 *
 * If the static buffer is empty or the memory allocation fails, NULL is
 * returned.
 *
 * @param str the static buffer containing the characters read
 * @return a new string containing chars of str up to and including '\n'
 */
static char	*create_return(char *str);

/** @brief Removes all chars before the '\n' from the static buffer.
 *
 * This function is executed after create_return, and it will create
 * a new string that only contains the characters after the '\n'
 * character from the static buffer, and then returns it.
 *
 * If the memory allocation fails, or the static buffer is empty,
 * NULL is returned.
 *
 * @param str the static buffer
 * @return A string with the chars after the '\n', if any, else NULL
 */
static char	*clean_static(char *str);

/** @brief Executes strnjoin on ret and str, then swaps it with ret.
 *
 * A new string is created containing the result of joining ret and
 * the chars_read first characters of str. Then the old ret is free'd
 * and ret is assigned this new string.
 *
 * ret is passed by reference because we need to modify the value of
 * the ret variable in another function, not only in the scope of this
 * function.
 *
 * @param ret the address of the string that will contain the line read
 * @param str a string containing the characters read by the read()
 * @param chars_read the number of characters read by read()
 */
static void	joinfree(char **ret, char *str, int chars_read);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_free(&str);
		return (NULL);
	}
	if (!str)
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
		if (!str)
			return (NULL);
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	ret = create_return(str);
	str = clean_static(str);
	return (ret);
}

static char	*read_line(int fd, char *ret)
{
	char	*str;
	int		chars_read;

	str = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, str, BUFFER_SIZE);
		if (!chars_read)
			break ;
		if (chars_read == -1)
		{
			ft_free(&str);
			ft_free(&ret);
			return (NULL);
		}
		if (ret && str)
			joinfree(&ret, str, chars_read);
		if (ft_strchr(str, '\n') + 1 != 0)
			break ;
	}
	ft_free(&str);
	return (ret);
}

static char	*create_return(char *str)
{
	char	*ret;
	size_t	i;

	if (*str == '\0')
		return (NULL);
	i = ft_strchr(str, '\n') + 2;
	if (i == 1)
		i = ft_strlen(str) + 1;
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

static char	*clean_static(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		ft_free(&str);
		return (NULL);
	}
	ret = ft_calloc(ft_strlen(str) - i + 1, sizeof (char));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	ft_free(&str);
	return (ret);
}

static void	joinfree(char **ret, char *str, int chars_read)
{
	char	*swap;

	swap = ft_strnjoin(*ret, str, chars_read);
	ft_free(ret);
	*ret = swap;
}
