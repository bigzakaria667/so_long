/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:17 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/05 14:45:17 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (game->map[new_y][new_x] == 'E'
		&& (game->collect_total == game->collect_count))
	{
		destroy(game);
		exit(0);
	}
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
		return ;
	if (game->map[new_y][new_x] == '!' || game->map[new_y][new_x] == '@' ||
			game->map[new_y][new_x] == '#' || game->map[new_y][new_x] == '$')
		game->collect_count++;
	game->map[game->player.y][game->player.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	if (game->total_moves > 9223372036854775807)
		game->total_moves = 0;
	ft_printf("🎮 Movements : %d\n", game->total_moves++);
	free_texture(game);
	generate_texture(game);
}
