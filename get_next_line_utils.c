/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:50:03 by eward             #+#    #+#             */
/*   Updated: 2022/01/10 12:50:06 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rez;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	rez = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (rez == NULL)
		return (NULL);
	if (s1)
		while (*(s1 + ++i) != '\0')
			*(rez + i) = *(s1 + i);
	while (*(s2 + j) != '\0')
		*(rez + i++) = *(s2 + j++);
	*(rez + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	free (s1);
	return (rez);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_read_line(int fd, char *rest)
{
	char	*buf;
	int		read_rez;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_rez = 1;
	while (!ft_strchr(rest, '\n') && read_rez != 0)
	{
		read_rez = read(fd, buf, BUFFER_SIZE);
		if (read_rez == -1)
		{
			free(buf);
			return (NULL);
		}
		*(buf + read_rez) = '\0';
		rest = ft_strjoin(rest, buf);
	}
	free(buf);
	return (rest);
}

char	*ft_crop_line(char *rest)
{
	char	*rez;
	int		len;

	len = 0;
	if (!(*(rest)))
		return (NULL);
	while (*(rest + len) && *(rest + len) != '\n')
		len++;
	rez = (char *)malloc((sizeof(char) * (len + 2)));
	if (!rez)
		return (NULL);
	len = 0;
	while (*(rest + len) && *(rest + len) != '\n')
	{
		*(rez + len) = *(rest + len);
		len++;
	}
	if (*(rest + len) == '\n')
	{
		*(rez + len) = '\n';
		len++;
	}
	*(rez + len) = '\0';
	return (rez);
}
