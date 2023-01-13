/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:43:37 by delvira-          #+#    #+#             */
/*   Updated: 2023/01/13 12:24:52 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include "fdf.h"

int	ft_get_heigh(char *filename)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	str = ft_get_next_line(fd);
	while (str)
	{
		free (str);
		str = ft_get_next_line(fd);
		i++;
	}
	free (str);
	close (fd);
	return (i);
}

int	ft_get_line_width(char *filename, int heigh)
{
	char	*str;
	char	**linesplited;
	int		x;
	int		fd;
	int		i;
	int		j;

	x = 0;
	j = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	//str = ft_get_next_line(fd);
		while (j < heigh)
	{
		str = ft_get_next_line(fd);
		j++;
	}
	ft_printf("\nline in width %s", str);
	linesplited = ft_split(str, ' ');
	while (linesplited[x])
	{
		if (linesplited[x][0] == '\n')
			i = 1;
		x++;
	}
	ft_free_split(linesplited);
	free (str);
	close(fd);
	return (x - i);
}

void	ft_print_big_dot(mlx_image_t *img, t_point point, uint32_t color)
{
	int	row;
	int	col;
	int	xinit;
	int	x;

	xinit = point.xcoord;
	col = 0;
	row = 0;
	while (row < 3)
	{
		col = 0;
		x = xinit;
		while (col < 3)
		{
			mlx_put_pixel(img, x, point.ycoord, color);
			col++;
			x++;
		}
		row++;
		point.ycoord++;
	}
	return ;
}

int	ft_colors(int diffvalor)
{
	int	red;
	int	green;
	int	blue;
	int	transparency;

	red = 0;
	blue = 125 - diffvalor;
	green = 125 + diffvalor;
	transparency = 255;
	return (red << 24 | green << 16 | blue << 8 | transparency);
}