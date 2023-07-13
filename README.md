# Sudoku Solver

## Aims of the project
- Produce a program that is capable of solving any classic sudoku table that has at least one solution
- Gives the users the ability to upload the unsolved tables through .txt files

## Overview of the program
![image](https://github.com/angh-el/SudokuSolver/assets/123000792/7b655bf4-f14d-471c-ae1e-d6e6a94f77d2)


## How it works
- the user types in the name of the file that stores the unsolved table, then they have the option to either see the table, solve it or go back to the main menu
- the format of the file has to be specific
- Example:
  ![image](https://github.com/angh-el/SudokuSolver/assets/123000792/b561116d-e8f3-4811-b64d-a4c7b3c107ef)

- the program works as a backtracking algorithm that recursively calls upon itself
- there are addistional functions that help validate, inputs or display the contents in a user friendly way
- in the repository, there are also included some test case files that the can be used, however users should feel free to add their own test cases

## How to install and run the program
- the program is written in c, therefore the installation of c is required before running the program
- clone the repository ->
**_git clone https://github.com/angh-el/SudokuSolver_**
-  navigate to the repository ->
 **_cd SudokuSolver_**
- to compile the program ->
**_gcc -o outputfile SudokuSolver.c_**
- to run the program ->
**_./outputfile_**

## How to use the program
- the program takes string inputs from the user to either choose the option in the menu, or inpupt the name of the file
- initially the users only have two options: upload the file or exit
![image](https://github.com/angh-el/SudokuSolver/assets/123000792/3c0ec21e-937c-42af-a04a-80e03b05e177)
- if first option is chosen the user is asked to enter the name of the file that stores the unsolved sudoku table
![image](https://github.com/angh-el/SudokuSolver/assets/123000792/6a5578d2-030c-4904-8fed-5d09b95a3e34)
- if the file has been uploaded and read succesfully the user is then given 3 other options
![image](https://github.com/angh-el/SudokuSolver/assets/123000792/d4beacaa-fef6-4775-999f-b55adf62c75c)
- after that the program just loops itself unitl the user decides to exit
