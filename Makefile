# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harmida <harmida@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 01:51:00 by dlucio            #+#    #+#              #
#    Updated: 2020/05/28 20:25:14 by harmida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HFILE	= ft_printf.h
FLAGS	= -Wall -Wextra -Werror
SRC		= utils/ft_accur_zero.c\
		  utils/ft_change_zero_list.c\
		  utils/ft_print_c.c\
		  utils/ft_print_d.c\
		  utils/ft_print_p.c\
		  utils/ft_print_s.c\
		  utils/ft_print_u.c\
		  utils/ft_print_width.c\
		  utils/ft_print_x.c\
		  utils/ft_putstr_n.c\
		  utils/ft_scan_and_percent.c\
		  utils/ft_what_a_char.c\
		  utils/ft_zero_accur_and_zero_int.c\
		  ft_printf.c
OBJS	= $(SRC:%.c=%.o)

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HFILE)
	cd libft && make bonus
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	@echo libftprintf.a compiled successfully

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@echo Object ft_printf files deleted

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@make fclean -C ./libft
	@echo libftprintf.a deleted
	
	

re: fclean all
