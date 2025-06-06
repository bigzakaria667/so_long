/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:28:01 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/06/01 21:42:16 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	instructions(char **argv)
{
	char	**matrice;

	matrice = parsing(argv);
	game_management(matrice);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		instructions(argv);
	else
		return (1);
	return (0);
}
