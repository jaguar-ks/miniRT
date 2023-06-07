# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:07:02 by faksouss          #+#    #+#              #
#    Updated: 2023/06/07 00:27:11 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror -Ofast

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRC = src/main.c\
		src/draw/img_utils.c\
		src/draw/render.c\
		src/draw/light.c\
		src/draw/send_rayes.c\
		src/math/sphere_intersection.c\
		src/math/vecrtors_operations.c\
		src/math/vecrtors_operations_2.c\
		src/parss/ft_Alight.c\
		src/parss/ft_Cam.c\
		src/parss/ft_cy.c\
		src/parss/ft_cy_ut.c\
		src/parss/ft_Light.c\
		src/parss/ft_pl.c\
		src/parss/ft_sp.c\
		src/parss/ft_sp_ut.c\
		src/parss/list_utils.c\
		src/parss/my_utils.c\
		src/parss/parse.c\
		src/parss/parse2.c\
		src/parss/parse_utils.c\
		src/parss/pl_ut.c\
		src/parss/pt.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

OBJDIR = obj

OBJ = $(patsubst %, $(OBJDIR)/%, $(SRC:.c=.o))

HEADERS = libtool/inc/libft.h\
		inc/minirt.h

INC_HEADERS = -I libtool/inc\
			-I get_next_line/\
			-I inc/

LIBTOOL = libtool/libft.a

all : $(NAME)

$(NAME): $(LIBTOOL) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBTOOL) $(MLX_FLAGS) -o $@

$(LIBTOOL) :
	@printf "\r\033[0;33m⏳ libtool is compiling ...\033[0m"
	@make -C libtool

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	@printf "\r\033[0;33mclearing object files 🚮🗑️ ...\033[0m"
	@make -C libtool clean
	$(RM) $(OBJDIR)

fclean : clean
	@printf "\r\033[0;33mYOU DELETED MY miniRT 😱 YOU !*#^&# 😡🤬\033[0m\n"
	@make -C libtool fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re $(LIBTOOL)

.SILENT: all clean fclean re $(NAME) $(LIBTOOL)
