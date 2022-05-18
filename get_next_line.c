/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:49:54 by eward             #+#    #+#             */
/*   Updated: 2022/01/10 12:49:58 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_rez(char *rest)
{
	char	*help;
	int		len;
	int		j;

	len = 0;
	j = -1;
	while (*(rest + len) && *(rest + len) != '\n')
		len++;
	if (!(*(rest + len)))
	{
		free(rest);
		return (NULL);
	}
	help = (char *)malloc(sizeof(char) * (ft_strlen(rest) - len + 1));
	if (help == NULL)
		return (0);
	len++;
	while (*(rest + len + j++))
		*(help + j) = *(rest + len + j);
	free(rest);
	return (help);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*rez;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_line(fd, rest);
	if (rest == NULL)
		return (NULL);
	rez = ft_crop_line(rest);
	rest = ft_new_rez(rest);
	if (rez == NULL)
		return (NULL);
	return (rez);
}
