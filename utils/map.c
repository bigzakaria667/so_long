/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:44:28 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/02 21:03:44 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collect(char **matrice)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (matrice[y])
	{
		x = 0;
		while (matrice[y][x])
		{
			if (matrice[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

void	*put_collect(char collect, void **collects)
{
	if (collect == '!')
		return (collects[0]);
	if (collect == '@')
		return (collects[1]);
	if (collect == '#')
		return (collects[2]);
	if (collect == '$')
		return (collects[3]);
	return (collects[0]);
}

void	rename_collect(char **matrice, int i, int x, int y)
{
	if (i == 0)
		matrice[y][x] = '!';
	if (i == 1)
		matrice[y][x] = '@';
	if (i == 2)
		matrice[y][x] = '#';
	if (i == 3)
		matrice[y][x] = '$';
}

char	**fix_collect(char **matrice)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (matrice[y])
	{
		x = 0;
		while (matrice[y][x])
		{
			if (matrice[y][x] == 'C')
			{
				i++;
				rename_collect(matrice, i, x, y);
				if (i == 3)
					i = -1;
			}
			x++;
		}
		y++;
	}
	return (matrice);
}
