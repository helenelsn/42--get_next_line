/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:24:53 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 04:28:44 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, int len)
{
	int		i;
	char	*substring;

	i = 0;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && str[i])
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*strncat2(char *line, char *buffer, int len)
{
	int		l_len;
	char	*tmp;
	int		i;

	i = 0;
	l_len = ft_strlen(line);
	tmp = malloc(sizeof(char) * (l_len + len + 1));
	if (!tmp)
		return (NULL);
	while (i < l_len)
	{
		tmp[i] = line[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp[l_len + i] = buffer[i];
		i++;
	}
	tmp[l_len + i] = '\0';
	free(line);
	line = ft_substr(tmp, ft_strlen(tmp));
	free(tmp);
	return (line);
}

char	*ft_strncat(char *line, char *buffer, int len)
{
	if (!line)
		line = ft_substr(buffer, len);
	else
		line = strncat2(line, buffer, len);
	return (line);
}
