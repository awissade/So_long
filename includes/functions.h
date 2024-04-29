/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:01 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 23:41:12 by awissade         ###   ########.fr       */
/*   Updated: 2024/03/04 19:53:01 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define BUFFER_SIZE 32

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_strstr(char *str, char *sub);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*read_file_contents(char *file_name);
void	*ft_memset(void *ptr, int value, size_t num);
char	**ft_split(const char *map_str, char c);
char	*ft_substr(const char *map_str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
void	ft_free_map(char **map_content);
void	is_map_closed(char **map_content, size_t line_len);
void	is_map_equal(char **map_content);
char	**make_copy(char	**map_conent);
void	contents_checker(char **map_content);
void	flood_fill(char **copy);
void	check_valid_path(char **copy, char **map_content);
void	check_valid_path_bonus(char **copy, char **map_content);
void	ft_putnbr_fd(int n, int fd);
int		ft_count(char **map, char c);
void	check_for_multiple_line(char *str);
char	*ft_itoa(int n);
void	flood_fill_bonus(char **copy);

#endif
