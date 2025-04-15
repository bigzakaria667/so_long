/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:24:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/15 16:18:36 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "functions/ft_printf/ft_printf.h"
# include "functions/libft/libft.h"
# include <unistd.h>    // Pour read, write, close
# include <fcntl.h>     // Pour open et O_RDONLY
# include <stdlib.h>    // Pour exit

/*----------------  error.c  ---------------*/
void	ft_error(char *s);

/*----------------  matrice.c  ---------------*/
int	ft_line(char **matrice);
int	ft_bytes(char **matrice);
int	ft_is_element(char *line);

/*----------------  parsing.c  ---------------*/
int	check_extension(char *s);
void	instructions(char **argv);

/*----------------  check_map.c  ---------------*/
int	check_shape(char **matrice);
int	read_file(char *s, char *stockage);
int	check_map(char *s);

/*----------------  set_matrice.c  ---------------*/
char	**put_into_matrice(char *stockage, char **matrice);
int	bytes_counter(char *stockage);
int	line_counter(char *stockage);
char	**set_matrice(char *stockage);

/*----------------  check_data.c  ---------------*/
int	check_arena(char **matrice);
int	check_border(char **matrice);
int	check_data(char **matrice);

/*----------------  so_long.c  ---------------*/
int	main(int argc, char **argv);

#endif
