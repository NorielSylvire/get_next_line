/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:32:38 by fhongu            #+#    #+#             */
/*   Updated: 2023/05/10 19:36:03 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s, int limit);
char	*ft_strnjoin(char const *s1, char const *s2, int chars_read);
void	*ft_calloc(size_t count, size_t size);

#endif
