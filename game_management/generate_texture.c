/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:29:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 18:30:08 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_collects(char **matrice, void *mlx, void *window, void **collects)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (matrice[y])
	{
		x = 0;
		while (matrice[y][x])
		{
			if (matrice[y][x] == '!' || matrice[y][x] == '@' || matrice[y][x] == '#' || matrice[y][x] == '$')
			{
				i++;
				mlx_put_image_to_window(mlx, window, put_collect(matrice[y][x], collects), x * 32, y * 32);
				if (i == 3)
					i = -1;
			}
			x++;
		}
		y++;
	}
}
void	render(t_game *game, void *type, char n)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == n)
				mlx_put_image_to_window(game->mlx, game->window, type, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	*load_image(void *mlx, char *filename)
{
	void	*image;
	int	width;
	int	height;

	image = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (!image)
		return (NULL);
	return (image);
}

int	generate_texture(t_game *game)
{
	game->textures.ground = load_image(game->mlx, "assets/enderstone.xpm");
	game->textures.wall = load_image(game->mlx, "assets/sky.xpm");
	game->textures.exit = load_image(game->mlx, "assets/enderportal.xpm");
	game->textures.player = load_image(game->mlx, "assets/steve.xpm");
	game->textures.collects[0] = load_image(game->mlx, "assets/collectibles/sword.xpm");
	game->textures.collects[1] = load_image(game->mlx, "assets/collectibles/pickaxe.xpm");
	game->textures.collects[2] = load_image(game->mlx, "assets/collectibles/chest.xpm");
	game->textures.collects[3] = load_image(game->mlx, "assets/collectibles/bow.xpm");
	if (!game->textures.ground || !game->textures.wall || !game->textures.exit
			|| !game->textures.collects[0] || !game->textures.collects[1]
			|| !game->textures.collects[2] || !game->textures.collects[3]
			|| !game->textures.player)
		return (1);
	render(game, game->textures.ground, '0');
	render(game, game->textures.wall, '1');
	render(game, game->textures.exit, 'E');
	render(game, game->textures.player, 'P');
	render_collects(game->map, game->mlx, game->window, game->textures.collects);
	return (0);
}
