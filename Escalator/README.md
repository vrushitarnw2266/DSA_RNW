# Escalator Stack-Based Project

A C++ implementation of an escalator system using stack data structure to manage people boarding and exiting.

## Project Overview

This project demonstrates the implementation of a **Stack** data structure and its practical application in an **Escalator System**. The project focuses on:

- **Stack Implementation**: Generic template-based stack using linked list
- **Encapsulation**: Private members and public interfaces
- **Object-Oriented Design**: Person struct and Escalator class
- **Polymorphism & Abstraction**: Virtual functions and abstract operations

## Files

- **Stack.h**: Generic Stack template class (linked list implementation)
- **Escalator.h**: Escalator class with Person struct
- **main.cpp**: Test driver program demonstrating all functionality
- **CMakeLists.txt**: Build configuration

## Features

### Stack Class
- `push(value)`: Add element to top of stack
- `pop()`: Remove and return top element
- `peek()`: View top element without removing
- `isEmpty()`: Check if stack is empty
- `getSize()`: Get number of elements
- `display()`: Print stack contents

### Escalator Class
- `boardPerson()`: Add person to escalator
- `exitPerson()`: Remove person from escalator
- `moveEscalator()`: Simulate escalator movement
- `checkOccupancy()`: Display current occupancy
- `setDirection()`: Change escalator direction (UP/DOWN)
- `emergencyStop()`: Evacuate all people

## Building

### Using CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .
./escalator
```

### Using g++ directly
```bash
g++ -std=c++17 -o escalator main.cpp
./escalator
```

## Compilation

**Compiler Requirements:**
- C++17 or later
- GCC, Clang, or MSVC

**On Windows (with g++):**
```bash
g++ -std=c++17 main.cpp -o escalator.exe
escalator.exe
```

## Example Output

```
========== ESCALATOR SYSTEM SIMULATION ==========

Escalator initialized (Capacity: 5, Direction: UP)

--- Test 1: Boarding People ---
Person(ID: 1, Name: Alice, Floor: 5) boarded the escalator.
...
--- Test 2: Check Occupancy ---
Escalator Occupancy: 5/5
Stack (top to bottom): Person(ID: 5, Name: Eve, Floor: 9) ...
```

## Key Concepts

1. **LIFO Principle**: Last-In-First-Out ordering with stack
2. **Capacity Management**: Escalator has max capacity constraint
3. **Floor Tracking**: Tracks current floor and movement direction
4. **Exception Handling**: Proper error handling for edge cases

## Marking Criteria Coverage

✅ Class & Object: Person and Escalator classes
✅ Polymorphism: Operator overloading (<<)
✅ Encapsulation: Private members with public methods
✅ Abstraction: Hide implementation details

## Author

Escalator Stack Project - DSA Implementation
