# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awissade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 20:49:44 by awissade          #+#    #+#              #
#    Updated: 2024/03/15 01:55:49 by awissade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long

B_NAME		=		so_long_bonus

LIBDIR		=		help_functions
LIB			=		$(LIBDIR)/functions.a

SRCS		=		main.c help_functions/check_map.c help_functions/check_path.c \
					help_functions/create_the_game.c \
					help_functions/create_the_window.c help_functions/load_images.c \
					help_functions/draw_map.c help_functions/close_the_game.c \
					help_functions/move_player.c

B_SRCS		=		main_bonus.c help_functions/check_map_bonus.c \
					help_functions/contents_checker_bonus.c \
					help_functions/check_path_bonus.c help_functions/create_the_game_bonus.c \
					help_functions/create_the_window_bonus.c help_functions/load_images_bonus.c \
					help_functions/draw_map_bonus.c help_functions/close_the_game.c \
					help_functions/move_player.c help_functions/move_player_bonus.c \
					help_functions/update.c


					

OBJS		=		$(SRCS:%.c=%.o)

B_OBJS		=		$(B_SRCS:%.c=%.o)

CC			=		cc
CFLAGS		=		-Wextra -Wall -Werror -I$(LIBDIR)
LDFLAGS		=		-L/usr/local/lib -lmlx -framework OpenGL -framework AppKit


all			:		$(LIB) $(NAME)

bonus		:		$(LIB) $(B_NAME)

$(LIB)		:
			@$(MAKE) -C $(LIBDIR)

$(NAME)		:		$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(LDFLAGS) -o $(NAME)

$(B_NAME)	:		$(B_OBJS)
			$(CC) $(CFLAGS) $(B_OBJS) $(LIB) $(LDFLAGS) -o $(B_NAME)

%.o			:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			rm -rf $(OBJS) 
			rm -rf $(B_OBJS)
			@$(MAKE) -C $(LIBDIR) clean

fclean		:		clean
			rm -rf $(NAME)
			rm -rf $(B_NAME)
			@$(MAKE) -C $(LIBDIR) fclean

re			:		fclean all

re_bonus	:		fclean bonus


.PHONY		:		all clean fclean re
