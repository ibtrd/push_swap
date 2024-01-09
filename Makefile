# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:14:34 by ibertran          #+#    #+#              #
#    Updated: 2024/01/09 06:44:11 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

# *** SOURCES **************************************************************** #

SRCS = \
	$(addsuffix .c, $(SRC))

SRCS_DIR	= srcs/
SRC	= \
	insert_biggest_sort \
	main \
	operations_list \
	operations_utils \
	parsing \
	progressive_presort \
	push \
	reverse_rotate \
	rotate \
	simplifier \
	simplifier_utils \
	sorting_utils \
	stacks_utils \
	swap \

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

BUILD_DIR = .build/

OBJS 		=	$(SRCS:%.c=$(BUILD_DIR)%.o)

OBJS_BONUS	=	$(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)

DEPS		=	$(OBJS:%.o=%.d) \
				$(OBJS_BONUS:%.o=%.d)

# *** LIBRARIES ************************************************************** #

LIB_NAME	=	ft
LIB_PATH	=	libft/libft.a

HEADERS		=	incs/

INCLUDES	= 	$(HEADERS) \
				$(dir $(LIB_PATH))incs/

# *** TRACE ****************************************************************** #

TRACE_DIR = .trace/

STD_TRACE = $(TRACE_DIR)

TRACE =	$(STD_TRACE)

# *** CONFIG ***************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3 -MMD -MP
CPPFLAGS = $(addprefix -I, $(INCLUDES))
LDFLAGS = $(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS = $(addprefix -l, $(LIB_NAME))

CC_FLAGS = $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

MKDIR = mkdir -p $(@D)

MAKE += --no-print-directory

# *** DEBUG ****************************************************************** #

ifeq ($(DEBUG),1)
BUILD_DIR := $(BUILD_DIR)debug/

CFLAGS := $(filter-out -O3,$(CFLAGS)) -g3

TRACE = $(DEBUG_TRACE)
endif

DEBUG_TRACE = $(TRACE_DIR)debug_

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME) $(NAME_BONUS)

$(NAME) : $(LIB_PATH) $(OBJS) $(addsuffix $(NAME), $(TRACE))
	$(CC) $(CC_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
ifeq ($(DEBUG),1)
	@$(RM) $(STD_TRACE)$@
	@echo "$(GREEN) $(NAME)(DEBUG) has been built! $(RESET)"
else
	@$(RM) $(DEBUG_TRACE)$@
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"
endif

.PHONY : bonus
bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIB_PATH) $(OBJS_BONUS) $(addsuffix $(NAME_BONUS), $(TRACE))
	$(CC) $(CC_FLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)
ifndef DEBUG
	@$(RM) $(DEBUG_TRACE)$@
	@echo "$(GREEN) $(NAME_BONUS) has been built! $(RESET)"
else
	@$(RM) $(STD_TRACE)$@
	@echo "$(GREEN) $(NAME_BONUS)(DEBUG) has been built! $(RESET)"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIB_PATH): FORCE 
	@$(MAKE) -C $(@D)

$(TRACE)% :
	@$(MKDIR)
	@touch $@

-include $(DEPS)

.PHONY : clean
clean :
	$(MAKE) -C $(dir $(LIB_PATH)) clean
	rm -rf $(BUILD_DIR)
	rm -rf $(TRACE_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	$(MAKE) -C $(dir $(LIB_PATH)) fclean
	rm -rf $(BUILD_DIR)
	rm -rf $(TRACE_DIR)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	echo "$(YELLOW) $(NAME) && $(NAME_BONUS) removed! $(RESET)"
	
.PHONY : re
re : fclean
	$(MAKE)

.PHONY : debug
debug :
	$(MAKE) DEBUG=1

.PHONY : %debug
%debug :
	$(MAKE) $(subst debug,,$@) DEBUG=1

.PHONY : norminette
norminette :
	$(MAKE) $@ -C $(dir $(LIB_PATH))
	norminette $(HEADERS) $(SRCS_DIR) > norminette.log; echo -n
	if [ $$(< norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < norminette.log grep Error; fi
			
# *** SPECIAL TARGETS ******************************************************** #

FORCE :

.PHONY : FORCE
.SILENT : clean fclean re debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m