
NAME_CHECKER	= checker
NAME_PS			= push_swap


# directories

SRC_DIR_SHARED	= ./src
OBJ_DIR_SHARED	= ./obj

SRC_DIR_CHECKER	= ./src/checker
OBJ_DIR_CHECKER	= ./obj/checker

SRC_DIR_PS		= ./src/push_swap
OBJ_DIR_PS		= ./obj/push_swap

INC_DIR			= ./includes


# src / obj files

SRC_SHARED	= stack.c \
			  	stack2.c \
				util.c \
				util2.c \
				exec_op.c \
				ops_1.c \
				ops_2.c \
				read_input.c

SRC_CHECKER	= checker.c

SRC_PS		= push_swap.c \
				calc_cost.c \
				exec_next_op.c \
				opcodes.c \
				tools.c \
				main.c \
				bruteforce.c
			  

OBJ_SHARED 	= $(addprefix $(OBJ_DIR_SHARED)/, $(SRC_SHARED:.c=.o))
OBJ_CHECKER	= $(addprefix $(OBJ_DIR_CHECKER)/, $(SRC_CHECKER:.c=.o))
OBJ_PS		= $(addprefix $(OBJ_DIR_PS)/, $(SRC_PS:.c=.o))


# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= libft
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: $(NAME_CHECKER) $(NAME_PS)

$(OBJ_DIR_CHECKER):
	mkdir -p $@

$(OBJ_DIR_PS):
	mkdir -p $@


$(OBJ_DIR_SHARED)/%.o:$(SRC_DIR_SHARED)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INC) -o $@ -c $<


$(OBJ_DIR_CHECKER)/%.o:$(SRC_DIR_CHECKER)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INC) -o $@ -c $<


$(OBJ_DIR_PS)/%.o:$(SRC_DIR_PS)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INC) -o $@ -c $<


$(NAME_CHECKER): $(OBJ_DIR_CHECKER) $(OBJ_DIR_SHARED) $(OBJ_CHECKER) $(OBJ_SHARED)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ_CHECKER) $(OBJ_SHARED) $(LIB_LNK)

$(NAME_PS): $(OBJ_DIR_PS) $(OBJ_DIR_SHARED) $(OBJ_PS) $(OBJ_SHARED)
	@$(MAKE) -C $(L_FT)
	$(CC) -o $@ $(OBJ_PS) $(OBJ_SHARED) $(LIB_LNK)


clean:
	@$(MAKE) clean -C $(L_FT)
	rm -rf $(OBJ_DIR_SHARED)

fclean: clean
	@$(MAKE) fclean -C $(L_FT)
	rm -rf $(NAME_CHECKER)
	rm -rf $(NAME_PS)

re:
	@$(MAKE) fclean
	@$(MAKE) all
