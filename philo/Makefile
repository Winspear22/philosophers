# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:23:14 by user42            #+#    #+#              #
#    Updated: 2022/02/08 07:18:02 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_OS = $(shell uname)

ifeq ($(NAME_OS), Darwin)
        SRC = srcs/*.c
NAME_OS = MAC
endif
ifeq ($(NAME_OS), Linux)
        SRC = srcs/*.c

endif

OBJ = *.o

FLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread

WHITE ='\033[0m'
WHITE_2 = \033[0m
BLUE ='\033[36m'
CYAN ='\033[1;32m'
YELLOW = \e[93m
RED = \e[31m


all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "Compilation en cours de $(NAME) sur l'OS \"$(NAME_OS)\"" $(WHITE)
	@echo "$(RED)─────$(YELLOW)╔╗$(RED)──$(YELLOW)╔╗$(RED)───────────────$(YELLOW)╔╗$(RED)──$(YELLOW)╔╗$(RED)────────────$(YELLOW)╔╗"
	@echo "$(RED)─────$(YELLOW)║║$(RED)──$(YELLOW)║║$(RED)───────$(YELLOW)╔╗$(RED)──────$(YELLOW)║║$(RED)──$(YELLOW)║║$(RED)────────────$(YELLOW)║║"
	@echo "╔══╦═╝╠══╣║╔══╦╗╔╦╣╠══╗╔══╣╚═╦╣║╔══╦══╦══╦══╣╚═╦══╦═╦══╗"
	@echo "║╔╗║╔╗║╔╗║║║╔╗║║║╠╬╣══╣║╔╗║╔╗╠╣║║╔╗║══╣╔╗║╔╗║╔╗║║═╣╔╣══╣"
	@echo "║╔╗║╚╝║╔╗║╚╣╚╝║╚╝║║╠══║║╚╝║║║║║╚╣╚╝╠══║╚╝║╚╝║║║║║═╣║╠══║"
	@echo "╚╝╚╩══╩╝╚╩═╩══╩══╩╝╚══╝║╔═╩╝╚╩╩═╩══╩══╩══╣╔═╩╝╚╩══╩╝╚══╝$(YELLOW)"
	@echo "$(RED)───────────────────────$(YELLOW)║║$(RED)────────────────$(YELLOW)║║"
	@echo "$(RED)───────────────────────$(YELLOW)╚╝$(RED)────────────────$(YELLOW)╚╝$(WHITE_2)"
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -g
	@echo $(BLUE)"Tout a été compilé avec succès ! -"$(WHITE)

$(OBJ): $(SRC)
	@echo $(CYAN) "Creation des fichiers .o." $(WHITE)
	@gcc $(FALGS) -c $(SRC)

clean:
	@echo "Suppression en cours des fichiers .o de philo."
	@echo $(CYAN) "Suppression des fichiers .o de philo." $(WHITE)
	@rm -f ${OBJ}
	@cd srcs;rm -f ${OBJ}
	@echo "Nettoyage des fichiers .o effectué"

fclean: clean
	@echo $(CYAN) "Suppression du logiciel $(NAME)." $(WHITE)
	@rm -rf $(NAME)
	@echo "Tout a été supprimé !"

re: fclean all