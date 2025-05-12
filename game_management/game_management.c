/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/12 21:12:16 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 13)
		move_player(game, 0, -1);
	else if (keycode == 0)
		move_player(game, -1, 0);
	else if (keycode == 1)
		move_player(game, 0, 1);
	else if (keycode == 2)
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

void	game_management(char **matrice)
{
	t_game	game;

	game.collect_total = count_collect(matrice);	
	game.collect_count = 0;
	game.map = fix_collect(matrice);
	game.player = find_player(matrice);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error("⚠️ Failed to initialize MLX"));
	game.window = create_window(game.mlx, ft_bytes(matrice) * 32, ft_line(matrice) * 32, "so_long");
	if (!game.window)
		return (ft_error("⚠️ Failed to created window"));
	if (generate_texture(matrice, game.mlx, game.window) == 1)
		return (ft_error("⚠️ Failed to generate texture"));
	//mlx_key_hook(game.window, key_hook, &game);
	mlx_hook(game.window, 2, 1L << 0, key_hook,& game);
	mlx_loop(game.mlx);
}
