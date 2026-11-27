/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:25:36 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 22:38:33 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_data
{
	char	b[BUFFER_SIZE];
	ssize_t	s;
	ssize_t	e;
}	t_fd_data;

char	*get_next_line(int fd);
void	*ft_gnl_memchr(void *s, int c, size_t n);
void	*ft_gnl_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnl_substr(const char *buffer, ssize_t size);
char	*ft_gnl_strjoin(char const *s1, char const *s2);

#endif