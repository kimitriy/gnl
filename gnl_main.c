/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburton <rburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:43 by rburton           #+#    #+#             */
/*   Updated: 2021/01/03 17:24:44 by rburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int main() 
// {
    //char	file_name[] = "get_next_line_utils.c";
	//char	file_name[] = "file";
	//char	file_name[] = "1_newline";
	//char	file_name[] = "4_newlines";
	//char	file_name[] = "41_char";
	//char	file_name[] = "42_char";
	//char	file_name[] = "43_char";
	//char	file_name[] = "alphabet";
	//char	file_name[] = "empty_file";
	//char	file_name[] = "empty_lines";
	//char	file_name[] = "half_marge_bottom";
	//char	file_name[] = "half_marge_top";
	//char	*file_name = "huge_alphabet";
	//char	file_name[] = "huge_file";
	//char	file_name[] = "huge_line";
	//char	file_name[] = "huge_lines";
	//char	file_name[] = "huge_lines2";
	//char	file_name[] = "mix_marge1";
	//char	file_name[] = "mix_marge2";
	//char	file_name[] = "1.txt";
	//char	file_name[] = "2.txt";
	//char	file_name[] = "3.txt";
	//char	*file_name = "4.txt";
	//char	file_name[] = "5.txt";
	//char	file_name[] = "INVALID_FD";
	//char	file_name[] = "1b.txt";
	//char	file_name[] = "2b.txt";
	
// 	int		fd;
// 	int		rv;
//     char 	*line;
//     line = 0;

// 	fd = open("scene.rt", O_RDONLY);

//     rv = get_next_line(fd, &line);
//     while (rv > 0) 
// 	{
//         //write(1, "main:line:", 10);
// 		write(1, line, strlen(line));
//         write(1, "\n", 1);
//         free(line);
//         line = 0;
//         rv = get_next_line(fd, &line);
//     }
// 	if (rv == 0) {
//         write(1, line, strlen(line));
//         write(1, "\n", 1);
//         free(line);
//         line = 0;
//     }
// 	//while (1);
// }


int		main(void)
{
	//char	file_name[] = "get_next_line_utils.c";
	//char	file_name[] = "file";
	//char	file_name[] = "1_newline";
	//char	file_name[] = "4_newlines";
	//char	file_name[] = "41_char";
	//char	file_name[] = "42_char";
	//char	file_name[] = "43_char";
	//char	file_name[] = "alphabet";
	//char	file_name[] = "empty_file";
	//char	file_name[] = "empty_lines";
	//char	file_name[] = "half_marge_bottom";
	//char	file_name[] = "half_marge_top";
	//char	file_name[] = "huge_alphabet";
	//char	file_name[] = "huge_file";
	//char	file_name[] = "huge_line";
	//char	file_name[] = "huge_lines";
	//char	file_name[] = "huge_lines2";
	//char	file_name[] = "mix_marge1";
	//char	file_name[] = "mix_marge2";
	//char	file_name[] = "1.txt";
	//char	file_name[] = "2.txt";
	//char	file_name[] = "3.txt";
	//char	file_name[] = "4.txt";
	//char	file_name[] = "5.txt";
	//char	file_name[] = "INVALID_FD";
	//char	file_name[] = "1b.txt";
	//char	file_name[] = "2b.txt";

	int		fd;
	int		rv;
	char	*line;
	
	fd = open("scene.rt", O_RDONLY);
	
	while (1)
	{	
		rv = get_next_line(fd, &line);
		//printf("main:rv:%d\n", rv);
		printf("main:line:%s\n", line);
		//free(&line);
		free(line);
		
		if (rv == 0 || rv < 0)
			break ;
	}
	
	close(fd);
	return (0);
}

/*
int main() {
    int ret;
    char *line;
    line = 0;
    ret = get_next_line(0, &line);
    while (ret > 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(0, &line);
    }
    if (ret == 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
    }
	while (1);
}
*/