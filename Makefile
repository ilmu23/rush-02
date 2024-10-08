# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 14:51:42 by ivalimak          #+#    #+#              #
#    Updated: 2024/08/20 15:42:24 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rush-02

BUILD	=	normal

CC 				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.debug	=	-g
cflags.debum	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address
cflags.normal	=	
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

SRCDIR	=	src
OBJDIR	=	obj
INCDIR	=	inc
LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

SRCFILES	=	main.c \
				dict.c \
				check.c \
				print.c \
				number.c

SRCS	=	$(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(OBJDIR):
	@echo Creating objdir...
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@make -C $(LIBDIR) --no-print-directory BUILD=$(BUILD)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $< -o $@

clean:
	@make -C $(LIBDIR) --no-print-directory clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) --no-print-directory fclean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
