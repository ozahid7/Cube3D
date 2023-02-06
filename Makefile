NAME = cube
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc
BUILD = build

SRC = src/main.c\
	utilis/printf/ft_printf.c utilis/printf/ft_putchar.c \
	utilis/printf/ft_putstr.c utilis/printf/ft_putnbr.c utilis/printf/ft_argp.c\
	utilis/printf/ft_hexa.c utilis/printf/ft_unsignednumber.c\
	utilis/get_next_line/get_next_line_utils.c utilis/get_next_line/get_next_line.c\

OBJ = $(addprefix build/, $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@echo "successfully maked"
	
build/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean :
	@rm -rf $(BUILD)
	@echo "Cleaned"
fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all