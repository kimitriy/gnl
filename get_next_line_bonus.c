/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:43 by rburton           #+#    #+#             */
/*   Updated: 2020/11/23 15:55:05 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	**buf;
	int			rv;
	int			i;

	rv = 0;
	if (BUFFER_SIZE <= 0)
		return (-1);
	*line = malloc(1);
	**line = 0;
	if (!buf)
		if (!(buf = (char**)malloc(255 * sizeof(char*))))
			return (-1);
	i = -1;
	while (++i < 255)
		if (i == fd && buf[fd])
			break ;
		else if (i == fd && !buf[fd])
		{
			if (!(buf[fd] = (char*)malloc((BUFFER_SIZE * 1) * sizeof(char))))
				return (-1);
			ft_bzero(buf[fd], BUFFER_SIZE + 1);
			break ;
		}
	rv = write2line(fd, buf[fd], line);
	return (rv);
}
