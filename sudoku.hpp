/*
    Program: SUDOKU
    Creators: Xuejin Gao, Jiale Qiu
*/

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <stack>

struct position {
    int row;
    int col;
    std::vector<int> possible_values;
};

class Sudoku {
    private: 
        //  Sudoku Grid
        std::vector<std::vector<int>> grid_;
        std::vector<std::vector<int>> grid_copy_; // used to check if board is solvable
        bool isSolvable = true;

        //  Private Recursion Function
        // bool SolveBoard(const std::vector<std::vector<int>>& board); 
        bool SolveBoard(const std::vector<std::vector<int>>& board, std::stack<position>& backtrack_stack);
        bool isBoardSolvable();
        bool isGridFull();
        //  Helper Functions
        std::pair<int, int> nextPositionFrom(int row, int col);
        
    public:
        //  Constructors
        Sudoku();
        Sudoku(std::vector<std::vector<int>> grid_);

        //  Methods
        void SolveBoard();
        void PrintBoard();
};

#endif