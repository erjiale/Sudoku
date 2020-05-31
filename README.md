# Sudoku-Solver

#### Authors
- (Jay) Jiale Qiu
- Xuejin Gao

#### Purpose
Attempting to create a program that:
<p>1) Generates a sudoku</p>
<p>2) Lets user fill out the sudoku</p>

#### How to Run
1. Open 'sudokuInput.txt' and the unfinished sudoku. The missing numbers must be labeled **0** 
    ie. 2 . . . . . . . . -> 2 0 0 0 0 0 0 0 0 
    `if there are none, you can use some from 'examples.txt'`
2. ```make clean```
3. ```make all```
4. ```./main```

### How we built
- We used a backtracking algorithm that will check all the possibilities 
- if there are no more possibilities, then there is no solution for the given sudoku
- else the result would be printed out in the terminal. 