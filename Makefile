# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:14:34 by ibertran          #+#    #+#              #
#    Updated: 2024/01/05 07:06:40 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

# *** SOURCES **************************************************************** #

SRCS = \
	$(addsuffix .c, $(SRC))

SRC_DIR	= srcs/
SRC	= \
	insert_biggest_sort \
	main \
	operations_list \
	operations_utils \
	parsing \
	progressive_presort \
	progressive_presort_utils \
	push \
	reverse_rotate \
	rotate \
	simplifier \
	simplifier_utils \
	sorting_utils \
	stacks_utils \
	swap \
	tiny_sort \

# *** SOURCES BONUS ********************************************************** #

SRCS_BONUS = \
	$(addprefix $(SRC_BONUS_DIR), $(addsuffix _bonus.c, $(SRC_BONUS)))

SRC_BONUS_DIR =	bonus/
SRC_BONUS = \
	instructions \
	main \
	parsing \
	push \
	reverse_rotate \
	rotate \
	stacks_utils \
	swap \

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

CC_OPTION	= 	-O3
CFLAGS		=	-Wall -Wextra -Werror $(CC_OPTION) -MMD -MP

CPPFLAGS	= 	$(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

ALL_FLAGS	=	$(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME) $(NAME_BONUS)

$(NAME) : $(LIBS_PATH) $(OBJS)
	$(CC) $(ALL_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBS_PATH): FORCE
	$(MAKE) -C $(@D)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBS_PATH) $(OBJS_BONUS)
	$(CC) $(ALL_FLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS) 
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
	@echo "$(YELLOW) $(NAME) && $(NAME_BONUS) removed! $(RESET)"
	
re : fclean
	$(MAKE)

debug :
	$(MAKE) CC_OPTION="-g3" BUILD_DIR=".build/debug/"

norminette :
	$(MAKE) $@ -C $(dir $(LIBS_PATH))
	norminette $(SRC_DIR)
	norminette $(INCLUDES)
	
# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all clean fclean re debug norminette

FORCE :

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m