/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:31:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/22 18:01:14 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_reachability(char **matrice)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (matrice[x])
	{
		while (matrice[x][y] != 'C' && matrice[x][y] != 'E' && matrice[x][y])
			y++;
		if (matrice[x][y] == 'C' || matrice[x][y] == 'E')
			return (1);
		y = 0;
		x++;	
	}
	return (0);
}

void	explore(char **matrice, int x, int y)
{

	if (x < 0 || y < 0 || !matrice[x] || !matrice[x][y])
		return;
	if (matrice[x][y] == 'E')
		matrice[x][y] = 'V';
	if (matrice[x][y] != '1' && matrice[x][y] != 'V')
	{
		matrice[x][y] = 'V';
		explore(matrice, x + 1, y);
		explore(matrice, x - 1, y);
		explore(matrice, x, y + 1);
		explore(matrice, x, y - 1);
	}
}

int	check_playable(char **matrice)
{
	int	x;
	int	y;
	char	**copy;

	x = 0;
	y = 0;
	copy = NULL;
	// FIND "P"
	while (matrice[x])
	{
		while (matrice[x][y] != 'P' && matrice[x][y])
			y++;
		if (matrice[x][y] == 'P')
			break;
		y = 0;
		x++;
	}
	// BACKTRACKING
	copy = ft_copy(matrice, copy);
	explore(copy, x, y);
	// LAST CHECK
	if (check_reachability(copy) == 1)
		return (1);
	return (0);
}
