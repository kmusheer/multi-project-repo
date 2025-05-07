# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Output executable
TARGET = library_app

# Object files
OBJS = main.o lib.o addBook.o countBook.o deleteBook.o editBook.o findBook.o listBook.o saveBook.o takeBook.o synchBook.o

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile main.c
main.o: main.c lib.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile lib.c
lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c

# Rule to compile addBook.c
addBook.o: addBook.c lib.h
	$(CC) $(CFLAGS) -c addBook.c

# Rule to compile countBook.c
countBook.o: countBook.c lib.h
	$(CC) $(CFLAGS) -c countBook.c

# Rule to compile deleteBook.c
deleteBook.o: deleteBook.c lib.h
	$(CC) $(CFLAGS) -c deleteBook.c

# Rule to compile editBook.c
editBook.o: editBook.c lib.h
	$(CC) $(CFLAGS) -c editBook.c

# Rule to compile findBook.c
findBook.o: findBook.c lib.h
	$(CC) $(CFLAGS) -c findBook.c

# Rule to compile listBook.c
listBook.o: listBook.c lib.h
	$(CC) $(CFLAGS) -c listBook.c

# Rule to compile saveBook.c
saveBook.o: saveBook.c lib.h
	$(CC) $(CFLAGS) -c saveBook.c

# Rule to compile takeBook.c
takeBook.o: takeBook.c lib.h
	$(CC) $(CFLAGS) -c takeBook.c

# Rule to compile synchBook.c
synchBook.o: synchBook.c lib.h
	$(CC) $(CFLAGS) -c synchBook.c

# Clean up generated files (Windows-compatible with shell)
clean:
	@if exist main.o del main.o
	@if exist lib.o del lib.o
	@if exist $(TARGET) del $(TARGET)
