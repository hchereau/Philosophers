NAME := Philo

### SRCS ######################################################################

PATH_SRCS := srcs/


vpath %.c $(PATH_SRCS)

### INCLUDES ##################################################################

PATH_INCLUDES := includes/

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c,$(PATH_OBJS)%.o,$(SRCS))

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

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(NAME) has been created !$(WHITE)"'

$(OBJS):$(PATH_OBJS)%.o: %.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -I $(PATH_INCLUDES) -o $@ -c $<

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
