//TODO:
//gestire i colori delle mappe con i colori
//imparare bene alcuni dei comandi di minilibx
//controllare le dimensioni iniziali 
//controllare da dove parte a essere disegnata la mappa
//controllare altre varie cose che al momento non mi sovvengono

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
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	else if (data->iso_or_not == 0)
		{
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_flat(data);
	}
	if (key == 65307)
	{
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->main.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data_free(data);
		free(data);
		exit(1);
	}
	return (0);
}

//funzione per check dimensione iniziale. 
void	centre_and_zoom(fdf *data)
{
	//prova a disegnare senza disegnare, vedi se ci sta, senno riprova con zoom--
	//restituisci 0 se e' entra la mappa
	//restituisci 1 se non entra la mappa, e cambia lo zoom.
	//NON CENTRA ancora bene....
	/*int	centre_y;
	int	centre_x;
	int	x;
	int	y;

	centre_y = data->height * data->zoom / 2;
	centre_x = data->width * data->zoom/ 2;*/
	data->shift_y = 540; //i- centre_y;
	data->shift_x = 960; //- centre_x;
	//controllo zoom isometric/*
	/*
	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (x < data->width - 1 && y < data->height - 1)
			{
				if (bresenham_sim(data, (float)x, (float)y) == 0)
					{
						x = 0;
						y = 0; 
						data->zoom--;
						ft_printf("%d\n", data->zoom);
					}
			}
			x++;
		}
		y++;
	}*/
}


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
		//idata->shift_y = 240;  //:(((( no good`:
		//data->shift_x = 860;
		centre_and_zoom(data);
		data->iso_or_not = 1;
		//funzione che controlla lo zoom 

		data->main.img = NULL;
		draw(data);
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
