##
## Makefile for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm
##
## Made by MARZI Nicolas
## Login   <marzi_n@etna-alternance.net>
##
## Started on  Mon Jun  5 13:26:04 2017 MARZI Nicolas
## Last update Sun Jun 11 13:41:50 2017 MARZI Nicolas
##

CC = gcc
RM = rm -f
RMDIR = rm -fr
MKDIR = mkdir
BUILD_PATH = obj
NAME = asm
SRC = src/op.c \
	src/main.c \
	src/file/xopen.c \
	src/file/file_exists.c \
	src/parser.c \
	src/label.c \
	src/instruction.c \
	src/debug.c \
	src/assemble.c \
	src/header.c \
	src/free.c \
	src/byte.c \
	src/param.c \
	src/utils.c \
	src/str_utils.c \
	src/command.c

OBJS = $(SRC:%.c=$(BUILD_PATH)/%.o)
TEST_OBJS = $(TEST:%.c=$(BUILD_PATH)/%.o)

INCLUDES = -I ./includes -I ../includes
CFLAGS = -W -Wextra -Werror -Wall -pedantic $(INCLUDES) -g

LIBMY_PATH = ../libmy/libmy.a

.PHONY	: dirs

all		: $(NAME)

$(NAME) : dirs $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMY_PATH) -o $(NAME)  

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