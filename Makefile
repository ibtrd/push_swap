# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:14:34 by ibertran          #+#    #+#              #
#    Updated: 2024/01/06 12:38:57 by ibertran         ###   ########lyon.fr    #
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

ifndef DEBUG
BUILD_DIR = .build/
else
BUILD_DIR = .build/debug/
endif

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

TRACE_DIR = .build/.trace/
STD_TRACE = $(TRACE_DIR)std/
DEBUG_TRACE = $(TRACE_DIR)debug/

ifndef DEBUG
TRACE =	$(STD_TRACE)
else
TRACE = $(DEBUG_TRACE)
endif

# *** CONFIG ***************************************************************** #

ifndef DEBUG
CC_OPTION = -O3
else
CC_OPTION = -g3
endif

CFLAGS		=	-Wall -Wextra -Werror $(CC_OPTION) -MMD -MP

CPPFLAGS 	= 	$(addprefix -I, $(INCLUDES))
LDFLAGS		=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIBS		=	$(addprefix -l, $(LIB_NAME))

PREPROCESSOR_FLAGS = $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

MKDIR 		= 	mkdir -p $(@D)

# *** TARGETS **************************************************************** #

all : $(NAME) $(NAME_BONUS)

$(NAME) : $(LIB_PATH) $(OBJS) $(addsuffix $(NAME), $(TRACE))
	$(CC) $(PREPROCESSOR_FLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
ifndef DEBUG
	@$(RM) $(DEBUG_TRACE)$@
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"
else
	@$(RM) $(STD_TRACE)$@
	@echo "$(GREEN) $(NAME)(DEBUG) has been built! $(RESET)"
endif

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIB_PATH) $(OBJS_BONUS) $(addsuffix $(NAME_BONUS), $(TRACE))
	$(CC) $(PREPROCESSOR_FLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)
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
	@$(MAKE) -C $(@D) --no-print-directory

$(TRACE)% :
	@$(MKDIR)
	@touch $@

-include $(DEPS)

clean :
	$(MAKE) -C $(dir $(LIB_PATH)) clean --no-print-directory
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"
	
fclean :
	$(MAKE) -C $(dir $(LIB_PATH)) fclean --no-print-directory
	rm -rf $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	echo "$(YELLOW) $(NAME) && $(NAME_BONUS) removed! $(RESET)"
	
re : fclean
	$(MAKE) --no-print-directory

debug :
	$(MAKE) DEBUG=1 --no-print-directory

%debug :
	$(MAKE) $(subst debug,,$@) DEBUG=1 --no-print-directory

norminette :
	$(MAKE) $@ -C $(dir $(LIB_PATH)) --no-print-directory
	echo
	mkdir -p $(BUILD_DIR)
	norminette $(HEADERS) $(SRCS_DIR) > $(BUILD_DIR)norminette.log; echo -n
	echo "$(NAME):"
	if [ $$(< $(BUILD_DIR)norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "Norm check OK!"; \
		else < $(BUILD_DIR)norminette.log grep Error; fi
		
# *** SPECIAL TARGETS ******************************************************** #

FORCE :

.PHONY : all bonus clean fclean re debug debug %debug norminette
.SILENT : clean fclean re debug norminette

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m