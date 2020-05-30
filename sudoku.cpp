/*
    Program: SUDOKU
    Creators: Xuejin Gao, Jiale Qiu
*/

#include "sudoku.hpp"

bool Sudoku::SolveBoard(const std::vector<std::vector<int>>& board, std::stack<position>& backtrack_stack, int& filled_count){
    // int row = board.size();
    // int col = board[0].size();
    
    /*  1) Function to look for next empty position and push to stack. ******* need to push to stack 
        2) Stack will hold -> position and list of possible values
                a) if no more possible values, backtrack_stack.pop(), and (3)
        3) Choose a value to fill the box, and (1) 
        4) If stack.empty() => return isSolvable = false;
    */
    std::vector<int> possible_values;
    std::pair<int, int> pos;
    // position stack_item;
    if (grid_[0][0] == 0) {
        pos = std::make_pair(0,0);
        possible_values = possibleValues(0,0);
    }
    else{
        pos = nextPositionFrom(0, 0);
        possible_values = possibleValues(pos.first, pos.second);
    }
    // initialize the stack
    position stack_item(pos.first, pos.second, possible_values);
    
    backtrack_stack.push(stack_item);    

    /*              
        stack: [pos1{5,6}, pos2{2,3}, pos3{}, pos4{2,3,4}]
    */
    
    // while loop
    while(!backtrack_stack.empty() && filled_count < 81) {
        auto& item = backtrack_stack.top();
        if (item.possible_values.size() == 0) {
            grid_copy_[item.row][item.col] = 0;
            backtrack_stack.pop();
            filled_count--;
        }
        else {
            //  Sets the grid position to one of the possible values and deletes that value from the position
            int val = item.possible_values[0];
            grid_copy_[item.row][item.col] = val;
            item.possible_values.erase(item.possible_values.begin());
            
            filled_count++;

            // look for next position, and push onto stack
            std::pair<int,int> next_pos = nextPositionFrom(item.row, item.col);
            
            if(next_pos.first != -1 && next_pos.second != -1){
                std::vector<int> next_pos_values = possibleValues(next_pos.first, next_pos.second);
                position new_stack_item(next_pos.first, next_pos.second, next_pos_values);
                backtrack_stack.push(new_stack_item);
            }
            //  Check if board is correct and set the bool 
        }
        std::cout << "filled_count: " << filled_count << "in\n";
        // std::vector<int> vec = item.possible_values;
    }

    grid_ = grid_copy_;

    return 0;
}

std::pair<int,int> Sudoku::nextPositionFrom(int row, int col) {
    std::pair<int,int> nextPosition;

    for (int i = col+1; i < 9; i++) { 
        if(grid_[row][i] == 0){
            nextPosition.first = row;
            nextPosition.second = i;
            return nextPosition;
        }
    }
    
    // loop through next row until the end.
    for (int r = row+1; r < 9; r++) {
        for(int c = 0; c < 9; ++c){
            if(grid_[r][c] == 0){
                nextPosition.first = r;
                nextPosition.second = c;
                return nextPosition;
            }
        }
    }

    nextPosition.first = -1;
    nextPosition.second = -1;
    return nextPosition;
}

std::vector<int> Sudoku::possibleValues(int row, int col) {
    // unordered_set => {1,2,3,4,5,6,7,8,9}
    // row => {1,2,3,4,5,6}
    // col => {7} 
    // return --> {8,9}
    std::vector<int> arr;
    std::unordered_set<int> possible_values = {1,2,3,4,5,6,7,8,9};

    //  Row
    for(int c = 0; c < 9; ++c){
        if(col != c){
            auto itr = possible_values.find(grid_copy_[row][c]);
            if(itr != possible_values.end()){
                possible_values.erase(itr);
            }
        }
    }

    // Column
    for (int r = 0; r < 9; r++) {
        if (r != row) {
            auto itr = possible_values.find(grid_copy_[r][col]);
            if(itr != possible_values.end()) {
                possible_values.erase(itr);
            }
        }
    }

    // 3x3 boxes 
    int starting_row, starting_col;
    // 1st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    if (row < 3 && col < 3) {
        starting_row = 0;
        starting_col = 0;
    }
    // 2st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 3 && col < 6) {
        starting_row = 0;
        starting_col = 3;
    }
    // 3st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 3 && col < 9) {
        starting_row = 0;
        starting_col = 6;
    }
    // 4st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 6 && col < 3) {
        starting_row = 3;
        starting_col = 0;
    }
    // 5st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 6 && col < 6) {
        starting_row = 3;
        starting_col = 3;
    }
    // 6st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 6 && col < 9) {
        starting_row = 3;
        starting_col = 6;
    }
    // 7st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 9 && col < 3) {
        starting_row = 6;
        starting_col = 0;
    }
    // 8st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else if (row < 9 && col < 6) {
        starting_row = 6;
        starting_col = 3;
    }
    // 9st : 0 <= row && row <= 2 && 0 <= col && col <= 2
    else {
        starting_row = 6;
        starting_col = 6;
    }
    // for testing
    // std::cout << "starting row: " << starting_row << " | starting col: " << starting_col ;

    // loop through specific 3x3 box
    for (int r = starting_row; r < starting_row + 3; ++r) {
        for(int c = starting_col; c < starting_col + 3; ++c) {
            if(r != row && c != col) {
                if (possible_values.count(grid_copy_[r][c])) {
                    possible_values.erase( possible_values.find(grid_copy_[r][c]) );
                }
            }
        }
    }

    for(auto val : possible_values) {
        arr.push_back(val);
    }
    
    return arr;
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

    isSolvable = true;
}

Sudoku::Sudoku(std::vector<std::vector<int> > grid) {
    grid_ = grid;
    isSolvable = true;
}

void Sudoku::SolveBoard() {
    //  Checks if the board has correct params
    int filled_count = 0;
    if(grid_.size() == 9) {
        for(int i = 0; i < 9; ++i){
            if(grid_[i].size() != 9){
                isSolvable = false;
                break;
            }
            for(int j = 0; j < 9; ++j) {
                if (grid_[i][j] != 0) {
                    filled_count++;
                }
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
        SolveBoard(grid_copy_, backtrack_stack, filled_count);
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



