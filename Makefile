NAME := Philo

### SRCS ######################################################################

PATH_SRCS := srcs/

SRCS += main.c

vpath %.c $(PATH_SRCS)

### INCLUDES ##################################################################

PATH_INCLUDES := includes/

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c,$(PATH_OBJS)%.o,$(SRCS))

### LIBFT ######################################################################

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

### COMPILATION ################################################################

CC := CC

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

### COLORS ####################################################################

WHITE := \033[0m
GREEN := \033[0;32m
BLUE := \033[0;34m

### RULES #####################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(PATH_INCLUDES) -I $(PATH_LIBFT)
	@echo "$(GREEN)$(NAME) has been created !$(WHITE)"'

$(OBJS):$(PATH_OBJS)%.o: %.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES) -I $(PATH_LIBFT)

$(LIBFT):
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)$(NAME) has been created !$(WHITE)"

clean:
	@echo "$(BLUE)Cleaning...$(WHITE)"
	@rm -rf $(PATH_OBJS)
	@$(MAKE) -sC $(PATH_LIBFT) clean
	@echo "$(GREEN)Cleaned !$(WHITE)"

fclean: clean
	@echo "$(BLUE)Full Cleaning...$(WHITE)"
	@rm -f $(NAME)
	@$(MAKE) -sC $(PATH_LIBFT) fclean
	@echo "$(GREEN)Full Cleaned !$(WHITE)"

re: fclean all

.PHONY: all clean fclean re
