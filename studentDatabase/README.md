# Student Database Management System

A comprehensive application to manage student records with functionalities to add, edit, delete, search, display, save, and reverse records. The database is persistent, ensuring data is retained between sessions using file handling.

## Features
- **Dynamic Memory Allocation:** Efficiently manage student records in memory.
- **File Handling:** Persistent storage in `student_DB.txt`.
- **Error Handling:** Prevents duplicate Student IDs and validates user inputs.
- **Modular Design:** Each functionality is implemented in separate files for maintainability.

---

## Compilation and Execution

### Windows
- Compile: `mingw32-make`
- Execute: `./student_DB`

### Linux
- Compile: `make`
- Execute: `./student_DB`

---

## Menu Options

### 1. Add a New Student Record (`a/A`)
- Add student details:
  - **Student ID** (e.g., `V24HE2A1`)
  - **Name**
  - **Date of Birth (DOB)**
  - **Percentage** (Matriculation, Inter/Diploma, Graduation)
  - **Contact Number**
  - **Email ID**
- *Note:* Duplicate Student IDs are not allowed.

### 2. Print Records (`p/P`)
- Display all student records in the database.

### 3. Save the Database (`s/S`)
- Save all current records to `student_DB.txt`.

### 4. Delete a Record (`d/D`)
- Delete a specific record using the Student ID.

### 5. Edit a Record (`e/E`)
- Modify details of an existing record:
  - Edit Name
  - Edit Date of Birth
  - Edit Percentage
  - Edit Contact Number
  - Edit Email ID
  - Display Updated Data

### 6. Find a Student (`f/F`)
- Search for a student by ID, Name, or other attributes.

### 7. Reverse Records (`r/R`)
- Reverse the order of displayed records without altering the database file.

### 8. Quit (`q/Q`)
- Exit the application. All data is automatically saved to the file.

---

## File Handling
- **File Used:** `student_DB.txt`
  - Data is loaded into memory at startup.
  - Changes are saved back to the file on exit or using the save option.

---

## Folder Structure
```plaintext
v24he2M14/
├── edit/
│   ├── edit.c               // Functions to edit student records.
│   ├── myEditLib.c          // Additional utility functions for editing.
│   ├── edit.h               // Header file for editing functions.
├── input/
│   ├── input.c              // Functions for handling user input.
│   ├── input.h              // Header file for input functions.
├── delete/
│   ├── delete.c             // Functions to delete student records.
│   ├── delete.h             // Header file for delete functions.
├── file_operations/
│   ├── save.c               // Functions to save the database to a file.
│   ├── syncFile.c           // Functions to load existing data.
│   ├── file.h               // Header file for file operations.
├── find/
│   ├── find.c               // Functions to search student records.
│   ├── find.h               // Header file for search functions.
├── print/
│   ├── print.c              // Functions to display student records.
│   ├── print.h              // Header file for print functions.
├── mylib/
│   ├── myLib.c              // Utility functions (e.g., validation).
│   ├── myLib.h              // Centralized header for utilities.
├── reverse/
│   ├── reverse.c            // Functions to reverse records.
│   ├── reverse.h            // Header file for reverse functions.
├── main.c                   // Main program handling menu and function calls.
├── main.h                   // Header file for main program.
├── readme.txt               // Documentation for compilation and usage.
├── student_DB.txt           // Persistent storage for student records.
└── Makefile                 // Build automation using `make`.
```

---

## Example Usage

### Adding a New Student Record
```plaintext
Enter your choice: a

Enter Student ID: V24HE2A1
Enter Name: Akash
Enter DOB (dd/mm/yyyy): 12/05/2001
Enter Marks (Matriculation, Inter, Graduation): 85.5 87.0 78.5
Enter your contact number: 9876543210
Enter Email ID: akash@example.com

Record added successfully.
```

---

## Notes for Linux Users

Update the `Makefile` for Linux systems as follows:
```make
student_DB: main.o edit.o input.o delete.o file_operations.o find.o reverse.o print.o mylib.o
	gcc -o student_DB main.o edit.o input.o delete.o file_operations.o find.o reverse.o print.o mylib.o

main.o: main.c
	gcc -c main.c

edit.o: edit/edit.c
	gcc -c edit/edit.c

input.o: input/input.c
	gcc -c input/input.c

delete.o: delete/delete.c
	gcc -c delete/delete.c

file_operations.o: file_operations/save.c file_operations/syncFile.c
	gcc -c file_operations/save.c file_operations/syncFile.c

find.o: find/find.c
	gcc -c find/find.c

reverse.o: reverse/reverse.c
	gcc -c reverse/reverse.c

print.o: print/print.c
	gcc -c print/print.c

mylib.o: mylib/myLib.c
	gcc -c mylib/myLib.c

clean:
	rm -f *.o student_DB
```

To compile:
```bash
make
```

---

## Cleanup
To remove compiled files and reset the environment:
```bash
mingw32-make clean   # For Windows
make clean           # For Linux
```

---

## Enjoy using the Student Database Management System!

