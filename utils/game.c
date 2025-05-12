/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:15:02 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/05/09 22:45:41 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	find_player(char **matrice)
{
	t_pos	position;
	int	x;
	int	y;

	y = 0;
	while(matrice[y])
	{
		x = 0;
		while (matrice[y][x])
		{
			if (matrice[y][x] == 'P')
			{
				position.x = x;
				position.y = y;
				break;
			}
			x++;
		}
		y++;
	}
	return (position);
}
