# CC = gcc
# CFLAGS = -Wall -Wextra -g

# # Directories
# SRCDIR = .
# EDITDIR = edit
# INPUTDIR = input
# DELETEDIR = delete
# FILEDIR = file_operations
# FINDDIR = find
# PRINTDIR = print
# MYLIBDIR = mylib
# REVERSEDIR = reverse

# # Source files
# SOURCES = $(SRCDIR)/main.c $(EDITDIR)/edit.c $(INPUTDIR)/input.c $(DELETEDIR)/delete.c \
#           $(FILEDIR)/save.c $(FILEDIR)/syncFile.c $(FINDDIR)/find.c \
#           $(PRINTDIR)/print.c $(MYLIBDIR)/myLib.c $(EDITDIR)/myEditLib.c $(REVERSEDIR)/reverse.c

# # Object files
# OBJECTS = $(SOURCES:.c=.o)

# # Output
# TARGET = student_DB

# all: $(TARGET)

# $(TARGET): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJECTS) $(TARGET)






CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRCDIR = .
EDITDIR = edit
INPUTDIR = input
DELETEDIR = delete
FILEDIR = file_operations
FINDDIR = find
PRINTDIR = print
MYLIBDIR = mylib
REVERSEDIR = reverse

# Source files
SOURCES = $(SRCDIR)/main.c $(EDITDIR)/edit.c $(INPUTDIR)/input.c $(DELETEDIR)/delete.c \
          $(FILEDIR)/save.c $(FILEDIR)/syncFile.c $(FINDDIR)/find.c \
          $(PRINTDIR)/print.c $(MYLIBDIR)/myLib.c $(EDITDIR)/myEditLib.c $(REVERSEDIR)/reverse.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Output
TARGET = student_DB

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -n "$(OBJECTS)" ]; then rm -f $(OBJECTS); fi
	@if [ -e "/student_DB" ]; then rm -f /student_DB; fi






















# ## Compilation and Build Instructions

# To compile and build the project, you will need to have **GCC** installed. You can use the MinGW toolchain on Windows or any other GCC-compatible compiler.

# ### 1. Install GCC (if not already installed)

# - **Windows**: Install MinGW from [MinGW](https://osdn.net/projects/mingw/releases/) or use [MSYS2](https://www.msys2.org/).
# - **Linux/macOS**: Install GCC via the terminal using the package manager:
#   - Ubuntu/Debian: `sudo apt install gcc`
#   - macOS: `brew install gcc`

# ### 2. Navigate to the Project Directory

# Open a terminal/command prompt and navigate to the directory where the project is located.

# ### 3. Create the Makefile

# In the root of the project, create a `Makefile` with the following content:

# ```Makefile
# CC = gcc
# CFLAGS = -Wall -Wextra -g

# # Directories
# SRCDIR = .
# EDITDIR = edit
# INPUTDIR = input
# DELETEDIR = delete
# FILEDIR = file_operations
# FINDDIR = find
# PRINTDIR = print
# MYLIBDIR = mylib
# REVERSEDIR = reverse

# # Source files
# SOURCES = $(SRCDIR)/main.c $(EDITDIR)/edit.c $(INPUTDIR)/input.c $(DELETEDIR)/delete.c \
#           $(FILEDIR)/save.c $(FILEDIR)/syncFile.c $(FINDDIR)/find.c \
#           $(PRINTDIR)/print.c $(MYLIBDIR)/myLib.c $(EDITDIR)/myEditLib.c $(REVERSEDIR)/reverse.c

# # Object files
# OBJECTS = $(SOURCES:.c=.o)

# # Output executable
# TARGET = student_DB

# # Default target to build the project
# all: $(TARGET)

# # Linking object files to create the executable
# $(TARGET): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# # Rule to compile C files into object files
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean up compiled files
# clean:
# 	rm -f $(OBJECTS) $(TARGET)

# # Rebuild the project from scratch
# rebuild: clean all
