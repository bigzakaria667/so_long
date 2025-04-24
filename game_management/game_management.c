/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:36 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/23 16:56:29 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_window(void *mlx, int width, int height, char *title)
{
	void	*window;

	window = mlx_new_window(mlx, width, height, title);
	if (window == NULL)
		return (1);
	return (0);
}

int	game_management(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	create_window(mlx, 600, 400, "so_long");
	return (0);
}
