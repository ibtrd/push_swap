# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:14:34 by ibertran          #+#    #+#              #
#    Updated: 2024/01/04 05:13:26 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

# *** SOURCES **************************************************************** #

SRC_DIR		=	srcs/
SRC			=	main \
				parsing \
				stacks_utils \
				sorting_utils \
				swap push rotate reverse_rotate \
				tiny_sort \
				progressive_presort progressive_presort_utils \
				insert_biggest_sort \
				operations_list operations_utils \
				simplifier simplifier_utils

SRC_BONUS	=	bonus/main_bonus

SRCS 		=	$(addsuffix .c, $(SRC))
SRCS_BONUS 	=	$(addsuffix .c, $(SRC_BONUS))

# *** OBJECTS **************************************************************** #

BUILD_DIR	=	.build/

OBJS 		=	$(SRCS:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)
DEPS		=	$(OBJS:%.o=%.d) \
				$(OBJS_BONUS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIBS		=	ft
LIBS_PATH 	=	libft/libft.a

INCLUDES	=	incs \
				$(dir $(LIBS_PATH))incs

# *** CONFIG ***************************************************************** #

CFLAGS		+=	-Wall -Wextra -Werror -O3
CPPFLAGS	= 	-MMD -MP $(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME) 

$(NAME) : $(LIBS_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(DEFINE) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBS_PATH): FORCE
	$(MAKE) -C $(dir $(@))

bonus : $(NAME_BONUS)

simplifier :
	$(RM) $(NAME)
	$(MAKE) push_swap DEFINE="-D FORCEPRINT=0"

$(NAME_BONUS) : $(LIBS_PATH) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS_BONUS) $(LDFLAGS) $(LDLIBS) -o $(NAME_BONUS) 
	@echo "$(BLUE) $(NAME_BONUS) has been created! $(RESET)"

-include $(DEPS)

clean :
	$(MAKE) -C $(dir $(LIBS_PATH)) clean
	rm -rf $(BUILD_DIR)
	@echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	$(MAKE) -C $(dir $(LIBS_PATH)) fclean
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(YELLOW) $(NAME) removed! $(RESET)"
	
re : fclean
	$(MAKE)
	
# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re

FORCE :

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m