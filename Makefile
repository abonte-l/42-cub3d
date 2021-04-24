SRC =	main.c \
		main_01_get_next_line.c \
		main_02_check_arg.c \
		main_03_parsing.c \
		main_04_parsing_color_res.c \
		main_05_parsing_textures.c \
		main_06_parsing_map.c \
		main_07_raycasting.c \
		main_08_sprites.c \
		main_09_save_to_bmp.c \
		main_10_movements.c \
		utils_01_init_1.c \
		utils_02_init_2.c \
		utils_03_get_next_line.c \
		utils_04_parsing_data.c \
		utils_05_parsing_data.c \
		utils_06_parsing_data.c \
		utils_07_parsing_map.c \
		utils_08_parsing_map.c \
		utils_09_handle_keys.c \
		utils_10_calc_raycasting.c \
		utils_11_print_and_textures.c \
		utils_12_cub3d.c \
		utils_13_error_exit.c 

NAME = cub3D

MLX_DIR = minilibx-linux
MLX = libmlx.a 
CC = clang

# diff entre .a et .dylib
# .a = lib static, les fonctions utilisees sont directement ecrite dans le binaire
# .dylib = lib dynamique, les fonctions doivent etre chargees au momnent ou on lance le binaire

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

# -C faire make comme si on etait dana le dossier
# -j multisreder / ameliore la vitesse de compliation
# Pas de regle opti car makefile mlx pas compatible
all:
	@$(MAKE) -j $(NAME)

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
# -L donner le nom du dossier / -l donner le nom le la lib
# loader path = ecrit le chemin de la mlx dans le binaire pour pouvoir la retrouver au moment ou on lance le binaire
$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re

# Utilise les .d (et ignore s'ils n'existe pas)
-include $(DPD)
