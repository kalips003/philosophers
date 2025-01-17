NAME = philo
NAME_BONUS = philo_b

CC = cc
# FLAGS = -Wextra -Wall -g -fPIE -I$(HEADER_FOLDER)
FLAGS = -Wextra -Wall -Werror -g -fPIE -I$(HEADER_FOLDER)

all: $(NAME)

# ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
# │─██████████████─██████████████─██████████████─██████████████─██████████─██████──────────██████─██████████████─│
# │─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░██─██░░██████████──██░░██─██░░░░░░░░░░██─│
# │─██████░░██████─██░░██████████─██░░██████████─██████░░██████─████░░████─██░░░░░░░░░░██──██░░██─██░░██████████─│
# │─────██░░██─────██░░██─────────██░░██─────────────██░░██───────██░░██───██░░██████░░██──██░░██─██░░██─────────│
# │─────██░░██─────██░░██████████─██░░██████████─────██░░██───────██░░██───██░░██──██░░██──██░░██─██░░██─────────│
# │─────██░░██─────██░░░░░░░░░░██─██░░░░░░░░░░██─────██░░██───────██░░██───██░░██──██░░██──██░░██─██░░██──██████─│
# │─────██░░██─────██░░██████████─██████████░░██─────██░░██───────██░░██───██░░██──██░░██──██░░██─██░░██──██░░██─│
# │─────██░░██─────██░░██─────────────────██░░██─────██░░██───────██░░██───██░░██──██░░██████░░██─██░░██──██░░██─│
# │─────██░░██─────██░░██████████─██████████░░██─────██░░██─────████░░████─██░░██──██░░░░░░░░░░██─██░░██████░░██─│
# │─────██░░██─────██░░░░░░░░░░██─██░░░░░░░░░░██─────██░░██─────██░░░░░░██─██░░██──██████████░░██─██░░░░░░░░░░██─│
# │─────██████─────██████████████─██████████████─────██████─────██████████─██████──────────██████─██████████████─│
# ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────╯


NAMEE = philo
NAMEE_BONUS = philo_b
# num_philo . tt_die . tt_eat . tt_sleep . [num_time_each_philosopher_must_eat]
NUM_PHILO = 6
TIME_DIE = 605
TIME_EAT = 300
TIME_SLEEP = 300

ARG_SET_33 = 200 800 200 200 20
ARG = $(NUM_PHILO) $(TIME_DIE) $(TIME_EAT) $(TIME_SLEEP)
ARG2 = 5 100 33 66 3

ARG_SET_66 = 4 500 249 251

a: $(NAME)
	@$(call random_shmol_cat, teshting ... $@: $(ARG), 'hav fun ね? ($(word 1, $^))', $(CLS), );
	./$(word 1, $^) $(ARG_SET_66)

c: $(NAME)
	@$(call random_shmol_cat, teshting ... $@: $(ARG_SET_33), 'hav fun ね? ($(word 1, $^))', $(CLS), );
	$(HELLGRIND) ./$(word 1, $^) $(ARG_SET_33)

b: $(NAME_BONUS)
	@$(call random_shmol_cat, teshting ... $@ !, " $(NAME_BONUS): ", $(CLS), );
	$(VALGRIIND) ./$(word 1, $^) $(ARG)

d:	$(NAMEE)
	-@$(call random_shmol_cat, "\'teshting the limits of the food chain: MANY MIANY PHILO", $(ARG_SET_15), $(CLS), )
	@echo "\n\tTHIS ONE WILL TAKE A LOTS OF TIME\n\tthe output will be grep for 'died'\n";
	-./$(word 1, $^) $(ARG_SET_33) | grep died
	@(echo "\n\t\033[5m~ Press Enter to continue...\033[0m"; read -p "" key);

v: $(NAME)
	@$(call random_shmol_cat, "vlgrininnng ... $(word 1, $^)!", "$(ARG2)", $(CLS), );
	-$(HELLGRIND) ./$(word 1, $^) $(ARG2)


ARG_SET_1 = 0 60 60 60
ARG_SET_2 = 1 1000 60 60
ARG_SET_22 = 2 500 300 60
ARG_SET_4 = 6 200 99 99 5
ARG_SET_3 = 200 250 50 70 2
ARG_SET_5 = 7 200 99 99 5
ARG_SET_6 = 7 210 70 139 5
ARG_SET_7 = 7 210 70 140 5
ARG_SET_8 = 7 100 10 300
ARG_SET_9 = 7 100 300 10
ARG_SET_10 = 6 100 49 49
ARG_SET_11 = 5 100 33 66
ARG_SET_12 = 8 15 5 5 10
ARG_SET_13 = 3 4 1 1 5
ARG_SET_14 = 7 250 50 150
ARG_SET_15 = 200 800 200 200 200

# MAKE M: Run life threatening arguments (no valgrind, make things fucked up)
#
m: $(NAME)
	-@$(call helper_tester, $(ARG_SET_1), "\'teshting the limits of the food chain:", shouldnt work, $(HELLGRIND))
	-@$(call helper_tester, $(ARG_SET_2), "\'teshting the limits of the food chain:", should die without sleep, timeout 3s $(HELLGRIND))
	-@$(call helper_tester, $(ARG_SET_22), "\'teshting the limits of the food chain:", one should die, timeout 3s $(HELLGRIND))
	-@$(call helper_tester, $(ARG_SET_4), "\'teshting the limits of the food chain:", should all live happily ever after, )
	-@$(call helper_tester, $(ARG_SET_3), "\'teshting the limits of the food chain: MANY MIANY PHILO", should all live happily ever after, )
	-@$(call helper_tester, $(ARG_SET_5), "\'teshting the limits of the food chain:", one should die, )
	-@$(call helper_tester, $(ARG_SET_6), "\'teshting the limits of the food chain:", should all live happily ever after, )
	-@$(call helper_tester, $(ARG_SET_7), "\'teshting the limits of the food chain:", live or die? maybe?, )
	-@$(call helper_tester, $(ARG_SET_8), "\'teshting the limits of the food chain:", should stop after the first death in their sleep, timeout 3s $(HELLGRIND))
	-@$(call helper_tester, $(ARG_SET_9), "\'teshting the limits of the food chain:", should stop after the first death while eating, timeout 3s $(HELLGRIND))
	-@$(call helper_tester, $(ARG_SET_10), "\'teshting the limits of the food chain: SMALL TIMES", are you fast enough?, timeout 3s)
	-@$(call helper_tester, $(ARG_SET_11), "\'teshting the limits of the food chain: SMALL TIMES", are you fast enough?, timeout 3s)
	-@$(call helper_tester, $(ARG_SET_12), "\'teshting the limits of the food chain: SMALL TIMES", are you fast enough?, )
	-@$(call helper_tester, $(ARG_SET_13), "\'teshting the limits of the food chain: SMALL TIMES", are you fast enough?, )
	-@$(call helper_tester, $(ARG_SET_14), "\'teshting the limits of the food chain:", They all should be HAPPY、and enjoy their last moment before the end..., timeout 10s $(HELLGRIND))
	@$(call random_shmol_cat, \033[5m(DISCLAIMER)\033[25m, No philosophers was harmed in the making of this test, $(CLS), );


# MAKE N: Run a dozen bad arguments, with valgrind
#
n: $(NAMEE)
	@for arg in $(BAD_ARGS); do \
	$(call random_shmol_cat, teshting lots of bad args:, $$arg, $(CLS), ); \
	$(HELLGRIND) ./$(word 1, $^) $$arg; \
	echo "\t\033[5m~ Press Enter to continue...\033[0m"; read -p "" key; \
	done
	@$(call random_shmol_cat, this one is for valgriind output only:, valgrind doesnt like philosophers、some will die, $(CLS), )
	$(VALGRIIND) ./$(word 1, $^) 3 500 100 200 2

BAD_ARGS = "3 5 1 1 2a" \
			"3 5 1 wtf" \
			"3 5 1 -2147483650" \
			"3 5 1 2147483646 2147483647" \
			"3 5 1 9999999999 9" \
			"4 3 2" \
			"4 3 2 1 1 1" \
			"" \
			"4 3 2 00000000000000 -" \
			"i want ... youuu" \
			"5 1-2 4 5"


ULIMIT = 3000
m2: $(NAME)
	@$(call random_shmol_cat, "\'trying to make shit crash", "try n break it.. にゃ?", $(CLS), );
	@(ulimit -s $(ULIMIT); ./$(word 1, $^) $(ARG))
	ulimit -s 8192

# $(1)=$(ARGS) $(2)=$(TXT_cat) $(3)=$(TXT_below) $(4)=$(VALGRIND)(timeout 15s)
define helper_tester
	$(call random_shmol_cat, $(2), $(1), $(CLS), )
	echo "\n\t$(3)\n"
	read -p "" key;
	$(4) ./$(word 1, $^) $(1)
	echo "\n\t\033[5m~ Press Enter to continue...\033[0m"; read -p "" key;
endef


# ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
# │─██████████████─██████████████─██████──██████─████████████████───██████████████─██████████████─██████████████─│
# │─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─│
# │─██░░██████████─██░░██████░░██─██░░██──██░░██─██░░████████░░██───██░░██████████─██░░██████████─██░░██████████─│
# │─██░░██─────────██░░██──██░░██─██░░██──██░░██─██░░██────██░░██───██░░██─────────██░░██─────────██░░██─────────│
# │─██░░██████████─██░░██──██░░██─██░░██──██░░██─██░░████████░░██───██░░██─────────██░░██████████─██░░██████████─│
# │─██░░░░░░░░░░██─██░░██──██░░██─██░░██──██░░██─██░░░░░░░░░░░░██───██░░██─────────██░░░░░░░░░░██─██░░░░░░░░░░██─│
# │─██████████░░██─██░░██──██░░██─██░░██──██░░██─██░░██████░░████───██░░██─────────██░░██████████─██████████░░██─│
# │─────────██░░██─██░░██──██░░██─██░░██──██░░██─██░░██──██░░██─────██░░██─────────██░░██─────────────────██░░██─│
# │─██████████░░██─██░░██████░░██─██░░██████░░██─██░░██──██░░██████─██░░██████████─██░░██████████─██████████░░██─│
# │─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─│
# │─██████████████─██████████████─██████████████─██████──██████████─██████████████─██████████████─██████████████─│
# ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────╯

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, src/obj/%.o, $(SRC))

SRC_FOLDER = src
OBJ_FOLDER = src/obj
HEADER_FOLDER = inc

ADD_FLAGS = -lm -pthread

# ╭──────────────────────────────────────────────────────────────────────╮
# │                  	 	        Libft                      	         │
# ╰──────────────────────────────────────────────────────────────────────╯

libft:
	@make -sC lib all;

libclean:
	@make -sC lib clean

relib:
	@make -sC lib re

libtest:
	@make -sC lib test_color

# ╭──────────────────────────────────────────────────────────────────────╮
# │                  	 	       PROJECT                   	         │
# ╰──────────────────────────────────────────────────────────────────────╯

FLAGS_MLX = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lz
FLAGS_OTHER = -lm -pthread

$(NAME): libft $(OBJ) main.c
	@clear
	@if ! $(CC) $(FLAGS) $(OBJ) main.c lib/libft.a $(FLAGS_OTHER) -o $(NAME); then \
		$(call print_cat, "", $(RED), $(GOLD), $(RED_L), $(call pad_word, 10, "ERROR"), $(call pad_word, 12, "COMPILING..")); \
		exit 1; \
	fi
	$(call print_cat, $(CLEAR), $(GOLD), $(GREEN1), $(GREEN1), $(call pad_word, 10, $(NAME)), $(call pad_word, 12, "Compiled~"));

abc: libft $(OBJ) main.c
	@rm -f $(NAME)
	$(CC) $(FLAGS) $(OBJ) main.c lib/libft.a -lm -o $(NAME)

src/obj/%.o: src/%.c inc/$(NAME).h
	@if [ ! -e $(OBJ_FOLDER) ]; then\
		mkdir -p $(OBJ_FOLDER);\
	fi
	@if ! $(CC) -c $(FLAGS) $< -o $@; then \
		$(call shmol_cat_error, $(RED), $(RED_L)); \
		exit 1; \
	fi

# ╭──────────────────────────────────────────────────────────────────────╮
# │                  	 	       BONUS	                   	         │
# ╰──────────────────────────────────────────────────────────────────────╯

SRC_B = $(wildcard srcb/*.c)
OBJ_B = $(patsubst srcb/%.c, srcb/obj/%.o, $(SRC_B))

OBJ_FOLDER_B = srcb/obj

$(NAME_BONUS): bonus

bonus: $(OBJ_B) main_bonus.c inc/$(NAME).h
	@clear
	@if ! $(CC) $(FLAGS) $(OBJ_B) main_bonus.c lib/libft.a -lm -o $(NAME_BONUS); then \
		$(call print_cat, "", $(RED), $(GOLD), $(RED_L), $(call pad_word, 10, "ERROR"), $(call pad_word, 12, "COMPILING..")); \
		exit 1; \
	fi
	$(call print_cat, $(CLEAR), $(GOLD), $(GREEN1), $(COLOR_4R_1G_5B), $(call pad_word, 10, $(NAME_BONUS)), $(call pad_word, 12, "Compiled~"));

srcb/obj/%.o: srcb/%.c inc/$(NAME).h
	@clear
	@if [ ! -e $(OBJ_FOLDER_B) ]; then\
		mkdir -p $(OBJ_FOLDER_B);\
	fi
	@if ! $(CC) -c $(FLAGS) -c $< -o $@; then \
		$(call shmol_cat_error, $(RED), $(RED_L)); \
		exit 1; \
	fi


# ╭────────────────────────────────────────────────────────────────────────────╮
# │─██████████████─██████████████─██████████████─██████─────────██████████████─│
# │─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██─────────██░░░░░░░░░░██─│
# │─██████░░██████─██░░██████░░██─██░░██████░░██─██░░██─────────██░░██████████─│
# │─────██░░██─────██░░██──██░░██─██░░██──██░░██─██░░██─────────██░░██─────────│
# │─────██░░██─────██░░██──██░░██─██░░██──██░░██─██░░██─────────██░░██████████─│
# │─────██░░██─────██░░██──██░░██─██░░██──██░░██─██░░██─────────██░░░░░░░░░░██─│
# │─────██░░██─────██░░██──██░░██─██░░██──██░░██─██░░██─────────██████████░░██─│
# │─────██░░██─────██░░██──██░░██─██░░██──██░░██─██░░██─────────────────██░░██─│
# │─────██░░██─────██░░██████░░██─██░░██████░░██─██░░██████████─██████████░░██─│
# │─────██░░██─────██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─│
# │─────██████─────██████████████─██████████████─██████████████─██████████████─│
# ╰────────────────────────────────────────────────────────────────────────────╯

# --------------------------------------------------------------------------------- >
# VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --track-fds=yes
VALGRIND_OTHER = valgrind --vgdb=yes
HELLGRIND = valgrind --tool=helgrind

# ↑さ↓ぎょう  を  ↓ほ↑ぞん
git: fclean
	@$(call random_shmol_cat_blink, 作業を保存してるかな.., いいね、いいねえー , $(CLS), );
	@current_date=$$(date); \
	git add .; \
	git commit -m "$$current_date"; \
	git push

NORM_FILE = src/ main.c main_bonus.c inc/

norm: fclean
	@$(call random_shmol_cat_blink, 掃除してるかな..、いいね、いいねえー, giv file to norm, $(CLS), );
	-@read -p 'file...:' path; \
	if [ -z "$$path" ]; then \
		watch -n 0.2 norminette $(NORM_FILE); \
	else \
		watch -n 0.2 norminette $$path; \
	fi

# --------------------------------------------------------------------------------- >
# 																				TEST
test:	libft
	@rm -f ./lib/a.out
	-@cc ./lib/test.c ./lib/libft.a -o ./lib/a.out -lm
	@if [ ! -e ./lib/a.out ]; then\
		$(call print_cat, "", $(RED), $(GOLD), $(RED_L), $(call pad_word, 10, "The⠀Cake"), $(call pad_word, 12, "Is⠀A⠀Lie..")); \
		exit 3; \
	fi
	@$(call random_cat, $(call pad_word, 12, "Making"), $(call pad_word, 14, "Science"), $(CLS), $(RESET));
	@lib/a.out

test2:	$(OBJ_B) inc/$(NAME).h
	@rm -f ./lib/a.out
	@cc ./lib/test.c $(OBJ_B) -I$(HEADER_FOLDER) lib/libft.a -lm -o ./lib/a.out
	@$(call random_cat, $(call pad_word, 12, "TESTING"), $(call pad_word, 14, "SCIENCE"), $(CLS), $(RESET));
	-@$(VALGRIND) lib/a.out map/map4.ber

vtest:	libft
	@cc -g3 ./lib/test.c ./lib/libft.a -o ./lib/a.out -lm
	$(call print_cat, "", $(RED), $(GOLD), $(BLUE1), $(call pad_word, 10, "TESTING"), $(call pad_word, 12, "SCIENCE.."));
	@$(VALGRIND) lib/a.out
# --------------------------------------------------------------------------------- >
# 																				CLEAN
clean:
	@rm -rf $(OBJ_FOLDER)
	@$(call print_cat, $(CLEAR), $(COLOR_2R_2G_5B), $(COLOR_3R_2G_0B), $(COLOR_4R_5G_0B), $(call pad_word, 10, "Objects"), $(call pad_word, 12, "Exterminated"));

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -sC lib clean_silent;
	@$(call print_cat, $(CLEAR), $(COLOR_1R_2G_0B), $(COLOR_3R_0G_0B), $(COLOR_2R_1G_0B), $(call pad_word, 10, "All⠀clean"), $(call pad_word, 12, "Miaster"));

re: fclean all bonus

.PHONY: all clean fclean re bonus

.SILENT: $(NAME) bonus

# 	monitor stack activiity
# valgrind --tool=massif --stacks=yes ./your_program
# lldb: clean all
# 	@lldb ./$(NAME) $(ARGS)


# ╭────────────────────────────────────────────────────────────────────────────────────╮
# │─██████████████─████████████████───██████████─██████──────────██████─██████████████─│
# │─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░░░░░██─██░░██████████──██░░██─██░░░░░░░░░░██─│
# │─██░░██████░░██─██░░████████░░██───████░░████─██░░░░░░░░░░██──██░░██─██████░░██████─│
# │─██░░██──██░░██─██░░██────██░░██─────██░░██───██░░██████░░██──██░░██─────██░░██─────│
# │─██░░██████░░██─██░░████████░░██─────██░░██───██░░██──██░░██──██░░██─────██░░██─────│
# │─██░░░░░░░░░░██─██░░░░░░░░░░░░██─────██░░██───██░░██──██░░██──██░░██─────██░░██─────│
# │─██░░██████████─██░░██████░░████─────██░░██───██░░██──██░░██──██░░██─────██░░██─────│
# │─██░░██─────────██░░██──██░░██───────██░░██───██░░██──██░░██████░░██─────██░░██─────│
# │─██░░██─────────██░░██──██░░██████─████░░████─██░░██──██░░░░░░░░░░██─────██░░██─────│
# │─██░░██─────────██░░██──██░░░░░░██─██░░░░░░██─██░░██──██████████░░██─────██░░██─────│
# │─██████─────────██████──██████████─██████████─██████──────────██████─────██████─────│
# ╰────────────────────────────────────────────────────────────────────────────────────╯

# COLOR_2R_1G_3B
PURPLE = \033[38;5;97m
# COLOR_4R_3G_0B
GOLD = \033[38;5;178m
# COLOR_0R_4G_0B
GREEN1 = \033[38;5;40m
# COLOR_0R_4G_5B
BLUE1 = \033[38;5;45m

# $(COLOR_1R_0G_5B), $(COLOR_5R_1G_0B), $(COLOR_0R_2G_5B)
# $(RED), $(GOLD), $(BLUE1)

test_color666:
	@$(call random_cat, $(call pad_word, 12, The⠀Cake), $(call pad_word, 14, Is⠀A⠀Lie⠀...), $(CLS), $(RESET));
	@$(call random_cat, $(call pad_word, 13, The⠀Cake), $(call pad_word, 15, Is⠀A⠀Lie⠀...), , $(RESET));


# $(call pad_word, 12, The⠀Cake)
pad_word = $(BLINK)$(shell printf "%$(1)s" "$(2)")$(RESET)
# improve with: STRING1=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1));

# --------------------------------------------------------------------------------- >
# @$(call print_cat, $(CLEAR), $(body), $(eye), $(txt), $(call pad_word, 12, "The⠀Cake"), $(call pad_word, 12, "Is⠀A⠀Lie..."));
# print_cat (resest?)(color_cat)(color_eyes)(color_text)($(padded_txt_top))($(padded_txt_bot))
define print_cat
    echo "$(1)$(2)\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠒⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⠘⡄⠀⠀⠀⠀⠀⠀⣀⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠁⠉⠉⠉⠒⠊⠉⠀⡇⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜$(3)$(BLINK)⣀⡀$(RESET)$(2)⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⢴⠁$(3)$(BLINK)⠛⠁$(RESET)$(2)$(3)$(BLINK)⢀⣄$(RESET)$(2)⠀⠀⠀⢸⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠑⠺⡀⠀⠀⢶⠤$(3)$(BLINK)⠈⠋$(RESET)$(2)⠀⠀⠀⡘⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢄⡀⠀⠀⠀⠠⣉⠑⠂⠀⢠⠃⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠊⠀⠀⠀⠀⠀⠀⠁⠀⠀⠈⢆⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠒⠃⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀\n\
	\t\t\t\t\t\t\t	⠀⠔⠑⠄⠀⠀⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇\n\
	\t\t\t\t\t\t\t	⠸⡀⠀⢣⠀⠀⠀⠀⠀⠀⠀⠀⡇$(4)$(5)$(2)⠀⠀⠀⠀⠀⡇\n\
	\t\t\t\t\t\t\t	⠀⠱⡀⠀⠳⡀⠀⠀⠀⠀⠀⠀⢃$(4)$(6)$(2)⠀⠀⡸⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠑⢄⠀⠈⠒⢄⡀⠀⠀⠀⠸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠁⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠑⠦⣀⠀⠈⠉⠐⠒⠒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢢⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠉⠐⠒⠠⠤⠤⠤⠤⠔⠂⠠⠤⠤⠤⠄⠐⠒⠂⠉⠉⠉⠉⠉⠁\n$(RESET)"
endef

# --------------------------------------------------------------------------------- >
# @$(call random_cat, $(call pad_word, 12, txt1), $(call pad_word, 12, txt2), $(CLS), $(RESET));
# print_cat (resest?)(color_cat)(color_eyes)(color_text)($(padded_txt_top))($(padded_txt_bot))
define random_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	COLOR3=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
    echo "$(3)$${COLOR}\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠒⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⠘⡄⠀⠀⠀⠀⠀⠀⣀⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠁⠉⠉⠉⠒⠊⠉⠀⡇⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀$${COLOR2}$(BLINK)⣀⡀$(RESET)$${COLOR}⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⢴⠁⠀$${COLOR2}$(BLINK)⠛⠁$(RESET)$${COLOR}$${COLOR2}$(BLINK)⠀⠀⢀⣄$(RESET)$${COLOR}⠀⠀⠀⠀⢸⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠑⠺⡀⠀⠀⢶⠤$${COLOR2}$(BLINK)⠀⠈⠋$(RESET)$${COLOR}⠀⠀⠀⠀⡘⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢄⡀⠀⠀⠀⠠⣉⠑⠂⠀⢠⠃⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠊⠀⠀⠀⠀⠀⠀⠁⠀⠀⠈⢆⠀⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠒⠃⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀\n\
	\t\t\t\t\t\t\t	⠀⠔⠑⠄⠀⠀⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇\n\
	\t\t\t\t\t\t\t	⠸⡀⠀⢣⠀⠀⠀⠀⠀⠀⠀⠀⡇$${COLOR3}$(1)$${COLOR}⠀⠀⠀⠀⠀⡇\n\
	\t\t\t\t\t\t\t	⠀⠱⡀⠀⠳⡀⠀⠀⠀⠀⠀⠀⢃$${COLOR3}$(2)$${COLOR}⠀⠀⡸⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠑⢄⠀⠈⠒⢄⡀⠀⠀⠀⠸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠁⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠑⠦⣀⠀⠈⠉⠐⠒⠒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢢⠀\n\
	\t\t\t\t\t\t\t	⠀⠀⠀⠀⠀⠀⠀⠉⠐⠒⠠⠤⠤⠤⠤⠔⠂⠠⠤⠤⠤⠄⠐⠒⠂⠉⠉⠉⠉⠉⠁\n$(4)"
endef

# --------------------------------------------------------------------------------- >
# @$(call shmol_cat_color, $(color_cat), $(color_txt), text1, txt2, $(CLS), $(RESET));
define shmol_cat_color
	echo "$(5)$(2)\
	\tにゃ~$(1)\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$(2)~ $(3) ~$(1)\n\
	\t\t⠀|、˜\\\\\t\t$(2)$(4)$(1)\n\
	\t\t⠀じしˍ)ノ\n$(6)"
endef
# --------------------------------------------------------------------------------- >
# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

# // <!> - - - - - - - - - - - </!>
# --------------------------------------------------------------------------------- >
rscs:
	@$(call random_shmol_cat_surligne, text 1, text 2, $(CLS), $(RESET));

define random_shmol_cat_surligne
	COLOR=$$(printf "\033[0m\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	COLOR2=$$(printf "\033[48;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

rscb:
	@$(call random_shmol_cat_blink, text 1, text 2, $(CLS), $(RESET));

define random_shmol_cat_blink
	COLOR=$$(printf "\033[0m\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	COLOR2=$$(printf "\e[5m\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)\n$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef
# // <!> - - - - - - - - - - - </!>
# --------------------------------------------------------------------------------- >
# @$(call shmol_cat_error, $(RED), $(RED_L));
# $(1) = $(color_cat), $(2) = $(color_text)	NO CLS
define shmol_cat_error
	echo "$(2)\
	\tにゃ~$(1)\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$(2)~ somshin wen wong ~$(1)\n\
	\t\t⠀|、˜\\\\\n\
	\t\t⠀じしˍ)ノ\n$(RESET)"
endef

# 					Define all 256 colors
CLEAR = \033[2J\033[H
CLS = \033[2J\033[H
RESET = \033[0m
BLINK = \033[5m
# U+2800 to U+28FF Braile
# <Esc>[38;5;ColorNumberm
BLACK = \033[38;5;0m
RED = \033[38;5;1m
GREEN = \033[38;5;2m
YELLOW = \033[38;5;3m
BLUE = \033[38;5;4m
MAGENTA = \033[38;5;5m
CYAN = \033[38;5;6m
GRAY = \033[38;5;7m

BLACK_L = \033[38;5;8m
RED_L = \033[38;5;9m
GREEN_L = \033[38;5;10m
YELLOW_L = \033[38;5;11m
BLUE_L = \033[38;5;12m
MAGENTA_L = \033[38;5;13m
CYAN_L = \033[38;5;14m
WHITE = \033[38;5;15m

COLOR_0R_0G_0B = \033[38;5;16m
COLOR_0R_0G_1B = \033[38;5;17m
COLOR_0R_0G_2B = \033[38;5;18m
COLOR_0R_0G_3B = \033[38;5;19m
COLOR_0R_0G_4B = \033[38;5;20m
COLOR_0R_0G_5B = \033[38;5;21m
COLOR_0R_1G_0B = \033[38;5;22m
COLOR_0R_1G_1B = \033[38;5;23m
COLOR_0R_1G_2B = \033[38;5;24m
COLOR_0R_1G_3B = \033[38;5;25m
COLOR_0R_1G_4B = \033[38;5;26m
COLOR_0R_1G_5B = \033[38;5;27m
COLOR_0R_2G_0B = \033[38;5;28m
COLOR_0R_2G_1B = \033[38;5;29m
COLOR_0R_2G_2B = \033[38;5;30m
COLOR_0R_2G_3B = \033[38;5;31m
COLOR_0R_2G_4B = \033[38;5;32m
COLOR_0R_2G_5B = \033[38;5;33m
COLOR_0R_3G_0B = \033[38;5;34m
COLOR_0R_3G_1B = \033[38;5;35m
COLOR_0R_3G_2B = \033[38;5;36m
COLOR_0R_3G_3B = \033[38;5;37m
COLOR_0R_3G_4B = \033[38;5;38m
COLOR_0R_3G_5B = \033[38;5;39m
COLOR_0R_4G_0B = \033[38;5;40m
COLOR_0R_4G_1B = \033[38;5;41m
COLOR_0R_4G_2B = \033[38;5;42m
COLOR_0R_4G_3B = \033[38;5;43m
COLOR_0R_4G_4B = \033[38;5;44m
COLOR_0R_4G_5B = \033[38;5;45m
COLOR_0R_5G_0B = \033[38;5;46m
COLOR_0R_5G_1B = \033[38;5;47m
COLOR_0R_5G_2B = \033[38;5;48m
COLOR_0R_5G_3B = \033[38;5;49m
COLOR_0R_5G_4B = \033[38;5;50m
COLOR_0R_5G_5B = \033[38;5;51m
COLOR_1R_0G_0B = \033[38;5;52m
COLOR_1R_0G_1B = \033[38;5;53m
COLOR_1R_0G_2B = \033[38;5;54m
COLOR_1R_0G_3B = \033[38;5;55m
COLOR_1R_0G_4B = \033[38;5;56m
COLOR_1R_0G_5B = \033[38;5;57m
COLOR_1R_1G_0B = \033[38;5;58m
COLOR_1R_1G_1B = \033[38;5;59m
COLOR_1R_1G_2B = \033[38;5;60m
COLOR_1R_1G_3B = \033[38;5;61m
COLOR_1R_1G_4B = \033[38;5;62m
COLOR_1R_1G_5B = \033[38;5;63m
COLOR_1R_2G_0B = \033[38;5;64m
COLOR_1R_2G_1B = \033[38;5;65m
COLOR_1R_2G_2B = \033[38;5;66m
COLOR_1R_2G_3B = \033[38;5;67m
COLOR_1R_2G_4B = \033[38;5;68m
COLOR_1R_2G_5B = \033[38;5;69m
COLOR_1R_3G_0B = \033[38;5;70m
COLOR_1R_3G_1B = \033[38;5;71m
COLOR_1R_3G_2B = \033[38;5;72m
COLOR_1R_3G_3B = \033[38;5;73m
COLOR_1R_3G_4B = \033[38;5;74m
COLOR_1R_3G_5B = \033[38;5;75m
COLOR_1R_4G_0B = \033[38;5;76m
COLOR_1R_4G_1B = \033[38;5;77m
COLOR_1R_4G_2B = \033[38;5;78m
COLOR_1R_4G_3B = \033[38;5;79m
COLOR_1R_4G_4B = \033[38;5;80m
COLOR_1R_4G_5B = \033[38;5;81m
COLOR_1R_5G_0B = \033[38;5;82m
COLOR_1R_5G_1B = \033[38;5;83m
COLOR_1R_5G_2B = \033[38;5;84m
COLOR_1R_5G_3B = \033[38;5;85m
COLOR_1R_5G_4B = \033[38;5;86m
COLOR_1R_5G_5B = \033[38;5;87m
COLOR_2R_0G_0B = \033[38;5;88m
COLOR_2R_0G_1B = \033[38;5;89m
COLOR_2R_0G_2B = \033[38;5;90m
COLOR_2R_0G_3B = \033[38;5;91m
COLOR_2R_0G_4B = \033[38;5;92m
COLOR_2R_0G_5B = \033[38;5;93m
COLOR_2R_1G_0B = \033[38;5;94m
COLOR_2R_1G_1B = \033[38;5;95m
COLOR_2R_1G_2B = \033[38;5;96m
COLOR_2R_1G_3B = \033[38;5;97m
COLOR_2R_1G_4B = \033[38;5;98m
COLOR_2R_1G_5B = \033[38;5;99m
COLOR_2R_2G_0B = \033[38;5;100m
COLOR_2R_2G_1B = \033[38;5;101m
COLOR_2R_2G_2B = \033[38;5;102m
COLOR_2R_2G_3B = \033[38;5;103m
COLOR_2R_2G_4B = \033[38;5;104m
COLOR_2R_2G_5B = \033[38;5;105m
COLOR_2R_3G_0B = \033[38;5;106m
COLOR_2R_3G_1B = \033[38;5;107m
COLOR_2R_3G_2B = \033[38;5;108m
COLOR_2R_3G_3B = \033[38;5;109m
COLOR_2R_3G_4B = \033[38;5;110m
COLOR_2R_3G_5B = \033[38;5;111m
COLOR_2R_4G_0B = \033[38;5;112m
COLOR_2R_4G_1B = \033[38;5;113m
COLOR_2R_4G_2B = \033[38;5;114m
COLOR_2R_4G_3B = \033[38;5;115m
COLOR_2R_4G_4B = \033[38;5;116m
COLOR_2R_4G_5B = \033[38;5;117m
COLOR_2R_5G_0B = \033[38;5;118m
COLOR_2R_5G_1B = \033[38;5;119m
COLOR_2R_5G_2B = \033[38;5;120m
COLOR_2R_5G_3B = \033[38;5;121m
COLOR_2R_5G_4B = \033[38;5;122m
COLOR_2R_5G_5B = \033[38;5;123m
COLOR_3R_0G_0B = \033[38;5;124m
COLOR_3R_0G_1B = \033[38;5;125m
COLOR_3R_0G_2B = \033[38;5;126m
COLOR_3R_0G_3B = \033[38;5;127m
COLOR_3R_0G_4B = \033[38;5;128m
COLOR_3R_0G_5B = \033[38;5;129m
COLOR_3R_1G_0B = \033[38;5;130m
COLOR_3R_1G_1B = \033[38;5;131m
COLOR_3R_1G_2B = \033[38;5;132m
COLOR_3R_1G_3B = \033[38;5;133m
COLOR_3R_1G_4B = \033[38;5;134m
COLOR_3R_1G_5B = \033[38;5;135m
COLOR_3R_2G_0B = \033[38;5;136m
COLOR_3R_2G_1B = \033[38;5;137m
COLOR_3R_2G_2B = \033[38;5;138m
COLOR_3R_2G_3B = \033[38;5;139m
COLOR_3R_2G_4B = \033[38;5;140m
COLOR_3R_2G_5B = \033[38;5;141m
COLOR_3R_3G_0B = \033[38;5;142m
COLOR_3R_3G_1B = \033[38;5;143m
COLOR_3R_3G_2B = \033[38;5;144m
COLOR_3R_3G_3B = \033[38;5;145m
COLOR_3R_3G_4B = \033[38;5;146m
COLOR_3R_3G_5B = \033[38;5;147m
COLOR_3R_4G_0B = \033[38;5;148m
COLOR_3R_4G_1B = \033[38;5;149m
COLOR_3R_4G_2B = \033[38;5;150m
COLOR_3R_4G_3B = \033[38;5;151m
COLOR_3R_4G_4B = \033[38;5;152m
COLOR_3R_4G_5B = \033[38;5;153m
COLOR_3R_5G_0B = \033[38;5;154m
COLOR_3R_5G_1B = \033[38;5;155m
COLOR_3R_5G_2B = \033[38;5;156m
COLOR_3R_5G_3B = \033[38;5;157m
COLOR_3R_5G_4B = \033[38;5;158m
COLOR_3R_5G_5B = \033[38;5;159m
COLOR_4R_0G_0B = \033[38;5;160m
COLOR_4R_0G_1B = \033[38;5;161m
COLOR_4R_0G_2B = \033[38;5;162m
COLOR_4R_0G_3B = \033[38;5;163m
COLOR_4R_0G_4B = \033[38;5;164m
COLOR_4R_0G_5B = \033[38;5;165m
COLOR_4R_1G_0B = \033[38;5;166m
COLOR_4R_1G_1B = \033[38;5;167m
COLOR_4R_1G_2B = \033[38;5;168m
COLOR_4R_1G_3B = \033[38;5;169m
COLOR_4R_1G_4B = \033[38;5;170m
COLOR_4R_1G_5B = \033[38;5;171m
COLOR_4R_2G_0B = \033[38;5;172m
COLOR_4R_2G_1B = \033[38;5;173m
COLOR_4R_2G_2B = \033[38;5;174m
COLOR_4R_2G_3B = \033[38;5;175m
COLOR_4R_2G_4B = \033[38;5;176m
COLOR_4R_2G_5B = \033[38;5;177m
COLOR_4R_3G_0B = \033[38;5;178m
COLOR_4R_3G_1B = \033[38;5;179m
COLOR_4R_3G_2B = \033[38;5;180m
COLOR_4R_3G_3B = \033[38;5;181m
COLOR_4R_3G_4B = \033[38;5;182m
COLOR_4R_3G_5B = \033[38;5;183m
COLOR_4R_4G_0B = \033[38;5;184m
COLOR_4R_4G_1B = \033[38;5;185m
COLOR_4R_4G_2B = \033[38;5;186m
COLOR_4R_4G_3B = \033[38;5;187m
COLOR_4R_4G_4B = \033[38;5;188m
COLOR_4R_4G_5B = \033[38;5;189m
COLOR_4R_5G_0B = \033[38;5;190m
COLOR_4R_5G_1B = \033[38;5;191m
COLOR_4R_5G_2B = \033[38;5;192m
COLOR_4R_5G_3B = \033[38;5;193m
COLOR_4R_5G_4B = \033[38;5;194m
COLOR_4R_5G_5B = \033[38;5;195m
COLOR_5R_0G_0B = \033[38;5;196m
COLOR_5R_0G_1B = \033[38;5;197m
COLOR_5R_0G_2B = \033[38;5;198m
COLOR_5R_0G_3B = \033[38;5;199m
COLOR_5R_0G_4B = \033[38;5;200m
COLOR_5R_0G_5B = \033[38;5;201m
COLOR_5R_1G_0B = \033[38;5;202m
COLOR_5R_1G_1B = \033[38;5;203m
COLOR_5R_1G_2B = \033[38;5;204m
COLOR_5R_1G_3B = \033[38;5;205m
COLOR_5R_1G_4B = \033[38;5;206m
COLOR_5R_1G_5B = \033[38;5;207m
COLOR_5R_2G_0B = \033[38;5;208m
COLOR_5R_2G_1B = \033[38;5;209m
COLOR_5R_2G_2B = \033[38;5;210m
COLOR_5R_2G_3B = \033[38;5;211m
COLOR_5R_2G_4B = \033[38;5;212m
COLOR_5R_2G_5B = \033[38;5;213m
COLOR_5R_3G_0B = \033[38;5;214m
COLOR_5R_3G_1B = \033[38;5;215m
COLOR_5R_3G_2B = \033[38;5;216m
COLOR_5R_3G_3B = \033[38;5;217m
COLOR_5R_3G_4B = \033[38;5;218m
COLOR_5R_3G_5B = \033[38;5;219m
COLOR_5R_4G_0B = \033[38;5;220m
COLOR_5R_4G_1B = \033[38;5;221m
COLOR_5R_4G_2B = \033[38;5;222m
COLOR_5R_4G_3B = \033[38;5;223m
COLOR_5R_4G_4B = \033[38;5;224m
COLOR_5R_4G_5B = \033[38;5;225m
COLOR_5R_5G_0B = \033[38;5;226m
COLOR_5R_5G_1B = \033[38;5;227m
COLOR_5R_5G_2B = \033[38;5;228m
COLOR_5R_5G_3B = \033[38;5;229m
COLOR_5R_5G_4B = \033[38;5;230m
COLOR_5R_5G_5B = \033[38;5;231m
