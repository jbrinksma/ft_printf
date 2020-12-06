# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbrinksm <jbrinksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/04 14:36:57 by jbrinksm       #+#    #+#                 #
#    Updated: 2019/03/14 18:34:31 by jbrinksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf struct_handlers read_conversion_specification \
replace_conversion_specification conversions_to_str_wrapper poxf_converters \
manipulate_converted_str add_field_width_and_flags diouxx_to_str_wrapper \
add_precision extra_functions

SRCS := $(SRCS:%=srcs/%.c)

FT_SRCS = putstr putchar putnbr putendl strdup strlen strndup strjoin itoa \
intlen revstr atoi isspace strstr strncmp strcmp atoi \
uitoa unsintlen longlonglen lltoa unslonglonglen ulltoa char_to_str putnstr

FT_SRCS := $(FT_SRCS:%=srcs/libft/ft_%.c)

OBJS = $(SRCS:srcs/%=%)

OBJS := $(OBJS:.c=.o)

FT_OBJS = $(FT_SRCS:srcs/libft/%=%)

FT_OBJS := $(FT_OBJS:.c=.o)

FLGS = -Wall -Werror -Wextra

GCC = gcc -c -Wall -Werror -Wextra -Iincludes/ $(SRCS) $(FT_SRCS)

LIB = ar rc $(NAME) $(OBJS) $(FT_OBJS)

$(NAME):
	$(GCC)
	$(LIB)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(FT_OBJS)
	rm -rf *~

fclean: clean
	rm -rf $(NAME)
	rm -rf aaTEST 

prog: re
	gcc -Wall -Werror -Wextra main.c -L. -lftprintf -Iincludes/ -o aaTEST
	make clean

re: fclean all