/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:34:25 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/30 22:29:45 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int		i;

	ch = (unsigned char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)((unsigned long) s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)((unsigned long) s + i));
	return (NULL);
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
	i = 0;
	while (i++ < count * size)
		*(unsigned char *) retcopy++ = 0;
	return (retbuff);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*ret;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = ft_calloc(total_size, sizeof (char));
	if (!ret || !s1 || !s2)
		return (NULL);
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	return (ret - total_size + 1);
}
