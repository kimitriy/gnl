/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:43 by rburton           #+#    #+#             */
/*   Updated: 2020/11/24 13:26:08 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		moveandzero(char *buf)
{
	int		i;
	char	*slshn;

	slshn = ft_strchr(buf, '\n');
	if (slshn == NULL)
		ft_bzero(buf, BUFFER_SIZE);
	else
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (slshn[i + 1])
				buf[i] = slshn[i + 1];
			else
				buf[i] = '\0';
			i++;
		}
	}
	return (1);
}

int		write2line(int fd, char *buf, char **line)
{
	int		rvlen;
	char	*tmpstr;
	char	*lineleak;

	while (1)
	{
		rvlen = (ft_strchr(buf, '\n') != NULL) ? ft_strchr(buf, '\n') - buf : ft_strlen(buf);
		tmpstr = ft_substr(buf, 0, rvlen);
		lineleak = *line;
		*line = ft_strjoin(*line, tmpstr);
		free(lineleak);
		free(tmpstr);
		if (buf[0] != '\0' && ft_strchr(buf, '\n') != NULL)
			return (moveandzero(buf));
		moveandzero(buf);
		rvlen = read(fd, buf, BUFFER_SIZE);
		if (rvlen < 0)
			return (-1);
		else if (rvlen == 0)
			return (0);
	}
	return (rvlen);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			rv;

	if (BUFFER_SIZE <= 0)
		return (-1);
	*line = malloc(1);
	**line = 0;
	rv = write2line(fd, buf, line);
	return (rv);
}
