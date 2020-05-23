/*
    Program: SUDOKU
    Creators: Xuejin Gao, Jiale Qiu
*/

#include "sudoku.hpp"

bool Sudoku::SolveBoard(const std::vector<std::vector<int>>& board, std::stack<position>& backtrack_stack){
    // int row = board.size();
    // int col = board[0].size();
    
    
    

    return 0;
}


bool Sudoku::isBoardSolvable(){
    return isSolvable;
}

//  Can improve efficiency w/ hash map
bool Sudoku::isGridFull(){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(grid_[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

// Initializes _grid with all 0's
Sudoku::Sudoku() {
    std::vector<int> initial_vec_;

    for (int i = 0; i < 9; i++) {
        grid_.push_back(initial_vec_);        
        for (int j = 0; j < 9; j++) {
            grid_[i].push_back(0);
        }
    }
}

Sudoku::Sudoku(std::vector<std::vector<int>> grid) {
    grid_ = grid;
}

void Sudoku::SolveBoard() {
    //  Checks if the board has correct params
    if(grid_.size() == 9) {
        for(int i = 0; i < 9; ++i){
            if(grid_[i].size() != 9){
                isSolvable = false;
                break;
            }
        }
    } 
    else {
        isSolvable = false;
    }


    // [0,0] -> [1,2] => [0,0] -> [2]
    // [1,2] -> [1,2] 
    if(isSolvable){
        grid_copy_ = grid_;
        std::stack <position> backtrack_stack;
        SolveBoard(grid_copy_, backtrack_stack);
    }
    else{
        std::cout << "Sudoku Board parameters are invalid." << std::endl;
    }
}

void Sudoku::PrintBoard() {
    for(int i = 0; i < 9; ++i){

        for(int j = 0; j < 9; ++j){
            std::cout << grid_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



