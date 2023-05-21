/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:32:38 by fhongu            #+#    #+#             */
/*   Updated: 2023/05/21 17:18:34 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/** @brief Returns the next line of an opened file.
 *
 * get_next_line is the main function of the GNL 42Madrid project. It reads
 * a file via a file descriptor and then returns a string with the first
 * line it reads. In an error is encountered, it returns NULL.
 *
 * @param fd the file descriptor to read from
 * @return The first line of the file pointed by fd
 */
char	*get_next_line(int fd);
/** @brief Returns the index of the first ocurrence of a character.
 *
 * This is a modified version of the ft_strchr from libft that returns
 * an index of type size_t of the first ocurrence of the character passed
 * as parameter, instead of a pointer to the first ocurrence of that char.
 *
 * @param s the string that will be read
 * @param c the char that will be found, passed as int
 * @return The index of the first occurrence of c
 */
size_t	ft_strchr(const char *s, int c);
/** @brief Returns the length of the passed string.
 *
 * @param s the string whose length will be returned
 * @return The length of s
 */
size_t	ft_strlen(const char *s);
/** @brief Creates a new string with the concatenation of s1 + s2.
 *
 * This is a modified version of my libft's strjoin. It returns a new
 * string consisting of all the content of s1 followed by the chars_read
 * first chars of s2. The return is then null-terminated.
 * Note: in this project, chars_read is the return value of read().
 *
 * @param s1 the first string that will be copied
 * @param s2 the secondd string that will be concatenated
 * @param chars_read the number of chars from s2 that will be concatenated
 * @return A new string consisting of s1 + s2
 */
char	*ft_strnjoin(char const *s1, char const *s2, int chars_read);
/** @brief Returns a pointer to allocated, 0'ed memory of size count*size.
 *
 * Calls malloc(count * size), and if a valid pointer is returned, all
 * of the memory allocated is set to 0. If malloc returns an error, NULL
 * is returned.
 *
 * @param count the number of elements the array will have
 * @param size the size of each element in the array
 * @return An array of size count*size bytes.
 */
void	*ft_calloc(size_t count, size_t size);
/** @brief The pointed pointer is free'd and then set to NULL.
 *
 * This function takes the address to the pointer that will be free'd,
 * frees it, and then sets it to NULL, unless it is already a NULL
 * pointer, in which case the function does nothing.
 *
 * @param str the address of the pointer that will be free'd
 */
void	ft_free(char **str);

#endif
