/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:29:46 by delvira-          #+#    #+#             */
/*   Updated: 2023/01/14 13:55:15 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_point {
	int			valor;
	int			xcoord;
	int			ycoord;
	int			color;
}	t_point;

typedef struct s_data {
	int	heigh;
	int	width;
	int	xcoor;
	int	ycoor;
}	t_data;

typedef struct s_red {
	int		x;
	int		i;
	char	*line;
}	t_red;

t_point	**ft_matrix(char *filename, t_data data);
int		ft_get_heigh(char *filename);
int		ft_get_line_width(char *filename, int heigh);
int		ft_sign(int x0, int x1);
void	pinta_rayas(t_point point0, t_point point1, mlx_image_t *img);
void	ft_print_big_dot(mlx_image_t *img, t_point point, uint32_t color);
void	ft_draw_down_lines(t_point **matrix, mlx_image_t *img, t_data data);
void	ft_draw_right_lines(mlx_image_t *img, t_point **matrix, t_data data);
void	ft_printdots(mlx_image_t *img, t_point **matrix, t_data data);
void	ft_free_split(char **split);
int		ft_colors(int diffvalor);
void	ft_sizecheck(t_point **matrix, t_red a);

#	endif