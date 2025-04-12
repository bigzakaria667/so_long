/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:24:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/12 16:55:25 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "functions/ft_printf/ft_printf.h"
# include "functions/libft/libft.h"
# include "functions/get_next_line/get_next_line.h"
# include <unistd.h>    // Pour read, write, close
# include <fcntl.h>     // Pour open et O_RDONLY
# include <stdlib.h>    // Pour exit

/*----------------  error.c  ---------------*/
void	ft_error(char *s);

/*----------------  parsing.c  ---------------*/
int	check_extension(char *s);
void	instructions(char **argv);

/*----------------  check_map.c  ---------------*/
int	read_file(char **stockage);
int	check_map(char *s);

/*----------------  set_matrice.c  ---------------*/
int	put_into_matrice(char *stockage, char ***matrice);
int	bytes_counter(char *stockage);
int	line_counter(char *stockage);
int	set_matrice(char *stockage, char ***matrice);

/*----------------  so_long.c  ---------------*/
int	main(int argc, char **argv);

#endif
