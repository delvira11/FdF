/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:46:36 by delvira-          #+#    #+#             */
/*   Updated: 2023/01/14 14:10:59 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "fdf.h"
#include "math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_free_split(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free (split[x]);
		x++;
	}
	free (split);
}

t_point	**ft_matrix_fill(t_point **matrix, t_data data, int fd, t_red a)
{
	char	**linesplited;

	a.line = ft_get_next_line(fd);
	while (a.x < data.heigh)
	{
		a.i = 0;
		data.xcoor = 0;
		linesplited = ft_split(a.line, ' ');
		while (linesplited[a.i])
		{
		matrix[a.x][a.i].valor = ft_atoi(linesplited[a.i]);
		matrix[a.x][a.i].xcoord = ((data.xcoor - data.ycoor) * cos(0.5)) + 1200;
		matrix[a.x][a.i].ycoord = ((data.xcoor + data.ycoor) * sin(0.5) + 300
					- matrix[a.x][a.i].valor * 5);
			ft_sizecheck(matrix, a);
			a.i++;
			data.xcoor += 20;
		}
		//ft_free_split(linesplited);
		//free (a.line);
		a.line = ft_get_next_line(fd);
		data.ycoor += 20;
		a.x++;
	}
	//free (a.line);
	return (matrix);
}

t_point	**ft_matrix(char *filename, t_data data)
{
	t_point			**matrix;
	int				malloccounter;
	int				fd;
	t_red			red_line;

	red_line.x = 0;
	fd = open(filename, O_RDONLY);
	malloccounter = 0;
	matrix = (t_point **)malloc(data.heigh * sizeof(t_point *));
	if (!matrix)
		return (NULL);
	while (malloccounter < data.heigh)
	{
		matrix[malloccounter] = (t_point *)malloc(data.width * sizeof(t_point));
		if (!matrix[malloccounter])
			return (NULL);
		malloccounter++;
	}
	matrix = ft_matrix_fill(matrix, data, fd, red_line);
	return (matrix);
}

int	main(int argc, char *argv[])
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_point			**matrix;
	char			*filename;
	t_data			data;

	if (argc > 2 != argc < 2)
	{
		perror("number of arguments incorrect");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	data.heigh = ft_get_heigh(filename);
	data.width = ft_get_line_width(filename, data.heigh);
	ft_printf("\nread heigh %i", data.heigh);
	ft_printf("\nreal width %i\n", data.width);
	mlx = mlx_init(5000, 5000, "test", false);
	img = mlx_new_image(mlx, 10000, 10000);
	matrix = ft_matrix(filename, data);
	ft_printdots(img, matrix, data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
}
	//system("leaks -q fdf");

// int	main(void)
// {
// 	int		heigh;
// 	int		width;
// 	t_point **matrix;
// 	heigh = ft_get_heigh();
// 	width = ft_get_line_width();
// 	matrix = ft_matrix();
// 	int row, columns;
// for (row=0; row<heigh; row++)
// {
//     for(columns=0; columns<width; columns++)
//     {
// 		// printf("row: %i\n", row);
// 		// printf("col: %i\n", columns);
// 		printf("%i ", matrix[row][columns].valor);
// 		// printf("x: %i\n", matrix[row][columns].xcoord);
// 		// printf("y: %i\n\n", matrix[row][columns].ycoord);
//     }
//     printf("\n");
// }

// system("leaks -q fdf");
// // int fd = open("test.txt", O_RDONLY);
// // printf("%s", ft_get_next_line(fd));
// // printf("%s", ft_get_next_line(fd));
// }
