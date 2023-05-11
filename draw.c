//drawing line 
//trova quanto devi far crescere X e di quanto Y usando float number 
//es
//x = 2 ; x1 = 4
//y = 2 ; y1 = 6
//steps per x = 2
//steps per y = 4 
//y deve crescere due volte piu veloce di x 
//ogni loop c'e' una crecita di y += 1 e x += 0.5
//
//dopo 4 steps x e y sono uguali con x1, y1 
//il float si trasforma in int con la funzione 
//mlx_pixel_put()
//


#include "fdf.h"

int ft_max(float a, float b) 
{
	if (a > b)
		return a;
	else
		return b;
}

float	mod(float i) // lui cambia il segno dell'eventuale float negativo 
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(0.80);
	*y = (*x + *y) * sin(0.80) - (z * data->zoom);
}

void	bresenham(float x, float y, float x1, float y1, fdf *data) // [1:1] [3:12]
{
	float	x_step; //la differenza tra vettori di coordinata x
	float	y_step; // stesso  per y 
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	// zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//color 
	if (z > 0 || z1 > 0)
		data->color = (0xe80c0c);
	else if (z == 0 || z1 == 0)
		data->color = (0xffffff);
	//2.5D
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	
	//shift	
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x; // 2 questo e' il delta 
	y_step = y1 - y; // 11
	max = ft_max(mod(x_step), mod(y_step)); // mod restituice il valore assoluto `

	x_step /= max;
	y_step /= max;
	
	while((int)(x - x1) || (int)(y - y1)) //finche esiste una differenza tra i due
	{
		my_mlx_pixel_put(&data->main, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	flat_bresenham(float x, float y, float x1, float y1, fdf *data) // [1:1] [3:12]
{
	float	x_step; //la differenza tra vettori di coordinata x
	float	y_step; // stesso  per y 
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	// zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//color 
	if (z > 0 || z1 > 0)
		data->color = (0xe80c0c);
	else if (z == 0 || z1 == 0)
		data->color = (0xffffff);
	//2.5D
	//
	//isometric(&x, &y, z);
	//isometric(&x1, &y1, z1);
	
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x; // 2
	y_step = y1 - y; // 11
	max = ft_max(mod(x_step), mod(y_step));

	x_step /= max;
	y_step /= max;
	
	while((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(&data->main, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}



void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	/* cancello e creo img su cui scrivere e la configuro */
	if (data->main.img)
		mlx_destroy_image(data->mlx_ptr, data->main.img);
	data->main.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->main.addr = mlx_get_data_addr(data->main.img, &data->main.bits_per_pixel, &data->main.line_length, &data->main.endian);
	while(y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->main.img, 0, 0);
}

void	draw_flat(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	/* cancello e creo img su cui scrivere e la configuro */
	if (data->main.img)
		mlx_destroy_image(data->mlx_ptr, data->main.img);
	data->main.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->main.addr = mlx_get_data_addr(data->main.img, &data->main.bits_per_pixel, &data->main.line_length, &data->main.endian);
	while(y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				flat_bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				flat_bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->main.img, 0, 0);
}

int	bresenham_sim(fdf *data, float x, float y) 
{
	int		z;

	z = data->z_matrix[(int)y][(int)x];

	printf("x: %f\n y: %f\n", x ,y); 
	x *= data->zoom;
	y *= data->zoom;

	isometric(&x, &y, z, data);
	x += data->shift_x;
	y += data->shift_y;
	if (x > data->width || y > data->height || y < 0 || x < 0)
		return (0);
	return (1);
}
