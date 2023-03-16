NAME = so_long
CC = gcc
FLAGS = -g -Wall -Werror -Wextra -fsanitize=address
SRC = ft_split.c ft_substr.c ft_strlcpy.c ft_strlen.c ft_strdup.c ft_memcpy.c \
		ft_free_s.c main.c get_next_line.c get_next_line_utils.c check_map.c \
		parsing.c flood_fill.c build_game.c \
		run_game.c ft_printf.c ft_printf_utils.c
HEAD = so_long.h
OBJDIR = build
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@ MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -lglfw3

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean re all
