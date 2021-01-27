/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_comments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:43 by rburton           #+#    #+#             */
/*   Updated: 2020/11/22 11:37:14 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	moveandzero(char *buf)
{
	int		i;
	char	*slshn;

	slshn = ft_strchr(buf, '\n'); //ищет вхождение \n
	if (slshn == NULL)
		ft_bzero(buf, BUFFER_SIZE); //если \n в buf нет то занулить весь буфер
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
		lineleak = NULL;
		lineleak = *line;
		*line = ft_strjoin(*line, tmpstr); //записать buf в line
		//if (lineleak != NULL)
		free(lineleak);
		free(tmpstr);
		if (buf[0] != '\0' && ft_strchr(buf, '\n') != NULL) //если первый (нулевой) элемент buf НЕ равен \0 (такое может быть только если в предыдущий цикл была найдена и выведена в line строка)
		{
			moveandzero(buf); //сдвинуть то что осталось и занулить
			return (1); //и выйти
		}
		moveandzero(buf); //если в line нет \n то записался весь buf и нужно занулить его, выходить не надо
		
		rvlen = read(fd, buf, BUFFER_SIZE); //т.к. в buf ничего нет, надо его прочитать
		if (rvlen < 0) //ошибка чтения
			return (-1);
		else if (rvlen == 0) //конец файла
			return (0);
		//buf[rvlen] = '\0'; //если чтение прошло успешно последнему элементу buf присвоить \0
	}
	return (rvlen);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1]; //создаем buf, +1 байт для \0
	int			rv;
	
	if (BUFFER_SIZE <= 0) //защита от неправильного BUFFER_SIZE
		return (-1);
	*line = malloc(1);
	**line = 0; //то же самое  что *line[0] = 0;
	// if (*line == NULL)
	// 	ft_strdup("");
	
	rv = write2line(fd, buf, line);
	
	return (rv); //п.5.4
}
