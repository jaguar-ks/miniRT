/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:09:16 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 05:33:01 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_and_open_file(char *fl)
{
	int	i;

	i = ft_strlen(fl) - 1;
	if (fl[i] != 't' && fl[i - 1] != 'r' && fl[i - 2] == '.')
	{
		ft_printf("Error : Wrong file format\n", 2);
		exit(1);
	}
	return (open(fl, O_RDONLY, 0777));
}

void	er_rd_lines(t_read r_data)
{
	perror("Error: Memory allocation failed");
	free(r_data.all_ln);
	free(r_data.line);
	close(r_data.fd);
	exit(EXIT_FAILURE);
}

void	r_2(t_read *r_data)
{
	ft_memcpy(r_data->temp + r_data->total_si, r_data->line, r_data->line_s);
	r_data->temp[r_data->total_si + r_data->line_s] = '\0';
	r_data->all_ln = r_data->temp;
	r_data->total_si += r_data->line_s;
	free(r_data->line);
	r_data->line = get_next_line(r_data->fd);
}

char	*read_all_lines(const char *filename)
{
	t_read	r_data;

	r_data.all_ln = NULL;
	r_data.total_si = 0;
	r_data.fd = open(filename, O_RDONLY);
	if (r_data.fd == -1)
	{
		perror("Error: Opening the file");
		exit(EXIT_FAILURE);
	}
	r_data.line = get_next_line(r_data.fd);
	while (r_data.line != NULL)
	{
		r_data.line_s = ft_strlen(r_data.line);
		r_data.temp = malloc(r_data.total_si + r_data.line_s + 1);
		if (r_data.temp == NULL)
			er_rd_lines(r_data);
		if (r_data.all_ln != NULL)
		{
			ft_memcpy(r_data.temp, r_data.all_ln, r_data.total_si);
			free(r_data.all_ln);
		}
		r_2(&r_data);
	}
	return (close(r_data.fd), r_data.all_ln);
}
