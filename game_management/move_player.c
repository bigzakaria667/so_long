/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:17 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/12 21:00:07 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	// EXIT
	if (game->map[new_y][new_x] == 'E' && (game->collect_total == game->collect_count))
		exit(0);
	// WALL
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
		return;
	// COLLECT
	if (game->map[new_y][new_x] == '!' || game->map[new_y][new_x] == '@' ||
			game->map[new_y][new_x] == '#' || game->map[new_y][new_x] == '$')
		game->collect_count++;
	// MAJ DE LA MAP
	game->map[game->player.y][game->player.x] = '0';
	game->map[new_y][new_x] = 'P';
	// MAJ DU PLAYER
	game->player.x = new_x;
	game->player.y = new_y;
	// REGEN LA MAP
	generate_texture(game->map, game->mlx, game->window);
}
