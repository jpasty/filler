NAME        := jpasty.filler

DIR_SRCS    := srcs/
DIR_INCLUDE  := include/
DIR_BIN     := bin/
DIR_LIBFT   := libft/
LIBFT       := libft.a
HEADERS     := libft.h filler.h
CC          := gcc
FLAGS       := -Wall -Wextra -Werror
RM          := /bin/rm -rf

SRCS        := main.c
OBJS        := $(SRCS:.c=.o)
LFT         := $(addprefix $(DIR_LIBFT), $(LIBFT))

MAKE_LFT    := make -C $(DIR_LIBFT)

vpath %.c $(DIR_SRCS)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INCLUDE)

``all: make_lft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(addprefix $(DIR_BIN), $(OBJS)) $(LFT) -o $@

$(OBJS): %.o:%.c $(HEADERS) | $(DIR_BIN)
	$(CC) -c $(FLAGS) $< -o $(DIR_BIN)$@ -I $(DIR_INCLUDE)

$(DIR_BIN):
	mkdir -p $@

make_lft:
	$(MAKE_LFT)

clean:
	$(RM) $(addprefix $(DIR_BIN), $(OBJS))
	$(RM) $(DIR_BIN)
	$(MAKE_LFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LFT) fclean

re: fclean all

.PHONY: clean fclean all re make_lft
.SILENT: all clean fclean re make_lft $(NAME) $OBJS $(DIR_BIN)
