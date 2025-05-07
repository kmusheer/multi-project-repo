# Library Management System

This is a C console application for managing a library’s book inventory. It uses a **singly linked list** to store book records (each `Book` struct node points to the next). Each `Book` struct holds fields such as title, author, page count, and available copies (plus a `next` pointer). The code is modular: core functions live in `lib.c` (with declarations in `lib.h`), and `main.c` provides a text-based menu. The primary executable is named `library_app`. Data is persisted in a text file (`library_data.txt`); on startup the program loads this file into the list, and on exit it writes changes back out.

## Features

* **Add New Book:** Prompt for a book’s title, author, pages, and count, then create a new `Book` node.
* **List All Books:** Display all books currently in the system, showing their ID, title, author, pages, and available count.
* **Search Books:** Find books by title or author. This works by traversing the linked list from the head until a matching node is found.
* **Edit Book Info:** Modify the details of an existing book (e.g. update its author, page count, or available copies).
* **Count Books:** Show the total number of copies for a given title (or count all books in inventory).
* **Delete Books:** Delete a specific book.
* **Borrow Book:** Decrement the available copy count when a book is borrowed (issue). The program checks if copies remain before allowing a borrow operation.
* **Save to File:** Write the current list of books to `library_data.txt`, ensuring all changes are saved. (Triggered on exit via "Save and Exit".)
* **File Persistence:** All book records persist in `library_data.txt` between runs. On startup, `loadBooksFromFile` rebuilds the list from the file, and on exit the list is saved back automatically.

## Compilation and Execution
Before compiling, ensure you have a C compiler (e.g. GCC) and **make** installed.

### Windows
The project includes a Windows Makefile (for MinGW or similar environments). You can open a Command Prompt (or PowerShell) and run `mingw32-make` (or `make`) to build the program on same folder.

- Compile: `mingw32-make`
- Execute: `./library_app`

### Linux
- Compile: `make`
- Execute: `./library_app`

---

### Windows
The project includes a Windows Makefile (for MinGW or similar environments). You can open a Command Prompt (or PowerShell) and run `mingw32-make` (or `make`) to build the program on same folder.

- Compile: `mingw32-make`
- Execute: `./library_app`

### Linux
- Compile: `make`
- Execute: `./library_app`

---

```bash
make
```

## Menu Options

The program presents a numbered menu; the user enters a choice to perform an action:

1. **Add Book** - Enter book details to append a new book to the list.
2. **List All Books** - Print a list of all books with their details and IDs.
3. **Search Books** - Enter a title or author to search; the list is traversed until a match is found.
4. **Edit Book Info** - Choose a book and update its information.
5. **Count Books** - Input a book title to display how many copies are available.
6. **Borrow Book** - Select a book to borrow; this reduces its available copy count by one (if available).
7. **Save and Exit** - Save all changes to `library_data.txt` and quit the program.

## File Handling and Persistence

The application uses standard C file I/O to persist data. On startup, it opens `library_data.txt` and reads saved book records into the linked list (via `loadBooksFromFile`). During the session, operations modify the in-memory list. When exiting through "Save and Exit", the program opens `library_data.txt` (creating it if needed) and writes all book records. This ensures that any added, edited, or deleted books are stored on disk. If `library_data.txt` is missing at launch, the program starts with an empty library and creates the file on save.

## Folder Structure

```plaintext
libraryMangment/
├── lib.h                   # Shared header with struct definitions and function prototypes
├── lib.c                   # Core library functions (add, edit, search, borrow, etc.)
├── main.c                  # Main program and menu interface
├── addBook.c
├── countBook.c
├── deleteBook.c
├── editBook.c
├── findBook.c
├── listBook.c
├── saveBook.c
├── synchBook.c
├── takeBook.c
├── Makefile                # Windows Makefile (for MinGW/Visual Studio Make)
└── README.md               # This documentation
└── library_data.txt        # Persistent data file containing book records
```

## Example Usage

```bash
$ ./library_app
--- Library Management Menu ---
a. Add Book
l. List Books
f. Search Books
e. Edit Book Info
c. Count Books
d. Delete Books
t. Borrow Book
s. Save and Exit
q. Quit from app
Enter choice: a

Enter title: The Hobbit
Enter author: J.R.R. Tolkien
Enter pages: 310
Enter count: 3
Book added successfully!

Enter choice: l

List of books:
ID: 1, Title: The Hobbit, Author: J.R.R. Tolkien, Pages: 310, Available: 3

Enter choice: q
Saving data and exiting...
```

## Linux Makefile

The Linux Makefile (`Makefile.Linux`) is similar but uses Linux commands. It compiles with `gcc` and names the executable `library_app`. It also defines a `clean` target that uses `rm` to remove object files and the executable:

```makefile
clean:
	rm -f *.o library_app
```

## Cleanup

Run the following command to remove compiled files:

### Windows

```bash
mingw32-make clean
```

### Linux

```bash
make clean
```

---

Happy coding! Feel free to fork this project, report issues, or suggest improvements. Enjoy using the Library Management System!
