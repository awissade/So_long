/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_contents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:04 by awissade          #+#    #+#             */
/*   Updated: 2024/02/28 21:42:13 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

// Open the file and return the file descriptor
int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error : This mape doesn't exist\n", 2);
		exit(1);
	}
	return (fd);
}

// Allocate memory for the content of the file
// Return the pointer to the allocated memory
char	*allocate_memory(void)
{
	char	*content;

	content = ft_calloc(1, sizeof(char));
	if (!content)
	{
		ft_putstr_fd("Error : There is an error in reading the file\n", 2);
		exit(1);
	}
	return (content);
}

// Read the content of the file and return it
char	*read_file_contents(char *file_name)
{
	int		fd;
	char	*content;
	char	buffer[BUFFER_SIZE + 1];
	int		size_read;

	fd = open_file(file_name);
	content = allocate_memory();
	size_read = 0;
	size_read = read(fd, buffer, BUFFER_SIZE);
	while (size_read > 0)
	{
		buffer[size_read] = '\0';
		content = ft_strjoin(content, buffer);
		if (!content)
		{
			ft_putstr_fd("Error : There is an error in reading the file\n", 2);
			free(content);
			exit(1);
		}
		size_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (content[0] == '\0')
		return (ft_putstr_fd("Error : the file is empty\n", 2),
			close(fd), exit(1), NULL);
	return (close(fd), content);
}
