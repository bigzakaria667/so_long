/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/21 16:35:23 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		return (destroy(game), exit (0), 1);
	else if (keycode == 13 || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 0 || keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 2 || keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

void	*create_window(void *mlx, int width, int height, char *title)
{
	void  *window;

	window = mlx_new_window(mlx, width, height, title);
	if (window == NULL)
		return (NULL);
	return (window);
}

int	exit_game(t_game *game)
{
	if (!game)
		return (0);
	if (game->map)
		free_matrice(game->map);
	if (game->textures.ground)
		mlx_destroy_image(game->mlx, game->textures.ground);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	for (int i = 0; i < 4; i++)
	{
		if (game->textures.collects[i])
			mlx_destroy_image(game->mlx, game->textures.collects[i]);
	}
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
#endif
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

void	game_management(char **matrice)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));  // Initialisation de toute la structure à 0
	game.textures.ground = NULL;
	game.textures.wall = NULL;
	game.textures.exit = NULL;
	game.textures.player = NULL;
	for (int i = 0; i < 4; i++)
		game.textures.collects[i] = NULL;
	game.collect_total = count_collect(matrice);	
	game.collect_count = 0;
	game.map = fix_collect(matrice);
	game.player = find_player(matrice);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (destroy(&game) ,ft_error("⚠️ Failed to initialize MLX"));
	game.window = create_window(game.mlx, ft_bytes(matrice) * 32, \
			ft_line(matrice) * 32, "so_long");
	if (!game.window)
		return (destroy(&game), ft_error("⚠️ Failed to created window"));
	if (generate_texture(&game) == 1)
		return (destroy(&game), ft_error("⚠️ Failed to generate texture"));
	mlx_hook(game.window, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}
