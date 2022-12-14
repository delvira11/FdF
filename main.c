/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:46:36 by delvira-          #+#    #+#             */
/*   Updated: 2022/12/14 18:10:36 by delvira-         ###   ########.fr       */
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

t_point	**ft_matrix_fill(t_point **matrix, int fd, char *filename)
{
	int		i;
	int		x;
	char	*line;
	char	**linesplited;
	int		xcoord;
	int		ycoord;
	int 	heigh = ft_get_heigh(filename);
	x = 0;
	xcoord = 0;
	ycoord = 0;
	line = ft_get_next_line(fd);
	while (x < heigh)
	{
		i = 0;
		xcoord = 0;
		linesplited = ft_split(line, ' ');
		while (linesplited[i])
		{
			matrix[x][i].valor = ft_atoi(linesplited[i]);
			matrix[x][i].xcoord = ((xcoord - ycoord) * cos(0.5)) + 900;
			matrix[x][i].ycoord = ((xcoord + ycoord) * sin(0.5) + 100
					- matrix[x][i].valor * 1);
			i++;
			xcoord += 8;
		}
		ft_free_split(linesplited);
		free (line);
		line = ft_get_next_line(fd);
		ycoord += 8;
		x++;
	}
	free (line);
	return (matrix);
}

t_point	**ft_matrix(char *filename)
{
	t_point		**matrix;
	int			fd;
	int			malloccounter;
	int			heigh;
	int			width;

	heigh = ft_get_heigh(filename);
	width = ft_get_line_width(filename);
	printf("%i\n", heigh);
	printf("%i\n", width);
	malloccounter = 0;
	matrix = (t_point **)malloc(heigh * sizeof(t_point *));
	if (!matrix)
		return (NULL);
	while (malloccounter < heigh)
	{
		matrix[malloccounter] = (t_point *)malloc(width * sizeof(t_point));
		if (!matrix[malloccounter])
			return (NULL);
		malloccounter++;
	}
	fd = open(filename, O_RDONLY);
	matrix = ft_matrix_fill(matrix, fd, filename);
	close(fd);
	return (matrix);
}

int	main(int argc, char *argv[])
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_point			**matrix;
	char			*filename;

	filename = argv[1];
	if (argc > 2 != argc < 2)
		return (0);
	mlx = mlx_init(5000, 5000, "test", false);
	img = mlx_new_image(mlx, 10000, 10000);
	matrix = ft_matrix(filename);
	ft_printdots(img, matrix, filename);
	mlx_image_to_window(mlx, img, 0, 0);
	//mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
}

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
