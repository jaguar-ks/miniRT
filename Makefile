# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:07:02 by faksouss          #+#    #+#              #
#    Updated: 2023/05/29 05:31:10 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRC = src/list_utils.c\
		src/ft_cy_ut.c\
		src/my_utils.c\
		src/pl_ut.c\
		src/ft_cy.c\
		src/ft_pl.c\
		src/pt.c\
		src/parse_utils.c\
		src/ft_sp_ut.c\
		src/parse2.c\
		src/ft_Light.c\
		src/ft_Alight.c\
		src/parse.c\
		src/ft_sp.c\
		src/ft_Cam.c\
		src/main.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

OBJDIR = obj

OBJ = $(patsubst %, $(OBJDIR)/%, $(SRC:.c=.o))

HEADERS = libtool/inc/libft.h\
		inc/minirt.h

INC_HEADERS = -I libtool/inc\
			-I inc

LIBTOOL = libtool/libft.a

all : $(NAME)

$(NAME): $(LIBTOOL) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBTOOL) -o $@

$(LIBTOOL) :
	@printf "\r\033[0;33m⏳ libtool is compiling ...\033[0m"
	@make -C libtool

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_HEADERS)

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
