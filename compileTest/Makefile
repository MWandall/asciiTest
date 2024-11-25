# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files and output
SRCS = menuMain.c printFunc.c stats.c fileHandling.c arrays.c
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



# *BASH with mingw32
# mingw32-make
# ./program

# *Clean Up (Optional): remove all the compiled .o files and the program executable
# mingw32-make clean


# gcc arrays.c fileHandling.c menuMain.c printFunc.c stats.c -Wall