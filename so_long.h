/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:24:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/31 20:22:05 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "functions/ft_printf/ft_printf.h"
# include "functions/libft/libft.h"
# include "minilibx/mlx.h"
# include <unistd.h>    // Pour read, write, close
# include <fcntl.h>     // Pour open et O_RDONLY
# include <stdlib.h>    // Pour exit
# include <string.h>

typedef struct s_pos
{
	int x;
	int y;
}	t_pos;

typedef struct s_textures
{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collects[4];
}	t_textures;

typedef struct s_game 
{
	t_pos	player;
	void	*mlx;
	void	*window;
	char	**map;
	int	collect_count;
	int	collect_total;
	t_textures	textures;
}	t_game;

/*----------------  so_long.c  ---------------*/
void	instructions(char **argv);
int	main(int argc, char **argv);

/*----------------  matrice.c  ---------------*/
char	**ft_copy(char **matrice, char **copy);
int	ft_line(char **matrice);
int	ft_bytes(char **matrice);
int	ft_is_element(char *line);
void	ft_count_element(char **matrice, int *c, int *e, int *p);
void	free_copy(char **copy);

/*----------------  game.c  ---------------*/
t_pos	find_player(char **matrice);

/*----------------  destroy.c  ---------------*/
void	free_matrice(char ***matrice);
void	free_game(t_game *game);
void	free_texture(t_game *game);
void	destroy(t_game *game);

/*----------------  error.c  ---------------*/
void	ft_error(char *s);
void	ft_free(char **matrice);

/*----------------  map.c  ---------------*/
void	*put_collect(char collect, void **collects);
void	rename_collect(char **matrice, int i, int x, int y);
char	**fix_collect(char **matrice);
int	count_collect(char **matrice);

/*----------------  parsing.c  ---------------*/
int	check_extension(char *s);
char	**parsing(char **argv);

/*----------------  check_map.c  ---------------*/
int	check_shape(char **matrice);
int	count_bytes(char *s);
int	read_files(char *s, char **stockage, int bytes);
char	**check_map(char *s);

/*----------------  set_matrice.c  ---------------*/
char	**put_into_matrice(char *stockage, char **matrice);
int	bytes_counter(char *stockage);
int	line_counter(char *stockage);
char	**set_matrice(char *stockage);

/*----------------  check_data.c  ---------------*/
int	check_arena(char **matrice);
int	check_border(char **matrice);
int	check_data(char **matrice);

/*----------------  check_playable.c  ---------------*/
int	check_reachability(char **matrice);
void	explore(char **matrice, int x, int y);
int	check_playable(char **matrice);

/*----------------  generate_texture.c  ---------------*/
void	render_collects(char **matrice, void *mlx, void *window, void **collects);
void	render(char **matrice, void *mlx, void *window, void *type, char n);
void	*load_image(void *mlx, char *filename);
int	generate_texture(t_game *game);

/*----------------  move_player.c  ---------------*/
void	move_player(t_game *game, int dx, int dy);

/*----------------  game_management.c  ---------------*/
int	key_hook(int keycode, t_game *game);
void	*create_window(void *mlx, int width, int height, char *title);
void	game_management(char **matrice);

#endif
