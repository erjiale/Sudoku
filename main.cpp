/*
    Program: SUDOKU
    Creators: Xuejin Gao, Jiale Qiu
*/

//  Import files
#include <fstream>
#include <sstream>
#include "sudoku.hpp"

// void testCases();

int main(int args, char *argv[] ) {
    // if(strcmp( argv[0], ./p1) == 0 && argc != 4){
    //     printf(Usage: %s gray-image threshold-level binary-image\n, argv[0]);
    //     return 0;
    // }
    std::ifstream file;
    std::string row;
    int row_col, row_counter = 0;
    file.open("sudokuInput.txt");

    std::vector<std::vector<int>> sudoku_input;
    std::vector<int> empty_vector;
    for (int i = 0; i < 9; i++) {
        sudoku_input.push_back(empty_vector);
    }

    if(file) {
        while(getline(file, row)) {
            std::istringstream ss(row);
            for (int col = 0; col < row.length(); col++) {
                if (row[col] != ' ') {
                    ss >> row_col;
                    sudoku_input[row_counter].push_back(row_col);
                    // std::cout << row_col << " ";
                }
            }
            row_counter++;
            // std::cout << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Error opening the file\n";
    }
    
    // std::vector<std::vector<int> > sudoku_input  = {    
    //                         {5,3,0,0,7,0,0,0,0},
    //                         {6,0,0,1,9,5,0,0,0},
    //                         {0,9,8,0,0,0,0,6,0},
    //                         {8,0,0,0,6,0,0,0,3},
    //                         {4,0,0,8,0,3,0,0,1},
    //                         {7,0,0,0,2,0,0,0,6},
    //                         {0,6,0,0,0,0,2,8,0},
    //                         {0,0,0,4,1,9,0,0,5},
    //                         {0,0,0,0,8,0,0,7,9}
    //     };

    Sudoku grid(sudoku_input);
    grid.SolveBoard();
    grid.PrintBoard();
    return 0;
}

// void testCases(){
//     std::vector<std::pair<int, int> > input_values = {   {1, 1}, 
//                                                         {3, 3}, 
//                                                         {2, 6}, 
//                                                         {8, 3}, 
//                                                         {0, 5}  
//     }; 
//     std::vector<std::pair<int,int> > expected_output = {{0,0},{3,3},{0,6},{6,3},{0,3}};
//     Sudoku test_grid;
//     std::vector<int> output_values;
//     for (int i = 0; i < input_values.size(); i++) {
//         std::cout << "Input value: " << input_values[i].first << " " << input_values[i].second << std::endl;
//         output_values = test_grid.possibleValues(input_values[i].first, input_values[i].second); // cout << the starting row and col
//         std::cout <<  "| Expected starting row : " << expected_output[i].first <<  "Expected starting col: " << expected_output[i].second;
//         std::cout << std::endl << std::endl;
//     }
// }

