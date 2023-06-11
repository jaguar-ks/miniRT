# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:07:02 by faksouss          #+#    #+#              #
#    Updated: 2023/06/11 03:15:35 by nbouljih         ###   ########.fr        #
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
		src/math/intersection.c\
		src/math/vecrtors_operations.c\
		src/math/vecrtors_operations_2.c\
		src/parss/ft_Alight.c\
		src/parss/ft_Cam.c\
		src/parss/ft_cy.c\
		src/parss/ft_al_ut.c\
		src/parss/ft_cy_ut.c\
		src/parss/ft_Light.c\
		src/parss/ft_pl.c\
		src/parss/ft_sp.c\
		src/parss/ft_sp_ut.c\
		src/parss/list_utils.c\
		src/parss/my_utils.c\
		src/parss/my_utils2.c\
		src/parss/my_ut3.c\
		src/parss/parse.c\
		src/parss/read.c\
		src/parss/parse2.c\
		src/parss/ft_cy_ut2.c\
		src/parss/parse_utils.c\
		src/parss/ft_atof.c\
		src/parss/pl_ut.c\
		src/parss/ft_atois.c\
		src/parss/ft_light_ut.c\
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
	@printf "\r\033[0;33m⏳ MINIRT is compiling ...\033[0m"
	cc $(CFLAGS) $(OBJ) $(LIBTOOL) $(MLX_FLAGS) -o $@
	@printf "\r\033[0;33m⏳ MINIRT is ready ENJOY\033[0m"

$(LIBTOOL) :
	@printf "\r\033[0;33m⏳ libtool is compiling ...\033[0m"
	@make -C libtool
	@printf "\r\033[0;33m⏳ libtool is ready to use \033[0m"

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	@printf "\r\033[0;33mclearing object files 🚮🗑️ ...\033[0m"
	@make -C libtool clean
	$(RM) $(OBJDIR)

fclean : clean
	@printf "\r\033[0;33mYOU DELETED MY minirt 😱 YOU !*#^&# 😡🤬\033[0m\n"
	@make -C libtool fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re $(LIBTOOL)

.SILENT: all clean fclean re $(NAME) $(LIBTOOL)
