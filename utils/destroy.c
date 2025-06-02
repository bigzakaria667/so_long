/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:14:42 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/31 21:10:22 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_matrice(char ***matrice)
{
	int	i;

	i = 0;
	while ((*matrice) && (*matrice)[i])
	{
		free((*matrice)[i]);
		(*matrice)[i] = NULL;
		i++;
	}
	free(*matrice);
	*matrice = NULL;
}

void	free_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_texture(t_game *game)
{
	int	i;

	if (game->textures.ground)
		mlx_destroy_image(game->mlx, game->textures.ground);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	i = 0;
	while (i <= 3)
	{
		if (game->textures.collects[i])
			mlx_destroy_image(game->mlx, game->textures.collects[i]);
		i++;
	}
}

void	destroy(t_game *game)
{
	if (!game)
		return;
	free_texture(game);
	free_game(game);
	free_matrice(&game->map);
}
