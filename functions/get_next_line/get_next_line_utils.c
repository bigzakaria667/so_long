/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/10 18:21:28 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(char *stockage, char a)
{
	int	i;

	i = 0;
	if (!stockage)
		return (0);
	while (stockage[i] && stockage[i] != a)
		i++;
	if (stockage[i] == a)
		return (1);
	return (0);
}

char	*gnl_substr(char *str, int start, int end)
{
	char	*substr;
	int		i;

	if (!str)
		return (NULL);
	if (start >= gnl_strlen(str) || start >= end)
		return (free(str), NULL);
	i = 0;
	substr = malloc (sizeof(char) * (end - start + 1));
	if (!substr)
		return (NULL);
	while (start < end && str[start])
		substr[i++] = str[start++];
	substr[i] = '\0';
	return (substr);
}

int	gnl_strlen(char *source)
{
	int	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, int bytes_read)
{
	int		s1_len;
	int		i;
	int		j;
	char	*strjoin;

	if (!s1 && s2)
		return (free(s2), NULL);
	if (!s2 && s1)
		return (free(s1), NULL);
	s1_len = gnl_strlen(s1);
	strjoin = malloc (sizeof(char) * (s1_len + bytes_read + 1));
	if (!strjoin)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (j < bytes_read)
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (free(s1), free(s2), strjoin);
}

char	*gnl_strdup(char *source, int bytes_read)
{
	char	*copy;
	int		i;

	if (!source)
		return (NULL);
	copy = malloc (sizeof(char) * (bytes_read + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < bytes_read)
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return (free(source), copy);
}
