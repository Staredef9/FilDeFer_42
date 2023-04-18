//TODO:
//gestire i colori delle mappe con i colori
//gestire eventuali leak dati dalla minilibx
//imparare bene alcuni dei comandi di minilibx
//controllare le dimensioni iniziali 
//controllare da dove parte a essere disegnata la mappa
//controllare altre varie cose che al momento non mi sovvengono 
//imparare algebra lineare da qui a un anno 

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

//TODO: aggiungere i keybindings corretti multipiattaforma
//Fai una funzione che freea e distrugge tutto da passare 
//alle funzioni Deal Key 

int	deal_key(int key, fdf *data)
{
	ft_printf("%d\n", key);

	if (key == 113)
	{
		if (data->iso_or_not == 1)
			data->iso_or_not = 0;
		else if (data->iso_or_not == 0)
			data->iso_or_not = 1;
	}
	if (key == 65362 || key == 115)
			data->shift_y -= 10;
	if (key == 65364 || key == 119)
			data->shift_y += 10;
	if (key == 65361 || key == 97)
			data->shift_x -= 10;
	if (key == 65363 || key == 100)
			data->shift_x += 10;
	if (data->iso_or_not == 1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		//mlx_destroy_image(data->mlx_ptr, data->win_ptr);
		draw_iso(data);
	}
	else if (data->iso_or_not == 0)
		{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		//mlx_destroy_image(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	if (key == 65307)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		data_free(data);
		free(data);
		exit(1);
	}
	return (0);
}

//funzione per check dimensione iniziale. 


int main(int argc, char **argv)
{
	fdf *data;
	if (argc == 2)
	{
		data = (fdf*)malloc(sizeof(fdf));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");


		//cambia lo shift in base alla grandezza della mappa
		//serve una flag che in base alla lettura del file
		//dica questa cosa 
		data->zoom = 20;
		//qui inizia  la funzione di controllo 
		data->shift_y = 240;
		data->shift_x = 860;
		data->iso_or_not = 1;
		draw_iso(data);

		mlx_key_hook(data->win_ptr, deal_key, data); //bonus
		//aggiungi il comportamento per il tasto x della finestra
		mlx_loop(data->mlx_ptr);
	//if ()//premuto il tasto esc o x
	//		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else
		ft_printf("\n");
	return (0);
}
