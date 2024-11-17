# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iboiraza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 11:43:52 by iboiraza          #+#    #+#              #
#    Updated: 2024/11/16 22:00:44 by iboiraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC           = cc
MINILIBX_DIR = minilibx-linux/
MINILIBX     = $(MINILIBX_DIR)libmlx.a
FRACTOL_DIR  = ./
CFLAGS       = -Wall -Wextra -Werror
HEADERS      = -I $(FRACTOL_DIR) -I $(LIBFT_DIR)
NAME         = fractol
RM           = rm -rf

CFILES = $(wildcard $(FRACTOL_DIR)/*.c) \
         $(wildcard $(FRACTOL_DIR)/fractals/*.c)

OFILES = $(CFILES:.c=.o)

all: $(MINILIBX) $(NAME)

$(NAME): $(MINILIBX) $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L$(MINILIBX_DIR) -lmlx -lm -lX11 -lXext

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
