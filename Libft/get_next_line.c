/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:32:00 by fsalvett          #+#    #+#             */
/*   Updated: 2023/01/25 11:36:44 by fsalvett         ###   ########.fr       */
/*                                       :w
 *                                      */
/* ************************************************************************** */

#include "libft.h"

char	*line_read_and_save(char *memorized_lines, int fd)
{	
	char	*temporary_buffer;
	int		counter;

	temporary_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temporary_buffer)
		return (NULL);
	counter = 1;
	while (!ft_strchr(memorized_lines, '\n') && counter != 0)
	{
		counter = read(fd, temporary_buffer, BUFFER_SIZE);
		if (counter == -1)
		{
			free (temporary_buffer);
			temporary_buffer = NULL;
			return (NULL);
		}
		temporary_buffer[counter] = '\0';
		memorized_lines = ft_strjoin_free(memorized_lines, temporary_buffer);
	}
	free(temporary_buffer);
	temporary_buffer = NULL;
	return (memorized_lines);
}

char	*line_move_to_return(char *memorized_lines)
{
	int		counter;
	char	*to_return;

	counter = 0;
	if (!memorized_lines[counter])
		return (NULL);
	while (memorized_lines[counter] != '\n' && memorized_lines[counter])
		counter++;
	to_return = (char *)malloc((counter + 2) * sizeof(char));
	if (!to_return)
		return (NULL);
	counter = -1;
	while (memorized_lines[++counter] != '\n' && memorized_lines[counter])
		to_return[counter] = memorized_lines[counter];
	if (memorized_lines[counter] == '\n')
	{
		to_return[counter] = '\n';
		counter++;
	}
	to_return[counter] = '\0';
	return (to_return);
}

char	*lines_forward_and_free(char *memorized_lines)
{
	int		counter;
	int		second_counter;
	char	*next_line;

	counter = 0;
	while (memorized_lines[counter] != '\n' && memorized_lines[counter])
		counter++;
	if (!memorized_lines[counter])
	{
		free(memorized_lines);
		memorized_lines = NULL;
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char)
			*(ft_strlen(memorized_lines) - counter + 1));
	if (!next_line)
		return (NULL);
	counter++;
	second_counter = 0;
	while (memorized_lines[counter] != '\0')
		next_line[second_counter++] = memorized_lines[counter++];
	next_line[second_counter] = '\0';
	free(memorized_lines);
	memorized_lines = NULL;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*memorized_lines;
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
	{
		if (memorized_lines != NULL)
		{
			free(memorized_lines);
			memorized_lines = NULL;
		}
		return (NULL);
	}
	memorized_lines = line_read_and_save(memorized_lines, fd);
	if (!memorized_lines)
	{
		free(memorized_lines);
		return (NULL);
	}
	line_to_return = line_move_to_return(memorized_lines);
	memorized_lines = lines_forward_and_free(memorized_lines);
	return (line_to_return);
}
