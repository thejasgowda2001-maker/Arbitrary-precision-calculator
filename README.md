# Arbitrary Precision Calculator

An Arbitrary Precision Calculator implemented in C using doubly linked lists. The project performs arithmetic operations on large integers beyond the limits of standard C data types.

## Features

- Addition of large integers
- Subtraction of large integers
- Multiplication of large integers
- Division of large integers
- Handles positive and negative results
- Command-line based expression input
- Supports numbers beyond standard integer limits

## Concepts Used

- C Programming
- Data Structures
- Doubly Linked Lists
- Dynamic Memory Allocation
- Pointers
- Command-Line Arguments
- Modular Programming

## Project Files

- main.c - Main program and command-line argument handling
- addition.c - Performs addition
- subtraction.c - Performs subtraction
- multiplication.c - Performs multiplication
- division.c - Performs division
- apc.c - Common APC operations and linked-list handling
- apc.h - Structure definitions and function declarations

## Compilation

bash
gcc *.c -o apc

## Execution

bash
./apc <operand1><operator><operand2>

### Examples

bash
./apc 12345+67890
./apc 12345-67890
./apc 12345*67890
./apc 12345/67890

## Learning Outcome

This project demonstrates the implementation of arithmetic operations without relying on the size limits of built-in integer data types. Large numbers are represented and processed using dynamically allocated doubly linked lists.
