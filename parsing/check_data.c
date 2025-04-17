/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:31:16 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/17 16:38:31 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_arena(char **matrice)
{
	int	i;
	int	c;
	int	e;
	int	p;
	int	line;

	i = 1;
	c = 0;
	e = 0;
	p = 0;
	line = ft_line(matrice);
	// CHECK SI DATA VALIDE
	while (i < line - 1)
	{
		if (ft_is_element(matrice[i]) == 0)
			return (1);
		i++;
	}
	// CHECK LES MINIMUMS ELEMENTS
	ft_count_element(matrice, &c, &e, &p);
	if (c < 1 || e != 1 || p != 1)
		return (1);
	return (0);
}

int	check_border(char **matrice)
{
	int	i;
	int	bytes;
	int	line;

	line = ft_line(matrice);
	bytes = ft_bytes(matrice);
	// CHECK 1er LINE AND LAST: ONLY 1
	i = 0;
	while (matrice[0][i])
	{
		if (matrice[0][i] != '1')
			return (1);
		if (matrice[line - 1][i] != '1')
			return (1);
		i++;
	}
	// CHECK RIGHT & LEFT BORDER : ONLY 1
	i = 0;
	while (matrice[i])
	{
		if (matrice[i][0] != '1' || matrice[i][bytes - 1] != '1')
			return (1);
		i++;
	}
	return (0);	
}

int	check_data(char **matrice)
{
	if (check_border(matrice) == 1)
		return (1);
	if (check_arena(matrice) == 1)
		return (1);
	return (0);
}
