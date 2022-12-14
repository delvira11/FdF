/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:21:47 by delvira-          #+#    #+#             */
/*   Updated: 2022/12/14 17:06:53 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "fdf.h"
#include "libft/libft.h"

int	ft_sign(int x0, int x1)
{
	if (x0 < x1)
		return (1);
	else
		return (-1);
}

void	pinta_rayas(t_point point0, t_point point1, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs (point1.xcoord - point0.xcoord);
	dy = -abs (point1.ycoord - point0.ycoord);
	err = dx + dy;
	while (1 == 1)
	{	
		mlx_put_pixel(img, point0.xcoord, point0.ycoord, 0xFF0000FF);
		if (point0.xcoord == point1.xcoord && point0.ycoord == point1.ycoord)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			point0.xcoord += ft_sign(point0.xcoord, point1.xcoord);
		}
		if (e2 <= dx)
		{
			err += dx;
			point0.ycoord += ft_sign(point0.ycoord, point1.ycoord);
		}
	}
}

void	ft_draw_down_lines(t_point **matrix, mlx_image_t *img, char *filename)
{
	int	row;
	int	col;
	int	width;
	int	heigh;

	row = 0;
	col = 0;
	heigh = ft_get_heigh(filename);
	width = ft_get_line_width(filename);
	while (col < width)
	{
		row = 0;
		while (row < heigh - 1)
		{
			pinta_rayas(matrix[row][col], matrix[row + 1][col], img);
			row++;
		}
		col++;
	}
}

void	ft_draw_right_lines(mlx_image_t *img, t_point **matrix, char *filename)
{
	int	row;
	int	col;
	int	heigh;
	int	width;

	heigh = ft_get_heigh(filename);
	width = ft_get_line_width(filename);
	row = 0;
	while (row < heigh)
	{
		col = 0;
		while (col < width -1)
		{
			pinta_rayas(matrix[row][col], matrix[row][col + 1], img);
			col++;
		}
		row++;
	}
}

void	ft_printdots(mlx_image_t *img, t_point **matrix, char *filename)
{
	int	row;
	int	col;
	int	heigh;
	int	width;

	heigh = ft_get_heigh(filename);
	width = ft_get_line_width(filename);
	row = 0;
	col = 0;
	while (row < heigh)
	{
		col = 0;
		while (col < width)
		{
			mlx_put_pixel(img, matrix[row][col].xcoord,
				matrix[row][col].ycoord, 0xFF0000FF);
			//ft_print_big_dot(img, matrix[row][col], 0xFF0000FF);
			col++;
		}
		row++;
	}
	ft_draw_down_lines(matrix, img, filename);
	ft_draw_right_lines(img, matrix, filename);
}

// int	main(void)
// {
// 	mlx_t			*mlx;
// 	mlx_image_t		*img;
// 	t_point			**matrix;

// 	mlx = mlx_init(5000, 5000, "test", false);
// 	img = mlx_new_image(mlx, 10000, 10000);
// 	matrix = ft_matrix();
// 	ft_printdots(img, matrix);
// 	ft_draw_down_lines(matrix, img);
// 	ft_draw_right_lines(img, matrix);
// 	mlx_image_to_window(mlx, img, 300, 100);
// 	mlx_loop(mlx);
// }