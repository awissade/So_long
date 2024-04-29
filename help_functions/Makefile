# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awissade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 13:56:57 by awissade          #+#    #+#              #
#    Updated: 2024/03/12 14:41:39 by awissade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		functions.a

SRCS		=		ft_strstr.c ft_strlen.c ft_putstr_fd.c read_file_contents.c \
					ft_strjoin.c ft_memset.c ft_calloc.c ft_substr.c ft_split.c \
					ft_strdup.c ft_free_map.c is_map_closed.c is_map_equal.c \
					make_copy.c contents_checker.c flood_fill.c check_valid_path.c \
					ft_putnbr_fd.c ft_count.c check_for_multiple_line.c ft_itoa.c \
					check_valid_path_bonus.c flood_fill_bonus.c


OBJS		=		$(SRCS:%.c=%.o)

CC			=		cc

CFLAGS		=		-Wextra -Wall -Werror

all			:		$(NAME)

$(NAME)		:		$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o			:		%.c
			$(CC) $(CFLAGS) -c $< -o $@
			
clean		:
			rm -rf $(OBJS)

fclean		:		clean
			rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
