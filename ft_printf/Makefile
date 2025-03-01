FUNC = ft_printf.c ft_putchar.c ft_puthexaupp.c ft_putstr.c \
		ft_strlen.c ft_putnbr.c ft_puthexalow.c \
		ft_putptr.c ft_putunsigned.c 

OBJS = ${FUNC:.c=.o}
NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)
 
$(NAME) : $(OBJS)
	ar rc $(NAME) $^

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean