LOG_GREEN = \033[32m
LOG_NOCOLOR = \033[0m

ARCHIVE = libftcorewar.a

NAME = corewar

LIB = ./libft/

LIB_A = libft/libft.a

INCLUDES = -I ./includes/ -I libft/includes/

SOURCES = 	main.c		\
options.c				\
options_utils.c			\
read.c					\
champs.c				\
champs_utils.c			\
cycles.c				\
process.c				\
errors.c				\
print_arena.c			\
pc_utils.c				\
op_utils.c			\
op_utils2.c			\
live.c				\
ld.c					\
st.c					\
add.c				\
sub.c				\
ft_and.c				\
ft_or.c				\
ft_xor.c				\
zjmp.c				\
ldi.c				\
sti.c				\
ft_fork.c			\
lld.c				\
lldi.c				\
ft_lfork.c			\
aff.c				\
func_print.c		\
init_ncurses.c	\
print_hud.c		\
print_champ.c	\
key_hook.c		\
math_utils.c		\
sig_handler.c


SRCDIR = srcs
OBJDIR = obj

SRC = $(addprefix $(SRCDIR)/, $(SOURCES))

OBJ = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

CCFL = -Wall -Wextra -Werror -g


all: obj_dir library $(ARCHIVE) $(NAME)

obj_dir:
	@mkdir -p $(OBJDIR)

library:
	@make -C $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CCFL) -o $@ -c $< $(INCLUDES)

$(ARCHIVE): $(OBJ)
	@ar rc $(ARCHIVE) $(OBJ)
	@ranlib $(ARCHIVE)

$(NAME): $(OBJ)
	gcc $(CCFL) -o $(NAME) $(ARCHIVE) $(LIB_A)
	@echo "$(LOG_GREEN)Corewar has compiled successfully!$(LOG_NOCOLOR)"

clean:
	@make clean -sC $(LIB)
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(ARCHIVE)
	/bin/rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
