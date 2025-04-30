/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/30 18:20:25 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	generate_texture(char **matrice, void *mlx, void *window)
{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*player;

	ground = load_image(mlx, "assets/enderstone.xpm");
	wall = load_image(mlx, "assets/sky.xpm");
	exit = load_image(mlx, "assets/enderportal.xpm");
	collect = load_image(mlx, "assets/sword.xpm");
	player = load_image(mlx, "assets/steve.xpm");
	if (!ground || !wall || !exit || !collect || !player)
		return (1);
	render(matrice, mlx, window, ground, '0');
	render(matrice, mlx, window, wall, '1');
	render(matrice, mlx, window, exit, 'E');
	render(matrice, mlx, window, collect, 'C');
	render(matrice, mlx, window, player, 'P');
	return (0);
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
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (ft_error("⚠️ Failed to initialize MLX"));
	window = create_window(mlx, ft_bytes(matrice) * 32, ft_line(matrice) * 32, "so_long");
	if (!window)
		return (ft_error("⚠️ Failed to created window"));
	if (generate_texture(matrice, mlx, window) == 1)
		return (ft_error("⚠️ Failed to generate texture"));
	mlx_loop(mlx);
}
