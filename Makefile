# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:01:42 by ajafy             #+#    #+#              #
#    Updated: 2023/05/05 11:51:29 by ajafy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAMEB = cub3D_bonus
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast
INC = -I ./inc
BUILD = build
BUILDB = build_bonus

HEADERS = inc/cube.h inc/ft_printf.h inc/get_next_line.h inc/libft.h

SRC = cub3D.c src/bonus/mouse.c src/bonus/draw_minimap.c src/parsing/2dlenandPrint.c src/parsing/ParsingMap.c \
	src/parsing/ParsingMap_utils.c src/parsing/get_file.c src/parsing/get_map_paco.c \
	src/parsing/parsingColorExt.c src/parsing/parsingPath.c src/parsing/prov.c \
	src/raycasting/calcule_distance.c src/raycasting/calcule_intersiction.c src/raycasting/keys.c \
	src/raycasting/mlx.c src/raycasting/move_player.c src/raycasting/raycasting.c src/raycasting/render_map.c \
	src/raycasting/wall_collision.c src/texture/draw_paint_walls.c src/texture/texture.c  \
	utilis/get_next_line/get_next_line.c utilis/get_next_line/get_next_line_utils.c utilis/libft/free2d.c \
	utilis/libft/ft_atoi.c utilis/libft/ft_lstnew.c utilis/libft/ft_split.c utilis/libft/ft_strchr.c \
	utilis/libft/ft_strcmp.c utilis/libft/ft_strdup.c utilis/libft/ft_strncmp.c utilis/libft/ft_strrchr.c \
	utilis/libft/initialisation.c utilis/printf/ft_argp.c utilis/printf/ft_hexa.c utilis/printf/ft_printf.c \
	utilis/printf/ft_putchar.c utilis/printf/ft_putnbr.c utilis/printf/ft_putstr.c utilis/printf/ft_unsignednumber.c

SRCB = cub3D_bonus.c src/bonus/mouse.c src/bonus/draw_minimap.c src/parsing/2dlenandPrint.c src/parsing/ParsingMap.c \
	src/parsing/ParsingMap_utils.c src/parsing/get_file.c src/parsing/get_map_paco.c \
	src/parsing/parsingColorExt.c src/parsing/parsingPath.c src/parsing/prov.c \
	src/raycasting/calcule_distance.c src/raycasting/calcule_intersiction.c src/raycasting/keys.c \
	src/raycasting/mlx.c src/raycasting/move_player.c src/raycasting/raycasting.c src/raycasting/render_map.c \
	src/raycasting/wall_collision.c src/texture/draw_paint_walls.c src/texture/texture.c  \
	utilis/get_next_line/get_next_line.c utilis/get_next_line/get_next_line_utils.c utilis/libft/free2d.c \
	utilis/libft/ft_atoi.c utilis/libft/ft_lstnew.c utilis/libft/ft_split.c utilis/libft/ft_strchr.c \
	utilis/libft/ft_strcmp.c utilis/libft/ft_strdup.c utilis/libft/ft_strncmp.c utilis/libft/ft_strrchr.c \
	utilis/libft/initialisation.c utilis/printf/ft_argp.c utilis/printf/ft_hexa.c utilis/printf/ft_printf.c \
	utilis/printf/ft_putchar.c utilis/printf/ft_putnbr.c utilis/printf/ft_putstr.c utilis/printf/ft_unsignednumber.c

OBJ = $(addprefix build/, $(SRC:.c=.o))
OBJB = $(addprefix build_bonus/, $(SRCB:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@echo "Mandatory successfully maked"
	
build/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean :
	@rm -rf $(BUILD)
	@rm -rf $(BUILDB)
	@echo "Cleaned"
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)

re : fclean all

bonus : $(NAMEB)

$(NAMEB) : $(OBJB) $(HEADERS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJB) -o $(NAMEB)
	@echo "Bonus successfully maked"

build_bonus/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

.PHONY : re fclean clean all