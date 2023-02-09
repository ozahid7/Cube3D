NAME = cub3D
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc
BUILD = build

HEADERS = ${wildcard inc/*.h}
# i should change the wildcard with the static file names
SRC = ${wildcard *.c} ${wildcard src/*.c} ${wildcard src/**/*.c} ${wildcard utilis/*.c} ${wildcard utilis/**/*.c}

OBJ = $(addprefix build/, $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@echo "successfully maked"
	
build/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean :
	@rm -rf $(BUILD)
	@echo "Cleaned"
fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all