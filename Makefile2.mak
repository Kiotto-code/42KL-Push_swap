
NAME	= push_swap
CHECKER	= checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g
RM		= rm -rf
LIBFT	= libft

INCLUDES	= ./includes
SRC_PATH	= ./src
OBJ_PATH	= ./obj


PUSHSWAP_SRCS	= $(wildcard $(SRC_PATH)/$(NAME)/*.c)
CHECKER_SRCS	= $(wildcard $(SRC_PATH)/$(CHECKER)/*.c)

PUSHSWAP_OBJS	= ${PUSHSWAP_SRCS:.c=.o}
CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

all:	$(OBJ_PATH) $(NAME) bonus

bonus:	$(CHECKER)

$(NAME):	$(PUSHSWAP_OBJS)
			$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $? -L$(LIBFT) -lft -o $@


$(CHECKER):		$(CHECKER_OBJS)
				$(MAKE) -C $(LIBFT)
				$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@


$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			$(MAKE) -C $(LIBFT) $@
			rm -rf $(OBJ_PATH)

fclean:		clean
			$(MAKE) -C $(LIBFT) $@
			rm -f $(NAME) $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus