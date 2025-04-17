/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:48:50 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/17 17:05:54 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	instructions(char **argv)
{
	char	**matrice;

	matrice = parsing(argv);
	if (matrice == NULL)
		return (1);
	return (0);
}
