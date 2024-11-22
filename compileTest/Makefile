# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files and output
SRCS = menuMain.c printFunc.c stats.c
OBJS = $(SRCS:.c=.o)
TARGET = program

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
