##
## Makefile for COREWAR in /media/maniarr/Workspace/etna/CoreWar/corewar
##
## Made by MARZI Nicolas
## Login   <marzi_n@etna-alternance.net>
##
## Started on  Mon Jun  5 13:26:04 2017 MARZI Nicolas
## Last update Sun Jun 11 10:40:07 2017 MARZI Nicolas
##

CC = gcc
RM = rm -f
RMDIR = rm -fr
MKDIR = mkdir
BUILD_PATH = obj
NAME = corewar
SRC = src/main.c \
	src/parser.c \
	src/memory.c \
	src/error.c \
	src/header_parser.c \
	src/manager.c \
	src/instructions.c \
	src/game.c \
	src/game_utils.c \
	src/instructions/live.c \
	src/instructions/ld.c \
	src/instructions/st.c \
	src/instructions/add.c \
	src/instructions/sub.c \
	src/instructions/and.c \
	src/instructions/or.c \
	src/instructions/xor.c \
	src/instructions/zjmp.c \
	src/instructions/ldi.c \
	src/instructions/sti.c \
	src/instructions/instructions_utils.c \
	src/op.c

OBJS = $(SRC:%.c=$(BUILD_PATH)/%.o)

INCLUDES = -I ./includes -I ../includes 
CFLAGS = -W -Wextra -Werror -Wall -pedantic $(INCLUDES)

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
