#include "fdf.h"

int	get_height(char *file_name)
{
	int	fd;
	int height;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		ft_wdcounter(char const *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_width(char *file_name)
{
	int	width;
	int	fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	line = NULL;
	while((line = get_next_line(fd)))
		free(line);
	close(fd);
	return width;
}


void	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	i = 0;
	nums = ft_split(line, ' ');
	while(nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int i;
	int fd;
	char *line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	printf("%d %d\n", data->height, data->width);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
}
