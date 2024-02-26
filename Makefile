# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 11:18:55 by bda-mota          #+#    #+#              #
#    Updated: 2024/02/26 16:43:56 by bda-mota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
NAME_BONUS	:= pipex_bonus
CFLAGS		:= -Wextra -Wall -Werror

# LIBRARIES_PATH
LIBFT_PATH = ./libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH 	:= objects
BONUS_PATH	:= sources_bonus
OBONUS_PATH	:= objects_bonus

# SOURCES
CFILES		:= pipex.c utils.c

CBONUS		:=

SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))
SRC_BONUS	:= $(addprefix $(BONUS_PATH)/, $(CBONUS))
OBJ_BONUS	:= $(addprefix $(OBONUS_PATH)/, $(CBONUS:%.c=%.o))

HEADERS		:= -I ./includes
HEADER_FILE := includes/pipex.h

MAKEFLAGS += --silent

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEADER_FILE) | $(OBONUS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBONUS_PATH):
	@mkdir -p $(OBONUS_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)PIPEX$(WHITE)] has been compiled!  "
	@echo "$(GREEN)-------------------------------------------"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBFT) $(INCLUDES) -o $(NAME_BONUS)
	@echo "$(GREEN)----------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)PIPEX BONUS$(WHITE)] has been compiled!  "
	@echo "$(GREEN)----------------------------------------------"

clean:
	@rm -rf $(OBJS) $(OBONUS_PATH)
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE) Objects - PIPEX - were cleaned!"
	@echo "$(RED)-----------------------------------"

fclean: clean
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(RED)-----------------------------------"
	@rm -rf $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE) ✨ Cleaning - PIPEX - complete! ✨"
	@echo "$(RED)---------------------------------------"

re: clean all

.PHONY: all, clean, fclean, re
