# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <szhong@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 20:52:33 by szhong            #+#    #+#              #
#    Updated: 2024/11/12 20:52:35 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Colors for output
GREEN		:=	\033[0;32m
RESET		:=	\033[0m
YELLOW		:=	\033[0;33m
MAGENTA		:=	\033[0;35m

NAME		:=	libtest.a
CC			:= 	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
AR			:= ar -rcs
RM			:= rm -rf

INCLUDE		:= -I ./inc
SRC_DIR		:= ./src
SRCS		:= \
			   test_runner.c \
			   assertions.c \
			   utils.c

OBJ_DIR		:= ./obj
OBJS		:= $(addprefix $(OBJ_DIR)/, $(patsubst %c, %o, $(SRCS)))

all: $(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[FT_TEST] Build Completed!$(RESET)"

$(OBJ_DIR)/%o: $(SRC_DIR)/%c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(YELLOW)[FT_TEST] Compiled: $<$(RESET)"


clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(MAGENTA)$[FT_TEST] Objects Removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)[FT_TEST] $(NAME) Removed"

re: fclean all

.PHONY: re fclean all clean
