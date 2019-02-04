#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 17:52:13 by naali             #+#    #+#              #
#    Updated: 2019/02/04 17:57:30 by naali            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fdf

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

SRC0		=	deal_with_key.c fill_img.c main.c segmnt_creation.c


SRCPATH0	=	/Users/naali/42_projects/fdf

SOURCES0	=	$(addprefix $(SRCPATH0)/, $(SRC0))

SRC1		=	ft_pushback_str_to_tab.c mapfunc.c


SRCPATH1	=	/Users/naali/42_projects/fdf/getmap

SOURCES1	=	$(addprefix $(SRCPATH1)/, $(SRC1))

SRC2		=	convert.c matrice_init.c matrice_rot.c matrice_scal.c matrice_trans.c mult_matrice.c multiply.c t_vect.c t_vertex.c


SRCPATH2	=	/Users/naali/42_projects/fdf/matrice

SOURCES2	=	$(addprefix $(SRCPATH2)/, $(SRC2))

HDR0		=	mlx.h


HDRPATH0	=	/Users/naali/42_projects/fdf

HEADERS0	=	$(addprefix $(HDRPATH0)/, $(HDR0))

HDR1		=	fdf.h t_struct.h


HDRPATH1	=	/Users/naali/42_projects/fdf/includes

HEADERS1	=	$(addprefix $(HDRPATH1)/, $(HDR1))

LIBNAME	=	ft

LIBPATH	=	/Users/naali/42_projects/fdf/libft

LIBHEAD	=	/Users/naali/42_projects/fdf/libft

OBJ0		=	$(SRC0:.c=.o)

%.o:		$(SRCPATH0)/%.c
			$(CC) -o $@ -c $^ $(CFLAGS)

OBJ1		=	$(SRC1:.c=.o)

%.o:		$(SRCPATH1)/%.c
			$(CC) -o $@ -c $^ $(CFLAGS)

OBJ2		=	$(SRC2:.c=.o)

%.o:		$(SRCPATH2)/%.c
			$(CC) -o $@ -c $^ $(CFLAGS)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ0) $(OBJ1) $(OBJ2)
			@(cd $(LIBPATH) && $(MAKE))
			$(CC) -o $(NAME) $(OBJ0) $(OBJ1) $(OBJ2) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME)  -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

clean:
			@(cd $(LIBPATH) && $(MAKE) clean)
			rm -rf $(OBJ0) $(OBJ1) $(OBJ2)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
