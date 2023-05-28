/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:08:53 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/28 20:43:36 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/minirt.h"

int	check_and_open_file(char *fl)
{
	int i;
	
	i  = ft_strlen(fl) - 1;
	if(fl[i] != 't' && fl[i - 1] != 'r' && fl[i - 2] == '.')
	{
		ft_printf("Error : Wrong file format\n", 2);
		exit(1);
	}
	return (open(fl, O_RDONLY, 0777));
}

char *read_all_lines(const char *filename);

char *read_all_lines_wrapper(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error: Opening the file");
        return NULL;
    }

    char *all_lines = read_all_lines(filename);

    close(fd);
    return all_lines;
}

char *read_all_lines(const char *filename)
{
    char *line;
    char *all_lines = NULL;
    size_t total_size = 0;
    ssize_t read_size;
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Error: Opening the file");
        return NULL;
    }

    while ((line = get_next_line(fd)) != NULL) {
        size_t line_size = ft_strlen(line);
        char *temp = malloc(total_size + line_size + 1);
        if (temp == NULL) {
            perror("Error: Memory allocation failed");
            free(all_lines);
            free(line);
            close(fd);
            return NULL;
        }
        if (all_lines != NULL) {
            ft_memcpy(temp, all_lines, total_size);
            free(all_lines);
        }
        ft_memcpy(temp + total_size, line, line_size);
        temp[total_size + line_size] = '\0';
        all_lines = temp;
        total_size += line_size;
        free(line);
    }
    close(fd);
    return all_lines;
}

char    **read_file(char *fl)
{
	int     fd;
	char    *r;
	char    **sp;

	r = NULL;
	r = read_all_lines(fl);
	sp = ft_split(r, '\n');
	free(r);
	return (sp);
}

int	mtx_len(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
		i++;
	return (i);
}

void    _miniRT(char *fl)
{
	t_rt    rt;

	rt.fl = read_file(fl);
	if (!rt.fl || !rt.fl[0])
	{
		ft_printf("Error : empty file\n", 2);
		exit(1);
	}
	init_rt(&rt);
	// free(rt.al);
	// free(rt.cam);
	// free(rt.lt);
	deallocate(rt.fl);
	// free(rt.pl);
	// for (int i = 0; i < mtx_len(rt.fl); i++)
	// 	printf("-> %s\n", rt.fl[i]);
}
void detect_memory_leaks() {
    system("leaks a.out");
}

int main(int ac, char **av){
	if (ac == 2)
		_miniRT(av[1]);
	else
	{
		ft_printf("Error : Bad number of args\n", 2);
		exit(EXIT_FAILURE);
	}
	// detect_memory_leaks();
}
