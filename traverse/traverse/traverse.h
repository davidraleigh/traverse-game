/*
 *  traverse.h
 *  traverse
 *
 *  Created by David Raleigh on 11/25/15.
 *  Copyright (c) 2015 David Raleigh. All rights reserved.
 *
 */

#ifndef traverse_
#define traverse_

/* The classes below are exported */
#pragma GCC visibility push(default)
#include <vector>


class Traverse
{
public:
    enum PositionType
    {
        Rock  = 16,
        Barrier = 8,
        Lava  = 4,
        Water = 2,
        Teleport = 1,
        Open = 0
    };
    
    struct move_t {
        public int x;
        public int y;
    };
    
    Traverse(int boardSize);
    
    PositionType GetPosition(int x, int y);
    
    //Write a function that accepts a sequence of moves and reports
    //whether the sequence contains only valid knight moves.
    bool MoveSequenceTest(std::vector<move_t> moves);
    
    //It should also
    //optionally print the state of the knight board to the terminal as shown
    //above after each move.  The current position should be marked with a 'K'.
    
    
private:
    int m_boardDimensions;
    std::vector<std::vector<PositionType>> m_boardState;
    

    
//    Compute a valid sequence of moves from a given start point to a given
//    end point.

//    Compute a valid sequence of moves from a given start point to a
//    given end point in the fewest number of moves.
    
//    Now repeat the Level 3 task for this 32x32 board.  Also, modify
//        your validator from Level 1 to check your solutions.  This board has the
//        following additional rules

//    1) W[ater] squares count as two moves when a piece lands there
//    2) R[ock] squares cannot be used
//    3) B[arrier] squares cannot be used AND cannot lie in the path
//    4) T[eleport] squares instantly move you from one T to the other in
//    the same move
//    5) L[ava] squares count as five moves when a piece lands there
    
};

#pragma GCC visibility pop
#endif
