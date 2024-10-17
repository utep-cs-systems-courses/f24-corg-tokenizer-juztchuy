# List of object files
OBJS = uimain.o history.o 

# Compiler flags for debugging and optimization
CFLAGS = -g -O3

# First target to build by default
all: tokenizer

# tokenizer depends on uimain.o and history.o (generated from uimain.c and history.c)
tokenizer: $(OBJS)
	$(CC) -o tokenizer $(CFLAGS) $(OBJS)

# Build object files for .c files
uimain.o: uimain.c tokenizer.h history.h
	$(CC) $(CFLAGS) -c uimain.c

history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

# Clean rule to remove generated object files and the final executable
clean:
	rm -f *.o tokenizer

# Run the program after building it
run: tokenizer
	./tokenizer
