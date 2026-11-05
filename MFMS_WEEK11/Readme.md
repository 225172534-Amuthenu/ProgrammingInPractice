# Municipal Financial Management System

## Project Description
A modular C application for managing municipal
employees, budgets and reports.

## Modules

- main.c: Controls the main menu.
- employees.c: Manages employee information and salaries.
- budget.c: Calculates municipal revenue and expenses.
- utilities.c: Provides reusable input functions.
- reports.c: Generates combined employee and budget reports.

## Header Files

- employees.h
- budget.h
- utilities.h
- reports.h

## Compilation

gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c

## Linking

gcc main.o employees.o budget.o utilities.o reports.o -o mfms.exe

## Running

.\mfms.exe