/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:34:25 by fhongu            #+#    #+#             */
/*   Updated: 2023/05/21 18:27:12 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	ch = (unsigned char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == ch)
			return (--i);
	}
	if (ch == '\0')
		return (i);
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*retbuff;
	void	*retcopy;
	size_t	i;

	retbuff = malloc(count * size);
	if (!retbuff)
		return (NULL);
	retcopy = retbuff;
	i = -1;
	while (++i < count * size)
		*(unsigned char *) retcopy++ = 0;
	return (retbuff);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strnjoin(char const *s1, char const *s2, int chars_read)
{
	size_t	total_size;
	char	*ret;

	if (!s1 || !s2 || chars_read < 0)
		return (NULL);
	total_size = ft_strlen(s2);
	if (total_size > (size_t) chars_read)
		total_size = chars_read;
	total_size += ft_strlen(s1) + 1;
	ret = ft_calloc(total_size, sizeof (char));
	if (!ret)
		return (NULL);
	while (*s1)
		*ret++ = *s1++;
	while (*s2 && chars_read > 0)
	{
		*ret++ = *s2++;
		chars_read--;
	}
	return (ret - total_size + 1);
}

void	ft_free(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}
