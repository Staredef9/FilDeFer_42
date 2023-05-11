#ifndef FDF_H
# define FDF_H

#include "./Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "./minilibx/mlx.h"

/* per scrivere su img */
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* rivedere def struct */
typedef struct
{
	int	width;
	int	height;
	int **z_matrix;
	int	zoom;
	int	color;
	int	shift_x;
	int	shift_y;
	int	iso_or_not;

	t_data	main;
	void	*mlx_ptr;
	void	*win_ptr;
} fdf;


int		ft_wdcounter(char const	*str, char	c);
int		get_height(char	*file_name);
int		get_width(char	*file_name);
void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	flat_bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);
void	draw_iso(fdf *data);
//agginta
void	draw_flat(fdf *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
