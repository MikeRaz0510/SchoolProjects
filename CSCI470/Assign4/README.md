[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/qL9nzY_3)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=14216685)
### Assignment: Maze Solver Using Recursive Backtracking

#### Introduction

In this assignment, you will implement a recursive backtracking algorithm, to solve a maze. The maze is represented as a 2D grid of characters, where different symbols represent walls, paths, the start point, and the end point. Your task will involve understanding the given code, preparing maze inputs, finding a path from the starting point to the end point if one exists.

The maze will be stored in a text file, and you will prompt the user for the filename.


#### Background

The maze is characterized by a 2d array of characters, as follows. notation is as follows
- `X` => wall
- `+` => starting point
- `-` =>  end point
- `*` =>  path taken by the solver
- `.` => dead ends marked during backtracking

The solver uses a recursive method to navigate through the maze, marking its path, and backtracks if it hits a dead end until it finds the end point or concludes there is no solution.

#### Tasks


1. **Prepare Your Maze**: Create at least three different maze files to test  the solver. Your mazes should vary in complexity and size. Make sure to include at least:
   - One solvable maze with a direct path.
   - One solvable maze with multiple paths.
   - One unsolvable maze.

Example maze format:

```
XXXXXXXXXXXX
+   XXX    -
XXX XXX XXXX
XXX  XX XXXX
XX         X
XXXXXXXXXXXX
```

2. **Solve the Maze**:   A solution to the above maze would look like:
```
XXXXXXXXXXXX
****XXX****-
XXX*XXX*XXXX
XXX**XX*XXXX
XX..****...X
XXXXXXXXXXXX

This maze was solvable!
```


This is the expected output as well.

3. **Analysis and Reporting**: For each maze, provide the following:
   - The original maze layout.
   - The output from the solver, including the final state of the maze.
 

### Algorithm Overview ###
In general, the algorithm should work like the following:
- Represent maze as a 2D array
- Make sure the row and column you are going to check is in bounds
- if the cell your checking is an endpoint, great you are done
- if its a wall or dead end or something you've already visited you will have to back up
- otherwise, try each of the four directions (Left right up down) until it works

# Grading Details #
## Header ##
  - Comment header must be present and must precisely match the followinng text.  
    - No changes, deletions or extra spaces.  Name, And student Id must be present.
     ```
     ////////////////////////////////////////////////////////
     // 
     //   Your Name 
     //   Your NIU ID
     //   Your Course and Section Number 
     //   
     //  I certify that this is my own work and where appropriate an extension 
     //   of the starter code provided for the assignment. 
     ////////////////////////////////////////////////////////
     ```
     - If this header is not present there will be a 20 Point deduction.
   ## Correctness of assignment: 50 Points ##  
   - Does it do what its supposed to?   Does it meet the requirements of the assignment?
  ## Coding Conventions 20 Points ##
    - Variables are named meaningfully 
    - Code is consistently formatted using an evident style
    - Comments are used where appropriate    
   ## Input and output 30 points ##
   - Program displays input as shown and output as shown.  Accurately formatted text is required.
  
  # If your program does not  run, your grade will automatically be a zero
 
Total: 100 points
