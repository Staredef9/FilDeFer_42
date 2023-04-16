//TODO:
//gestire i colori delle mappe con i colori
//gestire eventuali leak dati dalla minilibx
//imparare bene alcuni dei comandi di minilibx
//
//fare i binding corretti dei tasti, 
//gestire la cosa isometrica attraverso un tasto 
//
//controllare le dimensioni iniziali 
//controllare da dove parte a essere disegnata la mappa
//controllare altre varie cose che al momento non mi sovvengono 
//
//imparare algebra lineare da qui a un anno 
//per bene 
//
//



#include "fdf.h"

void	data_free(fdf *data)
{
	int	i;

	i = 0;
	while(data->z_matrix[i])
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}


//TODO: aggiungere i keybinndings corretti multipiattaforma
//aggiungere le combinazioni di tasti 
//mettere quella del cambio tra proiezione 2d e isometrica legata a un tasto
//duplicare la funzione bresenham e legarla ai tasti q ed e
//bresenham_2d
//bresenham_isometric
//
int	deal_key(int key, fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 65364 || key == 115)
			data->shift_y -= 10;
	if (key == 65362 || key == 113)
			data->shift_y += 10;
	if (key == 65361 || key == 97)
			data->shift_x -= 10;
	if (key == 65363 || key == 100)
			data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	if (key == 65307)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		return 1;
	}
	return (0);
}

int main(int argc, char **argv)
{
	fdf *data;
	int	fd;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 1200, "FDF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data); //bonus
	mlx_loop(data->mlx_ptr);
	//if ()//premuto il tasto esc o x
	//		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data_free(data);
	free(data);
}
