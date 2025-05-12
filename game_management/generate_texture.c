/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:29:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/12 18:18:51 by zel-ghab         ###   ########.fr       */
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
void	render(char **matrice, void *mlx, void *window, void *type, char n)
{
	int	x;
	int	y;

	y = 0;
	while (matrice[y])
	{
		x = 0;
		while (matrice[y][x])
		{
			if (matrice[y][x] == n)
				mlx_put_image_to_window(mlx, window, type, x * 32, y * 32);
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

int	generate_texture(char **matrice, void *mlx, void *window)
{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collects[4];

	ground = load_image(mlx, "assets/enderstone.xpm");
	wall = load_image(mlx, "assets/sky.xpm");
	exit = load_image(mlx, "assets/enderportal.xpm");
	player = load_image(mlx, "assets/steve.xpm");
	collects[0] = load_image(mlx, "assets/collectibles/sword.xpm");
	collects[1] = load_image(mlx, "assets/collectibles/pickaxe.xpm");
	collects[2] = load_image(mlx, "assets/collectibles/chest.xpm");
	collects[3] = load_image(mlx, "assets/collectibles/bow.xpm");
	if (!ground || !wall || !exit || !*collects || !player)
		return (1);
	render(matrice, mlx, window, ground, '0');
	render(matrice, mlx, window, wall, '1');
	render(matrice, mlx, window, exit, 'E');
	render(matrice, mlx, window, player, 'P');
	render_collects(matrice, mlx, window, collects);
	return (0);
}
