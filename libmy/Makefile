##
## Makefile for COREWAR in /media/maniarr/Workspace/etna/CoreWar/libmy
##
## Made by MARZI Nicolas
## Login   <marzi_n@etna-alternance.net>
##
## Started on  Mon Jun  5 13:21:20 2017 MARZI Nicolas
## Last update Mon Jun  5 13:31:40 2017 MARZI Nicolas
##

CC = gcc
RM = rm -f
RMDIR = rm -fr
MKDIR = mkdir
BUILD_PATH = obj
NAME = libmy.a
SRC = src/my_getnbr.c \
		src/my_is_alphanum.c \
		src/my_isneg.c \
		src/my_nb_len.c \
		src/my_pow.c \
		src/my_putchar.c \
		src/my_put_nbr.c \
		src/my_putstr.c \
		src/my_strcat.c \
		src/my_strcmp.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_strncat.c \
		src/my_strncmp.c \
		src/my_strncpy.c \
		src/my_strstr.c \
		src/my_str_to_wordtab.c \
		src/my_swap.c \
		src/my_wordlen.c \
		src/put_hex.c \
		src/my_putnbr_base.c \
		src/my_strspn.c \
		src/my_bstrlen.c \
		src/my_strnncpy.c \
		src/safe_malloc.c

OBJS = $(SRC:%.c=$(BUILD_PATH)/%.o)
CFLAGS = -W -Wextra -Werror -Wall -pedantic -I ./includes -I ../includes
AR = ar
ARFLAGS = rcs

.PHONY	: dirs

all		: $(NAME)

$(NAME) : dirs $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

dirs	:
	$(MKDIR) -p $(dir $(OBJS))

$(BUILD_PATH)/%.o :	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJS)
	$(RMDIR) $(dir $(OBJS))

fclean	: clean
	$(RM) $(NAME)

re: fclean all