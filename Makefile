NAME = libftprintf.a

SRCS = 					srcs/ft_printf.c \
						srcs/utils_recup.c \
						srcs/recup.c \
						srcs/utils_impression.c \
						srcs/imprime_d.c \
						srcs/imprime_s.c \
						srcs/imprime_c.c\
						srcs/imprime_u.c \
						srcs/imprime_x.c \
						srcs/imprime_p.c\
						srcs/imprime_r.c
		

OBJECTS = 				ft_printf.o \
						utils_recup.o \
						recup.o \
						utils_impression.o \
						imprime_d.o \
						imprime_s.o \
						imprime_c.o\
						imprime_u.o \
						imprime_x.o \
						imprime_p.o\
						imprime_r.o\

INCLUDES = include/ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all