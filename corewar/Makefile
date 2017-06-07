##
## Makefile for COREWAR in /media/maniarr/Workspace/etna/CoreWar/corewar
##
## Made by MARZI Nicolas
## Login   <marzi_n@etna-alternance.net>
##
## Started on  Mon Jun  5 13:26:04 2017 MARZI Nicolas
## Last update Mon Jun  5 13:27:36 2017 MARZI Nicolas
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
	src/error.c

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
