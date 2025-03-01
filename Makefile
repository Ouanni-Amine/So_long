SRC_DIR = src/
BONUS_DIR = bonus/
SRC = $(SRC_DIR)so_long.c $(SRC_DIR)draw.c $(SRC_DIR)init.c $(SRC_DIR)map.c \
		$(SRC_DIR)move.c $(SRC_DIR)map_validation.c $(SRC_DIR)utils.c
OBJS = $(SRC:.c=.o)

BONUS = $(BONUS_DIR)so_long_bonus.c $(BONUS_DIR)draw_bonus.c $(BONUS_DIR)init_bonus.c $(BONUS_DIR)map_bonus.c \
		$(BONUS_DIR)move_bonus.c $(BONUS_DIR)map_validation_bonus.c $(BONUS_DIR)utils_bonus.c $(BONUS_DIR)fonctions_bonus.c\
		$(BONUS_DIR)fonctions2_bonus.c
OBJB = $(BONUS:.c=.o)

GNL_SRC = GNL/get_next_line_utils.c GNL/get_next_line.c
OBJS_GNL = ${GNL_SRC:.c=.o}

PRINTF_DIR = ft_printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
CC = cc
RM = rm -f

all: ft_printf libft $(NAME)

$(NAME) : $(OBJS) $(OBJS_GNL) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(OBJS_GNL) $(PRINTF) $(LIBFT) -o $(NAME)

ft_printf:
	make -C $(PRINTF_DIR)

libft:
	make -C $(LIBFT_DIR)

$(SRC_DIR)%.o: $(SRC_DIR)%.c $(SRC_DIR)so_long.h GNL/get_next_line.h $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

GNL/%.o: GNL/%.c GNL/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c $(BONUS_DIR)so_long_bonus.h GNL/get_next_line.h $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ft_printf libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJB) $(OBJS_GNL) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJB) $(OBJS_GNL) $(PRINTF) $(LIBFT) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_GNL) $(OBJB)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY: clean libft ft_printf 