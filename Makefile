NAME		= cub3d
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g -Iinclude -Ilibft -Imlx
LDFLAGS		= -Llibft -Lmlx
LINKS		= -lft -lm -lmlx -lX11 -lXext
RM			= rm -f
MAKEFLAGS   := --no-print-directory

LIBFT		= libft/libft.a
MINILIBX    = mlx/libmlx.a

SRC_DIR		= src
SRCS		:= /main.c \
			/load_game.c \
			/read_map.c \
			/parsing.c \
			/utils.c \
			/key_press.c \
			/error.c \
			/raycast.c \
			/raycast2.c \
			/raycast_tex_utils.c \
			/minimap/draw_pixel.c \
			/minimap/draw_line.c \
			/minimap/draw_tile.c \
			/minimap/draw_textures.c \
			/player/ray.c \
			/player/move.c \

SRCS_FINAL = $(addprefix $(SRC_DIR), $(SRCS))

all: $(NAME)

$(NAME): $(SRCS_FINAL)
	@[ -f $(LIBFT) ] || make -C libft/
	echo "${BOLD}Creating  -> ${YELLOW}libft.a${NO_COLOR}"
	@[ -f $(MINILIBX) ] || make -C mlx/ > /dev/null 2>&1
	echo "${BOLD}Creating  -> ${BLUE}mlx.a${NO_COLOR}"
	$(CC) $(SRCS_FINAL) $(LDFLAGS) $(CFLAGS) $(LINKS) -o $(NAME)
	echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"
	$(MAKE) goku

clean:
	make clean -C libft/
	make clean -C mlx/ > /dev/null 2>&1

fclean: clean
	make fclean -C libft/
	make clean -C mlx/ > /dev/null 2>&1
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all goku
.SILENT:

RED			:= ${shell tput setaf 1}
BLUE		:= ${shell tput setaf 4}
YELLOW		:= ${shell tput setaf 3}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

goku:
	@echo '⣿⣿⠿⠿⠿⠿⣿⣷⣂⠄⠄⠄⠄⠄⠄⠈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣷⡾⠯⠉⠉⠉⠉⠚⠑⠄⡀⠄⠄⠄⠄⠄⠈⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠎⠄⠄⣀⡀⠄⠄⠄⠄⠄⠄⠄⠘⠋⠉⠉⠉⠉⠭⠿⣿'
	@echo '⡀⠄⠄⠄⠄⠄⠄⠄⠄⡇⠄⣠⣾⣳⠁⠄⠄⢺⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄'
	@echo '⣿⣷⡦⠄⠄⠄⠄⠄⢠⠃⢰⣿⣯⣿⡁⢔⡒⣶⣯⡄⢀⢄⡄⠄⠄⠄⠄⠄⣀⣤⣶'
	@echo '⠓⠄⠄⠄⠄⠄⠸⠄⢀⣤⢘⣿⣿⣷⣷⣿⠛⣾⣿⣿⣆⠾⣷⠄⠄⠄⠄⢀⣀⣼⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠑⢘⣿⢰⡟⣿⣿⣷⣫⣭⣿⣾⣿⣿⣴⠏⠄⠄⢀⣺⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣷⠶⠄⠄⠄⠹⣮⣹⡘⠛⠿⣫⣾⣿⣿⣿⡇⠑⢤⣶⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣯⣤⣤⣤⣤⣀⣀⡹⣿⣿⣷⣯⣽⣿⣿⡿⣋⣴⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣝⡻⢿⣿⡿⠋⡒⣾⣿⣧⢰⢿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⣏⣟⣼⢋⡾⣿⣿⣿⣘⣔⠙⠿⠿⠿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣛⡵⣻⠿⠟⠁⠛⠰⠿⢿⠿⡛⠉⠄⠄⢀⠄⠉⠉⢉'
	@echo '⣿⣿⣿⣿⡿⢟⠩⠉⣠⣴⣶⢆⣴⡶⠿⠟⠛⠋⠉⠩⠄⠉⢀⠠⠂⠈⠄⠐⠄⠄⠄'

