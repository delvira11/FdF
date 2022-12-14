/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:29:46 by delvira-          #+#    #+#             */
/*   Updated: 2022/12/14 18:00:12 by delvira-         ###   ########.fr       */
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

t_point	**ft_matrix(char *filename);
int		ft_get_heigh(char *filename);
int		ft_get_line_width(char *filename);
int		ft_sign(int x0, int x1);
void	pinta_rayas(t_point point0, t_point point1, mlx_image_t *img);
void	ft_print_big_dot(mlx_image_t *img, t_point point, uint32_t color);
void	ft_draw_down_lines(t_point **matrix, mlx_image_t *img, char *filename);
void	ft_draw_right_lines(mlx_image_t *img, t_point **matrix, char *filename);
void	ft_printdots(mlx_image_t *img, t_point **matrix, char *filename);
void	ft_free_split(char **split);
int		ft_colors(int diffvalor);

# endif