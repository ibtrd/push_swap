# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:14:34 by ibertran          #+#    #+#              #
#    Updated: 2023/12/29 00:41:05 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# *** SOURCES **************************************************************** #

SRC_DIR		=	srcs/
SRC			=	main parsing sorted stacks_utils \
				instructions/push \
				instructions/reverse_rotate \
				instructions/rotate \
				instructions/swap\
				\
				TESTS plouc_sort

SRCS 		=	$(addsuffix .c, $(SRC))			

# *** OBJECTS **************************************************************** #

BUILD_DIR	=	.build/

OBJS 		=	$(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS		=	$(OBJS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIBS		=	ft
LIBS_PATH 	=	libft/libft.a

INCLUDES	=	incs \
				$(dir $(LIBS_PATH))incs

# *** CONFIG ***************************************************************** #

CC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror -g3
CPPFLAGS	= 	-MMD -MP $(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

RM			=	rm -rf
MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME) 

$(NAME) : $(LIBS_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBS_PATH) :
	$(MAKE) -C $(@D)

-include $(DEPS)

bonus : all

clean :
	$(MAKE) -C $(dir $(LIBS_PATH)) clean
	$(RM) $(BUILD_DIR)
	@echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	$(MAKE) -C $(dir $(LIBS_PATH)) fclean
	$(RM) $(BUILD_DIR)
	$(RM) $(NAME)
	@echo "$(YELLOW) $(NAME) removed! $(RESET)"
	
re : fclean
	$(MAKE)

ARG = 3 2 1

run : 
	@$(MAKE)
	./$(NAME) $(ARG)

VALGRIND = valgrind --leak-check=full --leak-check=full

valgrind :
	@$(MAKE)
	$(VALGRIND) ./$(NAME) $(ARG)
	
# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m