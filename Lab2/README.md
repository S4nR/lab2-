# Laboratory #1: Building OOP Solutions
**October Edition**

## Task: Student Management System for Technical University of Moldova (TUM)

### Overview
This project involves designing an Object-Oriented solution to model a Student Management System for the Technical University of Moldova. The system is intended to efficiently manage faculties and students while providing various operations to enhance usability and functionality.

### General Restrictions
- **No third-party libraries** are allowed; only libraries available by default can be used.
- You can create as many classes as necessary for a well-structured system.
- Advanced OOP concepts such as **Polymorphism**, **Inheritance**, and **Abstraction** may be used but are not mandatory.

## Required Operations

### Faculty Operations
- **Create and assign a student to a faculty.**
- **Graduate a student from a faculty.**
- **Display currently enrolled students** (excluding graduates).
- **Display graduates** (excluding current students).
- **Check if a student belongs to a specific faculty.**

### General Operations
- **Create a new faculty.**
- **Search for the faculty of a student** by a unique identifier (e.g., email or student ID).
- **Display all university faculties.**
- **Display all faculties within a specific field** (e.g., Food Technology).

## Improved Laboratory Features (9th Grade Level)
### Persistence
The program saves its state between sessions. Students and faculties created in previous sessions are preserved. A `SaveManager` (or `FileManager`) class is designed to handle saving and loading data.

## Working System Features (10th Grade Level)
### Logging System
A logging system tracks all operations performed in the system, including student creation, graduation, and faculty creation.

## Additional Operations
- **Batch enrollment of students** from a text file.
- **Batch graduation of students** from a text file.
- **Input validation** with meaningful error messages (e.g., “Cannot graduate student: (student not found)”).

## Extra Points or Penalties
- Maintain a **clean project structure**.
- Follow the **coding conventions** of the chosen programming language.
- Demonstrate the use of **SOLID**, **DRY**, and **KISS** principles.

## Additional Exercises

1. **Operator Overloading**
   - Implement unary operator overloading for increment (`++`) and decrement (`--`) for the `Student` class.
   - Implement binary operator overloading for the `+` operator to add credits between two students.

2. **Single and Multiple Inheritance**
   - Create a `Person` class and derive a `Student` class.
   - Design an `Employee` class and create a `StudentEmployee` class inheriting from both.

3. **Pure Virtual Functions and Abstract Classes**
   - Create an abstract base class `Person` with a pure virtual function `getRole()`, and derive `Student`, `Teacher`, and `Administrator` classes.

4. **Polymorphism**
   - Create a function that accepts a pointer to a `Person` object and prints the role of the person, demonstrating polymorphism.

5. **Relationships between Classes: Aggregation and Composition**
   - Implement a `Faculty` class that contains a list of `Students`.
   - Implement a `Library` class where a `Book` is an essential part of the library.

6. **Polymorphic Logging System**
   - Extend the logging system using polymorphism by creating a base class `OperationLogger` with derived classes like `FileLogger` and `ConsoleLogger`.

7. **Advanced Error Handling with Custom Exceptions**
   - Create custom exception classes for handling specific errors, ensuring the system throws and catches these exceptions appropriately.

## Conclusion
This project is designed to provide a comprehensive understanding of Object-Oriented Programming principles while creating a practical application for managing students and faculties at TUM. The system incorporates various functionalities to ensure effective management and tracking of student information and operations.

# Student Management System with Logger

---

## Project Description

This project is a **Student Management System** designed to handle operations related to university students and faculties. The system is developed in **C++**, and it supports logging functionalities that track operations such as enrolling students, adding faculties, handling graduation processes, and logging errors. The project utilizes **polymorphism** and advanced object-oriented programming concepts such as **operator overloading**, **virtual destructors**, and **static members**.

---

## Main Features

1. **Student and Faculty Management**:
    - Add, display, and manage student information.
    - Enroll students and add faculties to the system.
    - Process student graduation and handle cases where errors occur (e.g., student not found).
2. **Logger System**:
    - Log actions (e.g., student enrollment, faculty addition, graduation) either to a file or to the console.
    - Utilize polymorphism to implement different loggers (`File_logger` and `Console_logger`).
3. **Error Logging**:
    - Log specific error messages such as "student not found" or "student could not graduate."
    - Support batch operations for logging multiple activities at once.

---

## Project Structure

- **`main.cpp`**: The main file that drives the user interaction, showing the menu and handling input for the various operations such as adding students, logging, or choosing loggers.
- **`log_system.hpp` / `log_system.cpp`**: Contains the core implementation of the `Logging_system` class. This class is responsible for performing operations and choosing the correct logger (either file or console).
- **`logger.hpp` / `logger.cpp`**: Defines the `Operation_logger` base class and its derived classes `File_logger` and `Console_logger`. Each logger class implements the `log()` function in its own way. The base class uses a virtual destructor to ensure proper cleanup when using pointers.
- **`faculty.hpp`**: Contains definitions for the `Faculty` class, which manages faculty-related data.
- **`students.hpp`**: Contains definitions for the `Students` class, which handles all operations and data related to students.

---

## Key Concepts and Implementation Details

### 1. Logging System (Polymorphism)

The project uses **polymorphism** for the logging system. The `Operation_logger` class serves as an abstract base class, with a pure virtual method `log()`. The derived classes `File_logger` and `Console_logger` override this method to either write the log to a file or print it to the console.

**Choosing a Logger**: The `Logging_system` class uses the `choose_logger()` method to let the user decide whether to log to a file or the console at runtime. This method returns an instance of either `File_logger` or `Console_logger`.

```cpp
Operation_logger* logger = choose_logger();
logger->log(logging_file, message);
