/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:11 by ajari             #+#    #+#             */
/*   Updated: 2023/01/24 20:43:14 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strchr_index(const char *s, int c);
char	*ft_strjoin_get(const char *s1, const char *s2);
char	*ft_strdup_get(const char *s);

#endif
