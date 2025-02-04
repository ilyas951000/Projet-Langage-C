CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET = bot
SRC = main.c commands.c
OBJ = $(SRC:.c=.o)
PYTHON = python3

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c commands.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(PYTHON) bot.py

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all