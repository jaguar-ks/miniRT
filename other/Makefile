# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:07:02 by faksouss          #+#    #+#              #
#    Updated: 2023/05/16 15:15:25 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC =

OBJ_DIR = obj

OBJ = $(patsubst %, $(OBJDIR)/%, $(SRC:.c=.o))

HEADERS = libtool/inc/libft.h

INC_HEADERS = -I libtool/inc/libft.h

LIBTOOL = libtool/libft.a

all : $(NAME)

$(NAME): $(OBJ) 
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
	@printf "\r\033[0;33mYOU DELETED MY MINISHELL 😱 YOU !*#^&# 😡🤬\033[0m\n"
	@make -C libtool fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re $(LIBTOOL)

.SILENT: all clean fclean re $(NAME) $(LIBTOOL)
