/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 21:47:05 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	destroy(game);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		return (destroy(game), exit(0), 1);
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
	void	*window;

	window = mlx_new_window(mlx, width, height, title);
	if (window == NULL)
		return (NULL);
	return (window);
}

void	game_management(char **matrice)
{
	t_game	game;

	game.collect_total = count_collect(matrice);
	game.collect_count = 0;
	game.total_moves = 0;
	game.map = fix_collect(matrice);
	game.player = find_player(matrice);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (destroy(&game), ft_error("⚠️ Failed to initialize MLX"));
	game.window = create_window(game.mlx, ft_bytes(matrice) * 32, \
			ft_line(matrice) * 32, "so_long");
	if (!game.window)
		return (destroy(&game), ft_error("⚠️ Failed to created window"));
	if (generate_texture(&game) == 1)
		return (destroy(&game), ft_error("⚠️ Failed to generate texture"));
	mlx_hook(game.window, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}
