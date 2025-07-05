NAME := Philo

### SRCS ######################################################################

PATH_SRCS := srcs/

SRCS += main.c
SRCS += init_data.c
SRCS += create_philosophers.c
SRCS += ft_atoi.c
SRCS += cleanup.c
SRCS += is_simulation_running.c
SRCS += philosophers_state.c
SRCS += print_status.c

vpath %.c $(PATH_SRCS)

### INCLUDES ##################################################################

PATH_INCLUDES := includes/

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c,$(PATH_OBJS)%.o,$(SRCS))

### COMPILATION ################################################################

CC := clang

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
# CFLAGS += -fsanitize=thread
CFLAGS += -g3

### COLORS ####################################################################

WHITE := \033[0m
GREEN := \033[0;32m
BLUE := \033[0;34m

### RULES #####################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(PATH_INCLUDES)
	@echo "$(GREEN)$(NAME) has been created !$(WHITE)"

$(OBJS):$(PATH_OBJS)%.o: %.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES)

clean:
	@echo "$(BLUE)Cleaning...$(WHITE)"
	@rm -rf $(PATH_OBJS)
	@echo "$(GREEN)Cleaned !$(WHITE)"

fclean: clean
	@echo "$(BLUE)Full Cleaning...$(WHITE)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full Cleaned !$(WHITE)"

re: fclean all

.PHONY: all clean fclean re
