#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:27:18 by naali             #+#    #+#              #
#    Updated: 2019/02/28 00:25:03 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

IFLAGS		=	-Iincludes -Ilibft

SRC			=	deal_with_key.c \
				main.c \
				fill_img.c \
				pixel_color_put_choice.c \
				refresh_windows.c \
				segmnt_creation.c \
				ft_pushback_str_to_tab.c \
				mapfunc.c \
				convert.c \
				matrice_init.c \
				matrice_rot.c \
				matrice_scal.c	\
				matrice_trans.c \
				mult_matrice.c \
				multiply.c \
				t_vect.c \
				t_vertex.c

OBJ			=	$(SRC:.c=.o)

OBJ_PATH	=	./obj

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ))

vpath %.c ./srcs/:./srcs/drawing:./srcs/getmap:./srcs/matrice

LIBPATH		=	./libft

LDFLAGS		=	-L$(LIBPATH)

LFLAGS		=	-lmlx \
				-lft

LDLIBS		=	$(LDFLAGS) $(LFLAGS)

FFLAGS 		=	-framework OpenGL -framework Appkit

$(OBJ_PATH)/%.o:	%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@echo "Compiling $< ...\c"
			@$(CC) $(CFLAGS) -o $@ -c $^ $(CFLAGS) $(IFLAGS)
			@echo " DONE"

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBPATH)
			@echo "Compiling $(NAME) ...\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS) $(LDLIBS) $(FFLAGS)
			@echo " DONE"

clean:
			@$(MAKE) clean -C $(LIBPATH)
			@echo "cleaning the obj file ...\c"
			@rm -rf $(OBJS)
			@echo " DONE"

fclean:		clean
			@$(MAKE) fclean -C $(LIBPATH)
			@echo "cleaning the executable ...\c"
			@rm -rf $(NAME)
			@echo " DONE"

re:			fclean all

.PHONY:		all clean fclean re
