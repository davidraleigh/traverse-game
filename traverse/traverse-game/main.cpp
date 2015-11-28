//
//  main.cpp
//  traverse-game
//
//  Created by David Raleigh on 11/25/15.
//  Copyright (c) 2015 David Raleigh. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <memory>
#include <regex>

#include "Traverse.h"
#define BOARD_1 R"(........B...LLL................. ........B...LLL................. ........B...LLL...LLL........... ........B...LLL..LLL...RR....... ........B...LLLLLLLL...RR....... ........B...LLLLLL.............. ........B............RR......... ........BB...........RR......... ........WBB..................... ...RR...WWBBBBBBBBBB............ ...RR...WW.........B............ ........WW.........B......T..... ...WWWWWWW.........B............ ...WWWWWWW.........B..RR........ ...WW..........BBBBB..RR.WWWWWWW ...WW..........B.........W...... WWWW...........B...WWWWWWW...... ...WWWWWWW.....B............BBBB ...WWWWWWW.....BBB..........B... ...WWWWWWW.......BWWWWWWBBBBB... ...WWWWWWW.......BWWWWWWB....... ...........BBB..........BB...... .....RR....B.............B...... .....RR....B.............B.T.... ...........B.....RR......B...... ...........B.....RR............. ...........B..........RR........ ...........B..........RR........................................................................................................................................)"

std::shared_ptr<Traverse> inputBoard() {
    // get the size
    std::shared_ptr<Traverse> board = nullptr;
    while (!board) {
        std::cout << "\nA Board must be 3x3 or larger\n";
        std::cout << "\nA Board connot be larger than 40x40\n";
        std::cout << "The string you input must have as many characters as a perfect square (row count = column count)\n";
        std::cout << "The character inputs are '.', 'o' or 'O' for empty positions\n";
        std::cout << "The character inputs are 'l' or 'L' for lava positions\n";
        std::cout << "The character inputs are 'b' or 'B' for barrier positions\n";
        std::cout << "The character inputs are 'r' or 'R' for rock positions\n";
        std::cout << "The character inputs are 'w' or 'W' for water positions\n";
        std::cout << "The character inputs are 't' or 'T' for teleport positions. Only two teleport positions per map.\n";
        std::cout << "An acceptable input would be '.b... .b.b. ..L.. ..b.. .....' (5 rows 5 columns)\n\n";
        std::cout << "Enter your board below and press enter when finished:\n";
        try {
            char input[1600];
            std::cin.getline(input, sizeof(input));
            board = std::make_shared<Traverse>(input);
        } catch (std::regex_error& e) {
            std::cout << "regex error on parse: " << e.what();
        } catch (std::invalid_argument& e) {
            std::cout << e.what();
        }
    }
    return board;
}

std::shared_ptr<Traverse> premadeBoard() {
    std::shared_ptr<Traverse> board = std::make_shared<Traverse>(BOARD_1);
    return board;
}

std::shared_ptr<Traverse> empytBoard() {
    // get the size
    int size = 0;
    while (size < 3) {
        std::cout << "\nA Board must be 3x3 or larger\n";
        std::cout << "Select the size of your board:\n";
        std::cin >> size;
    }
    std::shared_ptr<Traverse> board = std::make_shared<Traverse>(size);
    return board;
}

std::shared_ptr<Traverse> selectionLoop() {
    
    while (true) {
        std::cout << "1. [I]nput board\n";
        std::cout << "2. [P]re-made board\n";
        std::cout << "3. [E]mpty board\n\n";
        std::cout << "E[X]it\n";
        
        std::string input;
        std::cin >> input;
        std::cin.ignore();
        char selection = input[0];
        std::shared_ptr<Traverse> board = nullptr;
        switch (tolower(selection)) {
            case 'i':
                return inputBoard();
            case 'p':
                return premadeBoard();
            case 'e':
                return empytBoard();
            case 'x':
                return nullptr;
            default:
                std::cout << "Incorrect selection. Only keys 'i', 'I', 'p', 'P', 'e', 'E', 'x', and 'X' are accepted inputs.\n\n";
                break;
        }
    }

    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while (true) {
        std::cout << "Enter a Selection With the Keyboard:\n\n";
        
        auto board = selectionLoop();
        if (!board)
            return 0;
        
        board->PrintBoard();
        
        std::cout << "\nSelect a start position row:";
        int rowStart;
        std::cin >> rowStart;
        std::cin.ignore();
        std::cout << "\nSelect a start position column:";
        int colStart;
        std::cin >> colStart;
        Traverse::position_t fromPos(rowStart, colStart);
        
        std::cout << "\nSelect an end position row:";
        int rowEnd;
        std::cin >> rowEnd;
        std::cin.ignore();
        std::cout << "\nSelect an end position column:";
        int colEnd;
        std::cin >> colEnd;
        Traverse::position_t toPos(rowEnd, colEnd);
        std::vector<Traverse::position_t> path = board->CreatePath(fromPos, toPos);
        if (path.size() == 0){
            std::cout << "\n\nBoard has no solution:\n\tYou cannot being on a teleport\n\tYou cannot end on teleport\n\tYou cannot cross a barrier\n";
            continue;
        }
        
        std::cout << "\n\nCompleted board:\n\n";
        board->PrintBoard();
    }
}
