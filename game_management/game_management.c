/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/03 18:20:59 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
