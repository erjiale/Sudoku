/*
    Program: SUDOKU
    Creators: Xuejin Gao, Jiale Qiu
*/

//  Import files
#include <iostream>

#include <vector>

// #include "sudoku.hpp"

// void testCases();

int main(int args, char *argv[] ) {
    // if(strcmp( argv[0], ./p1) == 0 && argc != 4){
    //     printf(Usage: %s gray-image threshold-level binary-image\n, argv[0]);
    //     return 0;
    // }

    // std::vector<std::vector<int>> sudoku_input = {
    //     {},
    //     {},
    //     {},
    //     {},
    //     {},
    //     {},
    //     {},
    //     {},
    //     {}
    // };
    std::vector<int> empty {0, 1 ,2 , 3 ,4 ,5 ,6};
    empty.push_back(1);
    empty.push_back(2);
    std::cout << empty[0] << " " << empty[1] << "\n";

    // std::vector<std::vector<int> > sudoku_input  = {    {5,3,0,0,7,0,0,0,0},
    //                     {6,0,0,1,9,5,0,0,0},
    //                     {0,9,8,0,0,0,0,6,0},
    //                     {8,0,0,0,6,0,0,0,3},
    //                     {4,0,0,8,0,3,0,0,1},
    //                     {7,0,0,0,2,0,0,0,6},
    //                     {0,6,0,0,0,0,2,8,0},
    //                     {0,0,0,4,1,9,0,0,5},
    //                     {0,0,0,0,8,0,0,7,9}
    // };

    // for(int i = 0; i < 9; ++i){
    //     for(int j = 0; j < 9; ++j){
    //         std::cout << sudoku_input[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    // for (int i = 0; i < 9; i++) {
    //     sudoku_input.push_back(empty);
    // }

    // sudoku_input[0].push_back(5);
    // sudoku_input[0].push_back(3);
    // sudoku_input[0].push_back(0);
    // sudoku_input[0].push_back(0);
    // sudoku_input[0].push_back(7);
    // sudoku_input[0].push_back(0);
    // sudoku_input[0].push_back(0);
    // sudoku_input[0].push_back(0);
    // sudoku_input[0].push_back(0);
    // sudoku_input[1].push_back(5);
    // sudoku_input[1].push_back(3);
    // sudoku_input[1].push_back(0);
    // sudoku_input[1].push_back(0);
    // sudoku_input[1].push_back(7);
    // sudoku_input[1].push_back(0);
    // sudoku_input[1].push_back(0);
    // sudoku_input[1].push_back(0);
    // sudoku_input[1].push_back(0);
    
    

    // Sudoku grid(sudoku_input);
    // grid.SolveBoard();
    // std::vector<int> myv = grid0possibleValues(3,3);
    // testCases();
    // Function/class/object that lets user fill out the Sudoku
    // grid.PrintBoard();
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

