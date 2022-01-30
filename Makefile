# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusty <rusty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:56:00 by ubeetroo          #+#    #+#              #
#    Updated: 2022/01/30 10:35:20 by rusty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = gcc

FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = ./libft/

LIBFT = $(PATH_LIBFT)libft.a

PS_SRCS =  ft_clist_add_back \
	ft_clistdellone \
	ft_clstclear \
	ft_clist_add_front \
	ft_clistnew \
	errors \
	check_input \
	input \
	input_utils \
	utils \
	solve \
	solve_utils \
	find \
	actions \
	actions2 \
	actions3 \
	exec \
	main 
			

# PS_OBJ_FOLDER = ./obj/

# PS_INC = inc
# FLAGS += -I./inc
# FLAGS += -I./libft
# SRCS_B =	ft_lstnew \
# 			ft_lstadd_front \
# 			ft_lstsize \
# 			ft_lstlast \
# 			ft_lstadd_back \
# 			ft_lstdelone \
# 			ft_lstclear \
# 			ft_lstiter \
# 			ft_lstmap

PS_SRC =  $(addsuffix .c, $(PS_SRCS))
PS_OBJ =  $(addsuffix .o, $(PS_SRCS))

# SRC_B =  $(addsuffix .c, $(SRCS_B))
# PS_OBJ_B =  $(addsuffix .o, $(SRCS_B))


$(NAME): $(LIBFT) $(PS_OBJ) 
	$(COMP) $(FLAGS) $(PS_OBJ) $(LIBFT) -o $@

# bonus: $(PS_OBJ) $(PS_OBJ_B) 
# 	ar rcs $(NAME) $(PS_OBJ) $(PS_OBJ_B)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@ 

all: $(NAME) $(PS_INC) Makefile

clean: 
	rm -f $(PS_OBJ) 
	make -C $(PATH_LIBFT) clean

$(LIBFT):
	make -C $(PATH_LIBFT)

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean


re: fclean all

.PHONY: all clean fclean re
