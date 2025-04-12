/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:46 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/10 18:18:01 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define MAXINT 2147483647

/*----------------  get_next_line_utils.c  ---------------*/
char	*gnl_substr(char *str, int start, int end);
int		gnl_strlen(char *source);
char	*gnl_strjoin(char *s1, char *s2, int bytes_read);
char	*gnl_strdup(char *source, int bytes_read);
int		gnl_strchr(char *stockage, char a);
/*----------------  get_next_line.c  ---------------*/
char	*get_next_line(int fd);

#endif
